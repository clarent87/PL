#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x{0};

void foo()
{
    for ( int i = 0; i < 100000; ++i)
    {
        //++x; // x.operator++()    
        //x.fetch_add(1); // [*] atomic operation, 1증가시키는 함수
        x.fetch_add(1, std::memory_order_relaxed); // [*] 메모리 오더 세팅을 변경해서 성능 향상을 가져옴
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}

