#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "start add" << std::endl;    
    std::this_thread::sleep_for(2s);
    std::cout << "finish add" << std::endl;    
    return a + b;
}
int main()
{
//    std::future<int> ft = std::async( std::launch::async, add, 10, 20); // [*] 이렇게 하는 경우 ft는 지역변수 객체니까, block을 벗어날때 파괴되면서 소멸자가 호출됨
                                                                        //   [*] 이때 ft의 소멸자에서 get이 호출되며 add함수의 결과를 대기.
                                                                        //   [*] 즉 get을 호출하지 않아도 add의 종료를 대기 한다. 
    
    std::async( std::launch::async, add, 10, 20); // [*] 이거 신기함
                                                //   [*] 반환값을 받지 않았을대, 어쨋든 async는 임시객체 return을 하므로 ;에서 임시 객체가 파괴됨
                                                //   [*] 따라서 future의 소멸자가 호출되니까 get이 동작함
                                                //   [*] 즉, async호출후 add함수의 종료를 대기하는 형태의 코드가 됨, 따라서 main은 여기서 add 종료까지 멈춤
                                                //   [*] future의 이런 효과는 async에서만 나타난다.!!! (중요)

                                                //   [*] 참고: 함수 return이 임시객체인건 NRVO 개념 (notion의 임시객체 참조)
                                                //   [*] std::future<int> ft = 임시객체 일땐 아마.. move 생성자가 호출되는 것일듯, 복사 생성자 말고.. 
                                                //   [*] 그래야, 임시객체 소멸자의 get이 동작하지 않을듯.. 
                                                //   [*] 어.. 근데 강사는 "복사"해서 넘어온다고 하는데.. 복사에서 mutable로 세팅된 부분이 있는건가?
    
    std::async( std::launch::async, add, 10, 20); // [*] 한번더 실행하면, 위에꺼랑 이게 동시에 실행되는게 아니라, 위에게 끝나고 이게 실행됨
                                                //   [*] 왜냐면, 위에서 임시객체 소멸자 때문에 위 async의 쓰레드가 종료할때까지 대기 하기 때문
    std::cout << "continue main " << std::endl;    

//    int ret = ft.get();
} // [*] 지역변수 ft가 파괴되는 위치

 

