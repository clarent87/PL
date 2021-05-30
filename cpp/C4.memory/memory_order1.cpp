#include<thread>

int x = 0; // 일반 적역변수는 atomic하게 operation이 동작하지 않는다. ( atomic1,2에서 보였음)
int y = 0;

void foo()
{
    int n1 = y;
    x = n1;

    // 핵심 정리
    // 위 코드를 보았을대 아래와 같은 고려사항이 있음. 멀티 스레드에서..
    // 1.스레드에 안전한 실행을 지원하는가?
    // 2.reordering이 발생하지 않는가?

}

void goo()
{
    int n2 = x;
    y = 100;

}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join(); 
}