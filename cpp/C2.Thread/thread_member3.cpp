#include <iostream>
#include <thread>

int main()
{
    std::thread t; 

    if ( t.joinable() ) // [*] 안전한 join을 위해서 옆처럼 한다.
    {
        t.join();
    }
}


/*
int main()
{
    std::thread t; // [*] 생성자 인자로 아무것도 안넘겨서, 쓰레드가 생성되지 않았다.
    try 
    {
        t.join(); // [*] 이때 바로 조인하면 에러남
    }
    catch(std::exception& e)
    {
        std::cout << "예외 : " << e.what() << std::endl;
    }
}
*/