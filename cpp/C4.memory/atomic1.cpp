#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

std::mutex m;
long x = 0; // 모든 스레드가 공유.

void foo()
{
    for ( int i = 0; i < 100000; ++i)
    {
//        m.lock();
//        ++x;
//        m.unlock();

//        __asm
//        {
//            lock inc x // [*] 그냥 inc x는 스레드에 안전하지 않다. 
                        //  [*] 중요) 이거 vc 어셈이고 g++은 안된다네.. => OS opcode인데 컴파일러에 따라 뭔가 지원이 안되나봄
//        }
        InterlockedIncrement(&x); // [*] 위 asm을 매번 쓸수는 없으니, 운영체제에서 c레벨의 함수를 제공함  ( 옆 c 함수는 windows에서 제공하는 함수)
                                //   [*] 옆api는 x를 스레드 안전하게 증가 해주는 api, g++로도 실행가능 (windows에서 돌리는 거면)
                                //   [*] 근데 linux에선 당연히 돌릴수 없고, 따라서 cpp 표준으로 공통화해서 제공하는 것이 atomic class라고함
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
    std::cout << x << std::endl; // [*] 원하는 결과는 30만인데, 이결과가 안나옴. 왜냐면 ++x는 instruction 3개 짜리즉, 원자연산이 아님
                                //  [*] 해결책1.
                                //      - 운영체제가 제공하는 동기화 사용 (ex: std::mutex)
                                //      - 단점. OS의 동기화 도구는 무겁다( overhead가 있다는것.=> 성능이슈 언급인듯)
                                //  [*] 해결책2
                                //      - CPU가 제공하는 스레드(멀티 코어 환경)에 안전한 OPCODE 사용
                                //      - intel cpu의 경우 opcode에 lock이라는 prefix를 사용
                                //      - 이런 연산이 atomic operation이다. !
}
