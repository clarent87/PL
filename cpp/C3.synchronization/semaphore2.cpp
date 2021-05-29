#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>
using namespace std::literals;

std::counting_semaphore<3> sem(3); 



void Download(std::string name)
{ 
    sem.acquire(); // -- sem.counter

    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }

    sem.release(); // sem.counter += 1
}
int main() 
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    std::this_thread::sleep_for(2s);
    std::cout << "\n main \n";
    //sem.release();
    sem.release(2); // [*] 이렇게 다른 쓰레드에서도 count 증가 가능. 
                    // [*] 실행 결과
                    // [*] - 이거 호출전에는 counter가 0이고 1,2,3 쓰레드는 param 숫자를 100번 호출하는중
                    // [*] - 이거 호출되면 counter는 2가 되고, 대기중인 4,5 번이 counter를 줄이면서 들어옴
                    // [*] - 즉 특정 순간부터는 1,2,3,4,5가 모두 param숫자를 출력하다가 1,2,3은 먼저 끝나고 4,5번이 진행됨

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();   
}