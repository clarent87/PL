#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
}

// [*] 아래 함수 보면 promise랑은 다르게 값으로 shared_future를 받는것이 특징
void consume(std::shared_future<int> sf)
{
    sf.get();
    std::cout << "finish foo" << std::endl;
}
int main()
{
    std::promise<int> pm;
//    std::future<int> ft = pm.get_future();
    //std::future<int> ft2 = ft; // error [*] future는 복사가 안됨 (복사생성자 호출일듯)
//    std::shared_future<int> sft = ft.share(); // [*] 이건 가능

    std::shared_future<int> sft = pm.get_future(); // [*] share_future는 위에 처럼 future에서 꺼내도 되고, 
                                                    //[*] promise에서 바로 꺼내도 된다. 
                                                    //[*] future를 꺼낼때랑 같은 함수(get_future)로 꺼내는데 잘된다.
                                                    //[*] 흠,, 어케 이게 가능하지? future를 shared_future로 바꾸는 변환생성자라도 있나?
 
    std::thread t(add, std::move(pm), 10, 20);

    std::thread t1(consume, sft); // [*] share_future는 값으로 넘긴다.
    std::thread t2(consume, sft);

    t.join();
    t1.join();
    t2.join();
}

// std::future vs std::shared_future
// std::future : non-copyable, only movable => 즉 해당 객체는 복사가 안됨, 항상 move만 가능
// std::shared_future : copyalbe

