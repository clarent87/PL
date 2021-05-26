#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void divide(std::promise<int> &&p, int a, int b)
{
    try
    {
        if (b == 0)
            throw std::runtime_error("divide by zero");

        p.set_value(a / b); // a/b를 복잡한 연산이라 가정하고 쓰레드를 돌린거
                            // [*] cpp표준에서는 사실 0으로 나눈다고 예외가 나오진 않음..
                            // [*] 따라서 b가 0일때 위 if문으로 예외를 강제 발생 시키는 코드 넣음
    }
    catch (...)
    {
        //p.set_exception( std::current_exception() ); // [*] 현재 발생한 예외를 promise에 세팅 (즉, 주 쓰레드에 예외 알려주려고.)
        p.set_exception_at_thread_exit(std::current_exception()); // [*] 이건 예외를 쓰레드 종료시 전달하라는것, 
                                                                //   [*]promise1.cpp의 set_value_at_thread_exit와 의미가 비슷
    }
}

int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();

    std::thread t(divide, std::move(pm), 10, 0);

    try
    {
        int ret = ft.get();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    t.join();
}
