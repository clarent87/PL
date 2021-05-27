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
    std::unique_lock<std::mutex> ul(m);

    cv.wait(ul, [] { return data_ready; }); // [*]람다 표현식은 [](){} 인데, 인자가 없는경우 ()를 빼도 된다.
                                    // [*] wait(ul, Predicate pred);
                                    // [*] Predicate의 return이 false면 wait. 아니면 wait는 무시

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
    }
    cv.notify_one();
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}