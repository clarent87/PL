#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

int main()
{
    std::chrono::time_point tp1 = std::chrono::system_clock::now(); // 현재 시간 얻기

    // epoch 기준시간 기점으로 몇시간이 지났는지 파악하는 코드 ( 분,초로 받을수도 있음)
    // 이때 캐스팅 필요 => duration_cast
    std::chrono::hours h = std::chrono::duration_cast< std::chrono::hours >( tp1.time_since_epoch());
   
    std::cout << h.count() << std::endl;

    std::this_thread::sleep_for( 3ms);
    std::this_thread::sleep_until( std::chrono::system_clock::now() + 200ms);

}

// time_point에 대한 내용 강의



