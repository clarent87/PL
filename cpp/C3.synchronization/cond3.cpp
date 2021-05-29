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
    std::this_thread::sleep_for(2s);
    std::unique_lock<std::mutex> ul(m); // [*] 생성자에서 lock잡음.. 따라서 producer는 unlock을 하고 notify_one해야함

    cv.wait(ul, [] { return data_ready; }); // [*]람다 표현식은 [](){} 인데, 인자가 없는경우 ()를 빼도 된다.
                                    // [*] wait(ul, Predicate pred);
                                    // [*] Predicate의 return이 false면 wait. 아니면 wait는 무시
                                    // [*] 이 예제가 condition_variable을 이용하는 가장 기본적인 예제

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
    //    std::this_thread::sleep_for(2s);
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        data_ready = true;
        std::cout << "produce : " << shared_data << std::endl;
    } // [*] unlock이 되어야 함
    cv.notify_one();
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}