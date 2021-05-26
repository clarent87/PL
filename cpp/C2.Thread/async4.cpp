#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

void foo(std::promise<int>&& p)
{
    std::cout << "start foo" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "finish foo" << std::endl;
    p.set_value(10);
}
int main()
{
    std::promise<int> p;    
    std::future<int> ft = p.get_future();
    
    std::thread t(foo, std::move(p));
    t.detach();
//    ft.get();
} // [*] ft의 소멸자 get 기능은, async에서 반환되었을때만 존재, 즉 이 예제는 foo가 종료되기 전에 프로그램이 끝남

 

