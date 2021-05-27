#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::mutex m;
int share_data = 0; // [*] 공유 data. mutex를 사용해서 보호

void foo()
{
    //m.lock();
    if ( m.try_lock() ) //[*] 뮤텍스 획득 실패하면 false가 return됨
    {
        share_data = 100;
        std::cout << "using share_data" << std::endl;
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
    std::this_thread::sleep_for(20ms);
    std::thread t2(foo);
	t1.join();
	t2.join();

    // mutex 의 운영체제 레벨의 native handle을 얻는 코드 ( 당연히 type은 운영체제에 따라다름)
    // [*] 앞선 강좌의 thread의 native handle과 같은 개념이네
    std::mutex::native_handle_type h = m.native_handle();

//    std::mutex m2 = m; // error [*] 복사 안됨.
}



