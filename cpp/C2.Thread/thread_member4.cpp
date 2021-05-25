#include <thread>

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

    t1.swap(t2); // 이러면 t1은 goo가 실행되고, t2는 foo가 수행된다. 
                // [*] 이경우 t1,t2가 수행되다가 swap후 각각 변경된 함수를 호출한다. (아래 참조 확인)

//    std::thread t3 = t1;  // error  복사는 안된다. error는.. 삭제된 함수를 쓴다고 나오는데.. 
    std::thread t4 = std::move(t1);  // ok

//    t1.join(); // 예외. (t1이 이동했기 때문)
    t2.join();
    t4.join();
}

// 참조 https://jacking.tistory.com/1053