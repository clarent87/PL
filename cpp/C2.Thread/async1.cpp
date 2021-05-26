#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
    //add(10, 20); // 동기 호출
    // std::async(add, 10, 20); // [*] 간단하게 add를 비동기로 수행한다. 즉, thread를 만들어줌 (std::thread 했을때보다 코드가 간결함.)
    std::future<int> ft = std::async(add, 10, 20); // [*] async는 future를 반환
    std::cout << "continue main" << std::endl;
    int ret = ft.get();
    std::cout << "result : " << ret << std::endl;
}
