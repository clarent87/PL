#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void goo()
{
    std::lock_guard<std::mutex> lg(m); // [*] 생성자에서 lock 진행

//    m.lock();    
    std::cout << "using shared data" << std::endl;

//    throw std::exception(); // [*] 예외 발생시 아래 unlock는 실행이 안됨
//    m.unlock();
} // [*] lock_guard의 소멸자가 호출되는 위치, 여기서 unlock 수행 ( 지역변수 객체라서 여기서 파괴되는듯. )

// [*] 위에서 lock_guard를 일찍 unlock 해주려면 block으로 해당 코드를 감싸면 된다. 
// [*] { std::lock_guard<std::mutex> lg(m); ... } 이렇게..

void foo()
{
    try 
    {  
        goo(); 
    }
    catch(...)
    {
        std::cout << "catch exception" << std::endl;
    }
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	t1.join();
	t2.join();
}

//

