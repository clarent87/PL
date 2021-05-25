#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
using namespace std::literals;

void foo() 
{
    auto tid = std::this_thread::get_id(); // 스레드 ID 얻기

    auto handle = GetCurrentThread(); // [*] 아직까지 현재 수행되고 있는 thread의 OS레벨 handle을 얻는 방법은 없어서. system call을 이용했다. 
                                    // [*] cpp 표준에서 this_thread에  getnativehandle을 넣어야 하지 않느냐 고민중이라고 함. 
    std::this_thread::sleep_for(1s);    
    std::cout << GetThreadPriority( handle) << std::endl;
}

int main()
{
    // [*] 기본적으로 cpp thread의 우선순위를 변경할수 있는 방법은 없다. 
    // [*] 따라서 OS레벨의 thread handle을 얻어와서 작업해줘야함 
    std::thread t( &foo );
    std::thread::native_handle_type h = t.native_handle(); // OS레벨의 thread 핸들 얻기. windows랑 리눅스일때 반환 type이 다르다.. 
                                                            // native_handle_type은 type_def로 되어있고 윈도우일땐 handle, 리눅스는 pthread_handle 

    std::cout << "ID     : " << t.get_id() << std::endl;
    std::cout << "handle : " << h          << std::endl;

    std::this_thread::sleep_for(100ms);   
    SetThreadPriority((HANDLE)h, THREAD_PRIORITY_TIME_CRITICAL); // 쓰레드의 우선순위를 각 os의 system call을 이용해서 변경 ( 옆 api는 윈도우용)
                                                                // [*] (HANDLE)h 을 쓴이유는 g++빌드시 h의 타입이 pthread_handle이라 
                                                                // [*] SetThreadPriority에서 오류남, 단순히 casting만 해주면 잘 동작한다함
    t.join();
}

