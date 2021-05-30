#include<thread>
#include<atomic>
#include<cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;


int main()
{
    data1.store(100, std::memory_order_seq_cst); // [*] memory_order_seq_cst는 atomic 연산, 그리고 memory_order_seq_cst operation간 순서를 보장
    data2.store(200, std::memory_order_seq_cst); 
    data2.store(300); // [*] defualt는 std::memory_order_seq_cst가 쓰이는데, std::memory_order_seq_cst는 다른 옵션에 비해 overhead가 크다
}