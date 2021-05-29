#include <iostream>
#include <thread>
#include <string_view>

thread_local int x = 0; // [*] 이건 쓰레드당 따로따로 놓이는 전역변수

int next3times()
{
//  static int n = 0; // [*] 싱글스레드에서는 안전하지만 멀티 스레드 환경에서는 안전하지 않다. 
//	thread_local static int n = 0;
	thread_local int n = 0; // [*] TLS는 static안써도 암시적으로 static 변수가 됨
	n = n + 3;
	return n;
}
void foo(std::string_view name)
{
	std::cout << name << " : " << next3times() << std::endl; // 3 출력 되야 함
	std::cout << name << " : " << next3times() << std::endl; // 6 출력 되야 함
	std::cout << name << " : " << next3times() << std::endl; // 9 출력 되야 함
}
int main()
{
//	foo("A");
	std::thread t1(foo, "A");
	std::thread t2(foo, "\tB");

	t1.join();
	t2.join();
}



