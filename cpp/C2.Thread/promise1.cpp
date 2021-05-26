#include <iostream>
#include <thread>
#include <future> // promise사용에 필요
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b) // promise객체는 &나 &&로 받아야 한다. 
{
	int s = a + b;
	std::this_thread::sleep_for(1s);
	//p.set_value(s); // promise에 value 세팅

	p.set_value_at_thread_exit(s); // 쓰레드가 끝날때 값을 넣어 달라는것. ( 실행해보면 add 출력 이후 30이 찍힘)
	
	std::cout << "add" << std::endl;
	std::this_thread::sleep_for(1s);
}
int main()
{
	std::promise<int> pm; // 템플릿의 값은 세팅할 value의 type인듯
	std::future<int> ft = pm.get_future(); // pm을 통해 전달된 값은 ft를 통해 꺼낼수 있따. 

	std::thread t(add, std::move(pm), 10, 20); // add의 promise가 &일땐 std::ref로 전달( 현재는 &&라 move사용)
												// promise객체 전달
	//....
	int ret = ft.get(); // blocking	 - 쓰레드에서 결과값이 도착하지 않았을 경우..		
	std::cout << ret << std::endl;  // 30
	t.join();
}



