#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable> // 이거 필요
using namespace std::literals;

std::mutex m;
std::condition_variable cv;
int shared_data = 0;

void consumer()
{
    std::this_thread::sleep_for(200ms); // [*] 마지막에 추가한 코드.. 
                                        // [*] 즉 producer가 notify_one으로 신호를 먼저 준경우
                                        // [*] consumer는 wait를 나중에 호출하기 때문에 신호를 못받으니,, 영원히 block됨
                                        // [*] 이문제는 다음 cond3예제에서 해결..

    //std::lock_guard<std::mutex> lg(m); // [*] condition_variable사용시 lock_guard는 쓰지 못함, unique_lock만가능
    std::unique_lock<std::mutex> ul(m); 
    cv.wait(ul); // [*] unique_lock을 파라메터로 넘겨준다. wait함수는 자원이 준비 될때까지 기다린 다는것
                // [*] wait는 lock을 일단 풀고 signal을 대기한다. 
                // [*] 이후 signal이 오면 lock을 다시 걸로 진행함 -> 즉 signal이 와도 producer가 lock을 잡고 있으면 blocking됨
                // [*] 즉 lock을 먼저 풀기 때문에 producer가 먼저 값을 쓸수 있도록 배려한것
    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
    std::this_thread::sleep_for(10ms);
    {
        std::lock_guard<std::mutex> lg(m); // [*]여긴 lock_guard 써도 됨.. notify_one api에는 파라메터 안주니까.
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;
    } // [*]일부러 block을 잡음.. unlock을 미리 하고 notify_one호출하려고.. 그래야 consumer가 바로 lock잡고 동작가능
    cv.notify_one();
    //std::this_thread::sleep_for(3s);
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}

// 위 예제는 wait가 먼저 호출되어야 잘 동작하는 예제 이다.