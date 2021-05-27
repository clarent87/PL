#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

std::mutex m; // [*] 뮤텍스는 전역적으로 만들어서 씀.

void delay() { std::this_thread::sleep_for(20ms);}

void foo(std::string_view name )
{
    //int x = 0; // [*] 이건 thread마다 스택이 따로 잡히니까 스레드에 안전함
    static int x = 0; // [*] static 지역변수는 스레드에 안전하지 않음,, 따라서 mutex사용

    for ( int i = 0; i < 10; i++)
    {
        m.lock();
        x = 100; delay();
        x = x+1; delay();
        std::cout << name << " : " << x << std::endl; delay();
        m.unlock();
    }
}

int main()
{
	std::thread t1(foo, "A");
	std::thread t2(foo, "\tB");
	t1.join();
	t2.join();
}



