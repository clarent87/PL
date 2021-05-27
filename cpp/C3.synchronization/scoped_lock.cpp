#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

struct  Account // 계좌
{
    std::mutex m; // thread safe를 위해 뮤텍스를 하나 둠 (아마 money변수 )
    int money = 100;
};

/*
void transfer(Account& acc1, Account& acc2, int cnt)
{
//    acc1.m.lock();
//    acc2.m.lock();
    std::lock(acc1.m, acc2.m); // [*] 위 두코드를 대체해서 deadlock을 회피( 위 두코드는 기본적으로 본 예제의 의도에 따라 deadlock걸리는 코드 )
                            //    [*] std::lock은 deadlock 회피 기술을 사용해서 여러 개의 뮤텍스를 안전하게 lock해준다.

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
    acc2.m.unlock();
    acc1.m.unlock();
}
*/

/*
// 위 예제의 unlock() 호출을 편리하게 하기 위해, 앞서 배운 lock_guard를 활용하는 코드
// adopt_lock를 쓰는 예제이다. 본 예제 처럼 여러 뮤텍스를 lock하고서 쓴다. 
void transfer(Account& acc1, Account& acc2, int cnt)
{
    std::lock(acc1.m, acc2.m);
    std::lock_guard<std::mutex> lg1(acc1.m, std::adopt_lock); 
    std::lock_guard<std::mutex> lg2(acc2.m, std::adopt_lock);
    // [*] 근데.. 매번 이렇게 lock쓰고 lock_guard 따로 따로 매번 써줘야 하나? 귀찮은데..
    // [*] 그래서! 나온게 scopred_lock

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
}
*/

// 한쪽 계좌에서 다른쪽으로 cnt만큼 돈을 옮기는 함수
void transfer(Account& acc1, Account& acc2, int cnt)
{
//    std::scoped_lock<std::mutex, std::mutex> lg(acc1.m, acc2.m);// ok
    std::scoped_lock lg(acc1.m, acc2.m);// ok [*] 생성자로 템플릿 인자 추론 가능 (이거 c++17에서 추가됨, 짜피 scoped_lock도 17꺼)

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
}

int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5); 

    // [*] 위 예제는 t1, t2 쓰레드 실행시 데드락이 발생하게 구성한 예제 인다. 
    // [*] 왜냐면 t1에서 kim의 뮤텍스를 lock하는 순간, t2에서 lee의 뮤텍스를 lock한다. 
    // [*] 이후 t1에서 lee의 뮤텍스 접근시 lock이 되어 있어서 block, t2에서 kim의 뮤텍스 접근시 lock 되어 있어서 block

    t1.join();
    t2.join();
}
 
