#include <thread>
#include <atomic>

std::atomic<int> x = 0; // 강사 코드에서는 에러 없음.. 이거 빨간줄은 class일때나 의미가 있을듯
std::atomic<int> y = 0;

void foo()
{
    int n1 = y.load(std::memory_order_relaxed); // [*] atomic하게 값이 load되는 것을 보장 (n1에 값이 저장되는거까지? atomic?)
    x.store(n1, std::memory_order_relaxed);     // [*] atomic하게 값을 저장하는 것을 보장

    // memory_order_relaxed 는 위 두 코드가 순서가 바뀔수도 있다. ( 즉 순서 바뀌는것을 막지는 않음)
}

void goo()
{
    int n2 = x.load(std::memory_order_relaxed);
    y.store(100, std::memory_order_relaxed);
}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join();
    t2.join();
}

// 기본적으로 n1,n2는 둘다 동시에 100이 될수는 없는데.
// 만약 goo의 code 순서가 변경된다면
// 즉,  y=100이 n2=x보다 먼저 호출되고, 이때 foo의 내용이 진행되면 x=100이됨
// 이후 goo의 남은 코드인 n1 = x가 호출되게 되면
// 최종적으로 n1,n2가 동시에 100인 상황이 연출된다.