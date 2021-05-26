#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
//    p.set_value(a + b); [*] runtime error, set_value는 한번만 쓸수 있다.
}
int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();
 //   std::future<int> ft2 = pm.get_future(); [*] runtime error, future는 한번만 꺼낼수 있따. 
                                            //[*] 여러개의 future가 필요하면 shared_future를 복사해서 사용해야 한다. 

    std::thread t(add, std::move(pm), 10, 20);

    std::cout << ft.valid() << std::endl; // [*] 1 출력됨, valid
                                        //   [*] future를 get하기전에 유효한지 아닌지 test하는 함수
    int ret1 = ft.get();
    std::cout << ft.valid() << std::endl; // [*] 0 출력됨, valid하지 않음
//    int ret2 = ft.get(); // [*] runtime error, future의 get은 한번만 꺼낼수 있다. 

    t.join();
}




