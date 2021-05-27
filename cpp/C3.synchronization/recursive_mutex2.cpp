#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

class Machine
{
    int shared_data = 0;
    std::recursive_mutex m;
public:
    void f1()
    {
        m.lock();
        shared_data = 100;
        m.unlock();
    }
    // [*] recusive lock이 필요한 이유,, lock거는 함수에서 lock거는 함수를 호출해야 할때 필요
    void f2()
    {
        m.lock();
        shared_data = 200;
        f1();
        m.unlock();
    }
};
int main()
{
    Machine m;
	std::thread t1(&Machine::f1, &m);
    std::thread t2(&Machine::f2, &m);
	t1.join();
	t2.join();
}

// [*] 상식) 일반 함수포인터는 함수타입으로 넣어도 알아서 캐스팅이 되는데, 멤버함수는 
// [*] 멤버함수 타입을 함수포인터 타입위치에 넣을수 없음, 따라서 "&Machine::f1"이렇게 함수타입에 &를 넣어서 주소값으로 빼줘야함.



