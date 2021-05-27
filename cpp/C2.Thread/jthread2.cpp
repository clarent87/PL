#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

void foo()
{
    for( int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;
    }
}
void goo( std::stop_token token ) 
{     
    for( int i = 0; i < 10; i++)
    {
        if ( token.stop_requested() )
        {
            std::cout << "중지요청" << std::endl;
            // [*] 자원할당 같은게 있었다면 여기서 해제 하면된다.
            return ;
        }

        std::this_thread::sleep_for(500ms);
        std::cout << "goo : " << i << std::endl;
    }
}
int main() 
{
    std::jthread j1(foo);
    std::jthread j2(goo); // [*] goo의 param이 stop_token이 있지만, 안넘겨도 jthread가 알아서 넘겨줌
    std::this_thread::sleep_for(2s);

    j1.request_stop(); // [*] j1은 foo를 쓰레드로 돌리는것인데, 이건 중지가 안됨 (stop_token이 없어서.)
    j2.request_stop(); // [*] std::thread에는 없는 함수 jthread에서 생김, thread에 중지 요청을 하는 기능
                        //[*] 이거만 쓴다고 해당 쓰레드가 중지하는 것은 아님, std::stop_token이 있는 함수여야 stop기능이 가능
}
// 위 기능은 닷넷에서 많이 영감을 받은 거라고 함