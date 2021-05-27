#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::timed_mutex m;
int share_data = 0;

void foo()
{
    //m.lock();
    //if ( m.try_lock() )
    if ( m.try_lock_for(2s) ) //[*] 2초까지 대기 해주고, 그 안에 mutex획득 못하면 false 리턴
    {
        share_data = 100;
        std::cout << "using share_data" << std::endl;
        std::this_thread::sleep_for(3s);
        m.unlock();
    }
    else
    {
        std::cout << "뮤텍스 획득 실패" << std::endl;
    }
}
int main()
{
	std::thread t1(foo);
    std::thread t2(foo);
	t1.join();
	t2.join();
}



