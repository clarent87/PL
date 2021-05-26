#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;    
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
    // [*] async는 아래 4가지 방식으로 쓸수 있따. 
    std::future<int> ft = std::async( std::launch::async,    add, 10, 20); // [*] 비동기 실행, 즉 쓰레드 만든다는것
//    std::future<int> ft = std::async( std::launch::deferred, add, 10, 20); // 지연된 실행
                                                                        // [*] 즉 add함수의 결과가 필요할떄 실행해 달라는것, 즉 ft.get()할때..add가 실행됨
                                                                        // [*] 이때 중요한 사실은, main과 동일 thread에서 add가 호출된다는것
//    std::future<int> ft = std::async( std::launch::async | std::launch::deferred , add, 10, 20);
                // [*] 위 처럼 두가지 옵션을 or 해서 넘기면, 컴파일러 구현에 따라 동작이 다름
                // [*] 즉, 컴파일러가 임베디드 환경 컴파일러냐, 모바일 환경이나, pc환경이냐에 따라 쓰레드를 만들수도 있고, 지연된실행을 할수도 있음
                // [*] pc에서는 위 코드를 실행하면, 쓰레드가 생성되서 실행됨 (즉 비동기 실행, deferred는 무시되는듯.)

//    std::future<int> ft = std::async( add, 10, 20); // [*] 사실 이건 std::launch::async | std::launch::deferred 를 쓴거와 같다. 
                                                    //   [*] 즉, 환경에 따라 쓰레드를 생성하거나, 혹은 지연된 실행을 선택적으로 한다. 
                                                    //   [*] 근데, 대부분의 경우 쓰레드를 만든다고 함
    std::cout << "continue main : " << std::this_thread::get_id() << std::endl;    
    std::this_thread::sleep_for(2s);
    int ret = ft.get();

    std::cout << "result : " << ret << std::endl;
}

 

