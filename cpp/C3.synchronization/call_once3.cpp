#include <iostream>
#include <thread>
#include <mutex>
using namespace std::literals;

class Singleton
{
private:
    Singleton() 
    {
        std::cout << "start ctor" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "finish ctor" << std::endl;
    }
public:
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

    static Singleton& getInstance() 
    {        
        std::cout << "start getInstance" << std::endl;
        static Singleton instance;      // [*] 여기서 생성자가 호출되는데, 생성자 코드 종료전에 다른 쓰레드가 들어오면? 
                                        // [*] 매우매우 신기한데,, 다른 쓰레드는 첫번째 쓰레드에서 생성자 코드를 수행할 때까지 대기한다.
                                        // [*] 이게 c++11부터 static 지역변수는 쓰레드에 safe하기 때문인듯
        std::cout << "finish getInstance" << std::endl;

        return instance;
    }
};
void foo()
{
    Singleton& s = Singleton::getInstance(); // [*] 이거 참조타입 반환인데, 아.. 이러면 그냥 이름만 붙이는듯, 
    std::cout << &s << std::endl;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
}



