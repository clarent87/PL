#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;
int shared_data = 0;

void consumer()
{
    std::lock_guard<std::mutex> lg(m);
    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{
    std::this_thread::sleep_for(10ms);
    std::lock_guard<std::mutex> lg(m);
    shared_data = 100;
    std::cout << "produce : " << shared_data << std::endl;
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}

// 위 예제의 문제는 producer가 공유데이터에 값을 쓰지도 않았는데, consumer가 값을 읽어가능 경우
// 즉, 소비자-생산자 모델에서는 생산자가 생산후에 소비 되어야 한다.
// -> 즉, Data가 준비 되었음을 알려야 한다.
// -> 이기능을 std::condition_variable이 제공