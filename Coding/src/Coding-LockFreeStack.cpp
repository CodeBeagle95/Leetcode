#include <atomic>
#include <cstddef>
#include <new>
#include <utility>
#include <memory>

namespace boost {
namespace lockfree {

template<typename T, typename Alloc = std::allocator<T>>
class stack {
private:
    struct node {
        T data;
        node* next;
        
        node() : next(nullptr) {}
        explicit node(T const& value) : data(value), next(nullptr) {}
        explicit node(T&& value) : data(std::move(value)), next(nullptr) {}
    };

    using node_allocator_type = typename std::allocator_traits<Alloc>::template rebind_alloc<node>;
    using node_deleter = std::default_delete<node>;

    node* head_;
    node_allocator_type allocator_;

public:
    explicit stack(node_allocator_type const& alloc = node_allocator_type())
        : head_(nullptr), allocator_(alloc) {}

    ~stack() {
        while (pop_internal()) {}
    }

    // 禁用拷贝构造和拷贝赋值（lockfree容器通常不支持拷贝）
    stack(stack const&) = delete;
    stack& operator=(stack const&) = delete;

    // 允许移动构造和移动赋值
    stack(stack&& other) noexcept 
        : head_(other.head_), allocator_(std::move(other.allocator_)) {
        other.head_ = nullptr;
    }

    stack& operator=(stack&& other) noexcept {
        if (this != &other) {
            // 清理当前栈
            while (pop_internal()) {}
            
            head_ = other.head_;
            allocator_ = std::move(other.allocator_);
            other.head_ = nullptr;
        }
        return *this;
    }

    bool empty() const noexcept {
        return head_ == nullptr;
    }

    bool push(T const& value) {
        node* new_node = allocate_node(value);
        if (!new_node) return false;
        
        node* old_head = head_.load(std::memory_order_relaxed);
        new_node->next = old_head;
        
        while (!head_.compare_exchange_weak(old_head, new_node,
                                            std::memory_order_release,
                                            std::memory_order_relaxed)) {
            new_node->next = old_head;
        }
        
        return true;
    }

    bool push(T&& value) {
        node* new_node = allocate_node(std::move(value));
        if (!new_node) return false;
        
        node* old_head = head_.load(std::memory_order_relaxed);
        new_node->next = old_head;
        
        while (!head_.compare_exchange_weak(old_head, new_node,
                                            std::memory_order_release,
                                            std::memory_order_relaxed)) {
            new_node->next = old_head;
        }
        
        return true;
    }

    bool pop(T& result) {
        node* old_head = head_.load(std::memory_order_acquire);
        while (old_head != nullptr) {
            if (head_.compare_exchange_weak(old_head, old_head->next,
                                            std::memory_order_acquire,
                                            std::memory_order_relaxed)) {
                result = std::move(old_head->data);
                deallocate_node(old_head);
                return true;
            }
        }
        return false;
    }

    bool try_pop(T& result) {
        return pop(result);
    }

private:
    node* allocate_node(T const& value) {
        node* new_node = nullptr;
        try {
            new_node = std::allocator_traits<node_allocator_type>::allocate(allocator_, 1);
            new (new_node) node(value);
        } catch (...) {
            return nullptr;
        }
        return new_node;
    }

    node* allocate_node(T&& value) {
        node* new_node = nullptr;
        try {
            new_node = std::allocator_traits<node_allocator_type>::allocate(allocator_, 1);
            new (new_node) node(std::move(value));
        } catch (...) {
            return nullptr;
        }
        return new_node;
    }

    void deallocate_node(node* p) {
        if (p) {
            p->~node();
            std::allocator_traits<node_allocator_type>::deallocate(allocator_, p, 1);
        }
    }

    node* pop_internal() {
        node* old_head = head_.load(std::memory_order_acquire);
        while (old_head != nullptr) {
            if (head_.compare_exchange_weak(old_head, old_head->next,
                                            std::memory_order_acquire,
                                            std::memory_order_relaxed)) {
                node* result = old_head;
                result->~node();
                std::allocator_traits<node_allocator_type>::deallocate(allocator_, result, 1);
                return result;
            }
        }
        return nullptr;
    }
};

} // namespace lockfree
} // namespace boost
