#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>
using namespace std::literals;

//std::counting_semaphore<3> sem(0); // [*]이경우 counter는 0 즉 다른곳에서 release를 먼저 수행해 줘야함
                                    //  [*]이렇게 쓰는경우도 많다함
//std::counting_semaphore<1> sem(1); 
std::binary_semaphore sem(1); // [*] 이거 위와 같다. 
                            //   [*] using binary_semaphore = std::binary_semaphore<1>;


void Download(std::string name)
{ 
    sem.acquire(); 
    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }
    sem.release();
}


int main() 
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();   
}