#include <iostream>
#include <thread>
#include <atomic>

struct Point   { int x, y; };
struct Point3D { int x, y, z; };

std::atomic<int>     at1;
std::atomic<Point>   at2; // at2.load(), at2.store() 
                        // [*] 사용자 struct at2에 대해선 당연히 ++연산은 못하지만, 안전하게 저장하거나 로딩하는 함수는 사용가능
                        // [*] 즉 멀티 코어에 안전하게 로드하거나 저장해 달라는 함수는 쓸수 있다. 
std::atomic<Point3D> at3;

int main()
{
    ++at1; // lock xadd ... => 인텔의 경우

    std::cout << at1.is_lock_free() << std::endl; // 1 
    std::cout << at2.is_lock_free() << std::endl; // 1 ok
    std::cout << at3.is_lock_free() << std::endl; // 0  [*] 64bit os에서 4+4+4byte즉 96bit structure는 한번에 다루지 못함. 그래서 lock_free가 안됨
                                                //      [*] 즉 atomic하게 다룰수 없다는 것
                                                //      [*] 따라서 at3같은경우는 내부적으로 spin lock 등을 통해서 다루게됨
                                                //      [*] mingw환경에서 at3.is_lock_free() 는 컴파일 에러남.

    // [*] is_lock_free는 cpu레벨에서 lock_free가 보장되는지 check하는것으로 볼수 있겠네
    // [*] 즉 std::atomic가 해당 변수를 cpu opcode로 동기화를 처리하는지 아님 다른걸로 처리하는지를 판단할떄 씀
    // [*] 보통 lock_free인지 아닌지는 템플릿 인자로 넘긴 구조체/class/type의 크기를 보면 알수 있다함 (위 예제 처럼)
}

