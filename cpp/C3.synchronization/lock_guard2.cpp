#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
    m.lock(); // [*] m을 미리 lock해둠
//    std::lock_guard<std::mutex> lg(m);
    std::lock_guard<std::mutex> lg(m, std::adopt_lock); // [*] 이미 lock이 된 mutex를 받을떄 이렇게 씀
														// [*] 그냥 lock_guard랑 다르게 생성자에서 lock을 하지 않음
														// [*] 단 소멸자에선 unlock한다. 
														// [*] 따라서, error가 없으려면, mutex m은 이전에 lock이 걸렸어야 함

    std::cout << "using shared data" << std::endl;
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	t1.join();
	t2.join();
}

// [*]이게 왜 필요한지는 뒤어 가면 나온다함. 
// [*] 간단히 설명하길, 한번에 모든 mutex를 lock걸고, 각각은 lock_guard로 관리하는 case 있다함



