#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for( int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}
int main()
{
    std::thread t(&foo); // 객체 생성이 바로 thread start. 파라메터로 함수포인터 넘김 (함수타입에 &붙었으니까..)
    

 //   t.join(); // 주 쓰레드가 t가 종료될때까지 대기
    t.detach(); // 주 쓰레드는 t 를 기다리지 않고 진행 
                // 여기서는 아래 cin이 없을때 detach를 사용하면 runtime에 에러가 나는데, 
                // 이유는 주쓰레드가 죽으면서 프로세스가 종료되기 때문에 t가 강제종료되서 그럼
                // [*] 따라서 detach를 쓰는경우 주 쓰레드는 종료되지 않는다는 가정이 존재한다는 의미 ( 아래에서 cin으로 주쓰레드 종료를 막았다. )
                // [*] 또는 쓰레드간 동기화 필요
    std::cout << "end" << std::endl;

    int n;
    std::cin >> n; // 이건 주쓰레드의 종료를 맊기 위해 씀
}

