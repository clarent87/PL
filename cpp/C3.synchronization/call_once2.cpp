#include <iostream>
#include <thread>
#include <mutex>
using namespace std::literals;

class Singleton
{
private:
    Singleton() = default;
    static Singleton* sinstance;
    static std::once_flag create_flag; // [*] flag는 스레드간 공유가 되야 해서 static 잡은듯..
public:
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

    /* 맨처음 싱글톤 코드
    static Singleton* getInstance() 
    {
        if (sinstance == nullptr) // [*] 이거 싱글 스레드에서는 괜찮은데, 멀티 스레드면 문제 있음 - 따라서 아래와 같이 call_once를 써야한다.
                                //   [*] 두 쓰레드가 동시에 여길 지나는 경우, sinstance에 할당이 두번됨 ( 이거 메모리 릭인가? )
            sinstance = new Singleton;
        return sinstance;
    }
    */
    static Singleton* getInstance() 
    {
        std::call_once(create_flag, initSingleton);
        return sinstance;
    }
    static void initSingleton()
    {
        sinstance = new Singleton;
    }
};
Singleton* Singleton::sinstance = nullptr; // [*] static 변수는 외부 정의를 해줘야 하나봄..
std::once_flag Singleton::create_flag; // [*] static이라서 외부정의가 필요해서 이거 썼다는데? - 그런듯


int main()
{
    std::cout << Singleton::getInstance() << std::endl;
    std::cout << Singleton::getInstance() << std::endl;
}



