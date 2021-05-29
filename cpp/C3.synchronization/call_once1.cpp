#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::once_flag init_flag; // [*] 함수가 호출됬었는지 아닌지를 기록하는 변수
//std::once_flag a = init_flag;// error [*] 복사와 이동이 모두 삭제되었기 때문

void init(int a, double d) // [*] 예제 목적 : 동일한 foo 함수를 여러 개의 스레드로 수행하지만 "초기화 작업(init)은 한번만 수행" 하고 싶다.
{
    std::cout << "init" << std::endl;
    std::this_thread::sleep_for(2s);
}
void foo()
{
    std::cout << "start foo" << std::endl;
    //init(10, 3.4);    
    std::call_once(init_flag, init, 10, 3.4 ); // [*] 동작
                                            //    [*] 최초에 여기 도착한 쓰레드는 init함수 실행
                                            //    [*] init함수 끝나기 전에 여기 도착한 쓰레드는 모두 대기
	std::cout << "finish foo" << std::endl;
}
int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
    std::thread t3(foo);
	t1.join();
	t2.join();
    t3.join();
}



