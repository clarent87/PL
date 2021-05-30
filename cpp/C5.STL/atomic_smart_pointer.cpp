#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

void foo()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(5); // 이때 ptr은 "자원5" 와 "ref counter" 을 가리킴

    // 값에 의한 캡쳐
    // [*] 캡쳐를 값으로 하게 되면 값들은 const 가 붙음. 따라서 mutable을 써줘야 변경가능 
    // [*] ptr을 값복사 했으니 ptr은 원본 ptr "자원5" 와 "ref counter"을 똑같이 가르키게됨
    // [*] 이떄 ref counter는 1증가 일듯
    std::thread t1( [ptr]() mutable  
    { 
        ptr = std::make_shared<int>(1); // --ref
                                        // [*] 만약 local ptr에서 다른 값을 할당하면 기존 원본 ptr의 ref값이 감소할까?
                                        // [*] cpp에서 shared_ptr의 관리 객체(ref counter있는 구조체)는 설계 때부터 동기화에 문제 없이 동작하게 만들어짐
                                        // [*]   - 동기화 문제 없다는건 atomic 하게 ref counter가 관리 되거나, mutex를 사용해서 ref의 증가 감소에 문제 없게 구성되어있다 봐야겠지..
                                        // [*] 즉 ptr를 쓰레드 몇개에서 쓰더라도 문제 없이 ref의 감소가 가능
    });

    std::thread t2( [ptr]() mutable 
    { 
        ptr = std::make_shared<int>(2);
    }); 
    t1.join();
    t2.join();
}

// [*] 만약 람다에 shared_ptr를 참조로 전달하면? 이것도 쓰레드에 안전할까? 
// [*] 답은 NO.
// [*] 따라서 atomic을 써야 한다. (c++20부터 가능)
void goo()
{
//    std::shared_ptr<int> ptr = std::make_shared<int>(5); 

    // C++20 부터 아래 코드 허용.
    std::atomic<std::shared_ptr<int>> ptr = std::make_shared<int>(5);

    // 참조에 의한 캡쳐
    // [*] ptr를 참조 전달 했으니, t1,t2, main모두 ptr은 같은것을 쓴다. 
    // [*] 이때 ptr에 각각 다른 값을 세팅하면.. 기본적으로는 의도하지 않은 동작이 발생함
    // [*] 따라서 atomic으로 shared_ptr을 감싸주면 문제 없이 동작.
    // [*] mutable은 필요없음
    std::thread t1( [&ptr]() //mutable 
    { 
        ptr = std::make_shared<int>(1);
    });

    std::thread t2( [&ptr]() //mutable 
    { 
        ptr = std::make_shared<int>(2);
    }); 
    t1.join();
    t2.join();
}

int main()
{
    foo();
}
