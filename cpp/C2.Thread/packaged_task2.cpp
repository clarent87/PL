#include <iostream>
#include <thread>
#include <future>

// [*] 멀티 스레드를 고려하지 않고 작성된 함수
int add(int a, int b)
{
    std::cout << "add" << std::endl;
    return a + b;
}
int main()
{
    std::packaged_task<int(int, int)> task(add); // 템플릿 인자는 함수의 모양을 주면됨
    std::future<int> ft = task.get_future(); // task에도 future가 있다.

    //task(10, 20); // add(10, 20) [*] task는 객체이지만 ()연산자가 재정의 되어있어서 함수처럼 쓸수 잇음
    // int ret = task(10,20); // 에러..=> 이렇게 return값을 꺼낼수는 없음 재정의된 ()연산자의 return은 void로 되어있음

    std::thread t(std::move(task), 10, 20); // [*] task를 thread인자로 보내면 멀티 쓰레드 완성
                                            // [*] 이때 task를 한번만 쓰려면 move를 하면되고
                                            // [*] 여러번 쓰려면 ref를 이용하면 된다. 
    std::cout << "continue main" << std::endl;
    
    int ret = ft.get(); // add함수의 return을 get으로 받을수 있다. 
    std::cout << ret << std::endl;
    t.join();
}

// [*] 근데 task보다는 async를 많이 쓴다함.