#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

std::shared_mutex m;
int share_data = 0;

void Writer()
{
    while(1)
    {
        {
            std::lock_guard<std::shared_mutex> lg(m); //[*] lock 호출
            share_data = share_data + 1;
            std::cout << "Writer : " << share_data << std::endl;
            std::this_thread::sleep_for(1s);        
        } //[*]lock_guard 소멸자 호출위치. 즉 여기서 unlock 됨       

        std::this_thread::sleep_for(10ms);
    }
}
void Reader(std::string_view name)
{
    while(1)
    {   
        {  
            //m.lock_shared();
        
            //std::lock_guard<std::shared_mutex> lg(m); // [*]여기서 lock_guard를 쓰면 Reader들 끼리도 동기화됨
                                                        // [*]왜냐면 lock가드는 생성자에서 lock을 호출하지 lock_shared를 호출하는 것이 아니기 때문
                                                        // [*]따라서 아래 처럼 shared_lock이 필요한것
            std::shared_lock<std::shared_mutex> lg(m);
            // lg.unlock(); // [*] 이건 unlock을 내부적으로 호출하진 않고, unlock_shared를 호출
                            // [*] 명시적으로 호출안해도 소멸자에서 알아서 호출됨
                            // [*] * 근데 강사는 lg.unlock에서 lock_shared/unlock_shared가 호출된다고 하는데..잘못 말한거 일듯
            std::cout << "Reader(" << name <<  ") : " << share_data << std::endl;
            std::this_thread::sleep_for(500ms);
            
            //m.unlock_shared();
        }
        
        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
	std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");
    std::thread t4(Reader, "C");
	t1.join();
	t2.join();
    t3.join();
	t4.join();
}



