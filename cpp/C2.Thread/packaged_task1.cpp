#include <iostream>
#include <thread>
#include <future>

// add 함수가 promise 를 통해서 반환값 전달
// 다른 스레드에 반환
// [*] 즉 멀티 쓰레드를 고려해서 만들어진 함수.
// [*] 다시 말해, 쓰레드용으로 설계된 함수라는것.
void add(std::promise<int>&& p, int a, int b)
{
    p.set_value(a + b);
}

int main()
{
    std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::move(pm), 10, 20);

	int ret = ft.get(); 

    t.join();
}



