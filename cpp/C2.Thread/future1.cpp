#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{	
	std::this_thread::sleep_for(1s);
	p.set_value(a+b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

    std::thread t(add, std::move(pm), 10, 20);

//    int n1 = ft.get();
    

    std::future_status ret = ft.wait_for(2s); // 2초간 대기
                                            // [*] 만약 2초대기 중에 결과값이 도착하면 바로 빠져나감.

    if ( ret == std::future_status::ready ) // 결과값이 준비됨
        std::cout << "ready !" << std::endl;

    else if ( ret == std::future_status::timeout ) // [*] 2초 대기 했는데, 아직 쓰레드가 안끝난 경우.. 
        std::cout << "timeout !" << std::endl;

    else // std::future_status::deferred // 연산할 함수가 아직 시작 안됨. 나중에 async() 함수 에서 사용
        std::cout << "deferred !" << std::endl;

	t.join();
}



