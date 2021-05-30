#include<thread>
#include<atomic>
#include<cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;
std::atomic<int> flag = 0;

void foo()
{
    data1.store(100, std::memory_order_relaxed);
    data2.store(200, std::memory_order_relaxed); // [*] memory_order_relaxed이기 때문에 data1.store랑 순서 바뀔수 있따. 
    // flag.store(1, std::memory_order_relaxed); // [*] memory_order_relaxed는 이 코드의 순서가 변경되는 것을 막지 않는다, 
                                                //  [*] 즉 data2.store보다 이게 먼저 수행될수도 있음

    flag.store(1, std::memory_order_release); 

}

void goo()
{
    // if(flag.load(std::memory_order_relaxed) > 0) // [*] flag가 1이 되었을때 , data1, dat2가 100,200 을 보장하는지 확인하는 코드
    // {                                            // [*] foo에서 memory_order_relaxed를 썻다면 당연히 보장이 안됨

    if(flag.load(std::memory_order_acquire) > 0)    // [*] release 이전의 코드들은 acquire이후에도 읽을수 있음을 보장 ( 즉 적어도 flag.store의 실행 순서는 보장)
    {
        assert(data1.load(std::memory_order_relaxed) == 100);
        assert(data2.load(std::memory_order_relaxed) == 200);
    }

}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}