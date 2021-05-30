#include <iostream>
#include <thread>
#include <atomic>

//long x = 0;
std::atomic<long> x{0}; // 원하는 타입을 템플릿 인자로 주고, 요즘은 중괄호 초기화도 많이 쓰니까 중괄호 초기화 진행함

void foo()
{
    for ( int i = 0; i < 100000; ++i)
    {
        // atomic op flag
        ++x; // x.operator++() 이 호출됨
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
