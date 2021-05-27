#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex> // 헤더가 별도로 있다.
#include <string_view>
using namespace std::literals;

//std::mutex m;
std::shared_mutex m;
int share_data = 0;

void Writer()
{
    while(1)
    {
        m.lock(); // [*] 쓰기중에는 읽기가 읽어나면 안되니까, lock으로 해야함 ( shared_mutex에도 lock제공인듯,, 뭐 당연한가..)
        share_data = share_data + 1;
        std::cout << "Writer : " << share_data << std::endl;
        std::this_thread::sleep_for(1s);        
        m.unlock();
        std::this_thread::sleep_for(10ms);
    }
}
void Reader(std::string_view name)
{
    while(1)
    {      
        //m.lock();
        m.lock_shared(); // [*] lock_shared 간에는 뮤텍스 공유 가능
        std::cout << "Reader(" << name <<  ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        //m.unlock();
        m.unlock_shared();
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



