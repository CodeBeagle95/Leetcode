/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// LRU缓存，多线程加锁会有并发问题，需要hash分段加锁
class LRUCache;

class LRUItem {
private:
    int key_;
    int val_;
    LRUItem* prev_;
    LRUItem* next_;

public:
    LRUItem() : key_(0), val_(0), prev_(nullptr), next_(nullptr) {}
    LRUItem(int key, int val) : key_(key), val_(val), prev_(nullptr), next_(nullptr) {}

    friend class LRUCache; // 声明友元类
};

class LRUCache { // 哈希表+双链表
private:
    const int maxCapacity_;
    LRUItem* idleHead_;
    LRUItem* idleTail_;
    unordered_map<int, LRUItem*> itemMap_;

    void DetachNode(LRUItem* item);
    void AttachHead(LRUItem* item);
    void MoveToHead(LRUItem* item);
    void RemoveTail();

public:
    LRUCache(int capacity) : maxCapacity_(capacity) {
        idleHead_ = new LRUItem();
        idleTail_ = new LRUItem();
        idleHead_->next_ = idleTail_;
        idleTail_->prev_ = idleHead_;
    }

    ~LRUCache() { // 补充析构函数，防止内存泄漏
        LRUItem* item = idleHead_->next_;
        while (item != idleTail_) {
            item = item->next_;
            delete item->prev_;
        }
        delete idleHead_;
        delete idleTail_;
    }

    LRUCache(const LRUCache&) = delete;            // 删除拷贝构造
    LRUCache& operator=(const LRUCache&) = delete; // 删除拷贝赋值
    LRUCache(LRUCache&&) = delete;                 // 删除移动构造
    LRUCache& operator=(LRUCache&&) = delete;      // 删除移动赋值
    
    int get(int key) {
        auto found = itemMap_.find(key);
        if (found == itemMap_.end()) {
            return -1;
        }
        MoveToHead(found->second);
        return found->second->val_;
    }
    
    void put(int key, int value) {
        auto found = itemMap_.find(key);
        if (found != itemMap_.end()) {
            auto item = found->second;
            item->val_ = value;
            MoveToHead(item);
            return;
        }
        
        auto item = new LRUItem(key, value);
        itemMap_[key] = item;
        AttachHead(item);
        if (itemMap_.size() > maxCapacity_) {
            RemoveTail();
        }
    }
};

void LRUCache::DetachNode(LRUItem* item) {
    item->prev_->next_ = item->next_;
    item->next_->prev_ = item->prev_;
}

void LRUCache::AttachHead(LRUItem* item) {
    item->next_ = idleHead_->next_;
    item->next_->prev_ = item;
    idleHead_->next_ = item;
    item->prev_ = idleHead_;
}

void LRUCache::MoveToHead(LRUItem* item) {
    DetachNode(item);
    AttachHead(item);
}

void LRUCache::RemoveTail() {
    auto item = idleTail_->prev_;
    if (item == idleHead_) return; // 边界检查：说明链表为空
    
    itemMap_.erase(item->key_);
    DetachNode(item);
    delete item; // 释放内存，避免内存泄漏
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */