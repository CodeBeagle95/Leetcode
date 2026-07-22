#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <atomic>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data;
std::atomic<bool> isFinish{false};

void MessageProducer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "[Sending]: " << i << std::endl;
        data.push(i);
        lock.unlock(); // 这里要提前释放锁再 notify_one，否则消费者获取不到锁会继续阻塞等待
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    isFinish.store(true, std::memory_order_release); // 内存序控制写约束
    cv.notify_one();
}

void MessageConsumer() {
    do {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !data.empty() || isFinish; });

        while (!data.empty()) {
            std::cout << "[Receive]: " << data.front() << std::endl;
            data.pop();
        }
    } while (!isFinish.load(std::memory_order_acquire)); // 内存序控制读约束
}

int main(int argc, char* argv[]) {
    std::thread producer(MessageProducer);
    std::thread consumer(MessageConsumer);

    producer.join();
    consumer.join();

    return 0;
}

/*
1. 为什么要用 unique_lock 而不是 lock_guard？
答：因为 std::condition_variable::wait() 内部需要能够手动释放和重新获取锁，
而 lock_guard 不支持手动释放，只有 unique_lock 支持。

2. 什么是虚假唤醒（Spurious Wakeup）？
答：操作系统在某些情况下（如信号处理）可能会在没有收到 notify 的情况下唤醒等待的线程。
因此 wait 被唤醒后必须重新检查条件，这就是为什么必须传入第二个参数（lambda 谓词）的原因。

3. 为什么在 notify 之前先 unlock？
答：如果在持有锁的情况下调用 notify_one，被唤醒的线程会立刻尝试获取这把锁，但发现锁被占用，又会进入睡眠状态，
导致一次无意义的上下文切换。先释放锁再唤醒，能让被唤醒的线程直接拿到锁，提升并发性能。
*/