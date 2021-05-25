#include <iostream>
#include <thread>

void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};
struct Work
{
    void operator()(int a, double b) const {} // () 연산자를 재정의 해서 함수 객체처럼 쓰기위해
};
int main()
{
    Machine m;
    Work w;  w(1, 3.4); // 함수객체
    std::thread t1( &foo, 1, 3.4 ); // 함수넘길때 &가 없어도 되긴 한다함.. 왜냐면 함수타입을 함수포인터로 자동 형변환 해주기 때문
    std::thread t2( &Machine::Run, &m, 1, 3.4 ); // 멤버함수 호출시에는 첫번째 파라메터로 객체 필요 ( 이거 강제로 이렇게 쓰는 예제.. 어디 있었지?)   
                                                // c++ 기초에 있음 pointer to member operator 
    std::thread t3( w, 1, 3.4 ); // w() 호출이 가능하므로 w 넘김
                                // 객체 자체를 넘기는 것은 복사 생성자를 유도하는거 같음 ( 질문에 객체 주소를 넘기면 안된다는 내용이 있었음)
    std::thread t4( []{ std::cout << "lambda" << std::endl;} );
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

// std::thread의 생성자는 템플릿이라서 위와 같이 w나 람다를 넘기는 경우 해당하는 딱 맞는 생성자가 생성되어서 위 내용이 가능한 것으로 보임
// 음.. callable object 항목을 다시 보고 생각해봐야 할듯
