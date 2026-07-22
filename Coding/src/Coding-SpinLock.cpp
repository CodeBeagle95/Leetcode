#include <iostream>
#include <atomic>
#include <thread>

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int n)
{
    for (int cnt = 0; cnt < 10; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
             ; // spin
        std::cout << "Output from thread: " << n << " Cnt: " << cnt << std::endl;
        lock.clear(std::memory_order_release);  // release lock
    }
}

int main()
{
    std::thread t1(f, 1);
    std::thread t2(f, 2);
    std::thread t3(f, 3);
    std::thread t4(f, 4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}