#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo(int a, double d)
{
	std::cout << "start foo" << std::endl;
	std::this_thread::sleep_for(2s);
	std::cout << "finish foo" << std::endl;
}

// [*] prefect fowarding도 써서 구현
class mythread
{
	std::thread th;
public:
	template<typename F, typename ... ARGS> 
	explicit mythread(F&& f, ARGS&& ... args)
		: th(std::forward<F>(f), std::forward<ARGS>(args)...) {}
	// explicit은 암시적으로 생성자가 호출되는것을 방지( 변환 같은거.. 방지)
	// perfect fowarding은 인자가 rvalue일때도 정상적으로 함수의 파라메터로 rvalue타입을 넘기기위함, lvalue도 잘 넘기고..

	~mythread()
	{
		if (th.joinable())
			th.join();
	}
};

int main()
{

// [*] 아래처럼 쓰면 매번 join해줘야 하니까 불편
//	std::thread t(foo, 10, 3.4);
//    t.join();

// [*] 따라서 block의 마지막에서 소멸자가 호출되면 여기서 join을 해주게 mythread를 만듬
//    mythread t(foo, 10, 3.4);

// [*] 많은 개발자들이 위 mythread가 편해서 개발해서 썻기때문에, c++20에서 해당 class를 제공하게됨, 그게 jthread
    std::jthread t(foo, 10, 3.4);

}
// 정리)
// std::thread 사용시 반드시 join이나 detach해야 한다. 
// std::jthread
// - c++20에서 추가된 새로운 스레드 클래스
// - Cooperatively interruptible joining thread라고 한다, 즉
// Cooperatively Interrupible + joining thread(위 예제 개념)
// 두개 특징중 더 중요한것은 Cooperatively Interrupible





