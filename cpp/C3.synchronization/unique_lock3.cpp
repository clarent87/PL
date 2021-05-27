#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::timed_mutex m;

int main()
{   
    std::unique_lock<std::timed_mutex> u1;
    std::unique_lock<std::timed_mutex> u2(m);

    //u1 = u2; // error [*] 복사 생성자 지원안됨
    u1 = std::move(u2); // ok [*] move생성자는 가능, u2는 더이상 뮤텍스를 가지고 있지 않고, u1이 가지게 된다.

    std::cout << u1.owns_lock() << std::endl; // 1 출력됨

    if ( u1 ) // [*] operator bool 연산자가 재정의 되어 있어서 이렇게 쓸수 있음 (이거 notion SAFE bool에 나옴)
        std::cout << "acquire" << std::endl;
    
    u1.unlock(); // [*] lock_guard였다면 명시적 unlock은 불가.. 왜냐면 멤버함수로 제공이 안됨

    std::cout << u1.owns_lock() << std::endl;  // 0  

    if ( u1.try_lock_for(2s) )
    {
        //....
        u1.unlock();
    }

    u1.release(); // [*] unlock하는 api는 아님, 내부적으로 가지고 있는 mutex를 끈는 용도.(음, 아마 뮤텍스 변수를 초기화하는거일듯)
}



