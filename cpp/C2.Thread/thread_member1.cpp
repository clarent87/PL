#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo() 
{
    std::cout << std::this_thread::get_id() << std::endl; // this_thread에도 get_id있음
}
int main()
{
    int n =  std::thread::hardware_concurrency();
    std::cout << n << std::endl; // 8

    std::thread t( &foo );
    std::this_thread::sleep_for(1s);

    std::thread::id tid = t.get_id(); // thread에도 get_id있음
    std::cout << "created thread id : " << tid << std::endl;
    t.join();
}

