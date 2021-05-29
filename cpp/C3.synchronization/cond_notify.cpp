#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std::literals;
  
std::mutex m;
std::condition_variable cv;
bool data_ready = false;
int shared_data = 0;

void consumer()
{       
    std::unique_lock<std::mutex> ul(m);  
    cv.wait( ul, [] { return data_ready;} );
    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{     
    std::this_thread::sleep_for(100ms); 
    {
        std::lock_guard<std::mutex> lg(m);        
        shared_data = 100;
        data_ready = true;
        std::cout << "produce : " << shared_data << std::endl;    
    }
    cv.notify_all(); // [*] 대기중인 모든 쓰레드를 한큐에 깨우는 api
//    cv.notify_one(); // [*] consumer는 세개가 도는데, 이 api쓰면 하나만 깨어남
//    std::this_thread::sleep_for(500ms); 
//    cv.notify_one(); // [*] 따라서 세번 호출해야 consumer가 다 깨어남.
//    std::this_thread::sleep_for(500ms); 
//    cv.notify_one();
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    std::thread t3(consumer);
    std::thread t4(consumer);
    t1.join(); t2.join();
    t3.join(); t4.join();
}