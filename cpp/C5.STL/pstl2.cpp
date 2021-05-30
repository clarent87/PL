#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <execution>
#include <mutex>
#include <chrono>
using namespace std::literals;

int main()
{
    std::vector<int> v(100, 0); // [*] 이거 vector에 공간을 100개를 만든것일듯, 
                                // [*] 여기서 {100,0} 초기화를 대신 쓰게되면 공간 100개가 아니라, 값 100,0이 벡터에 들어감, 즉 크기가 2

    for ( int i = 1 ; i <= 100; i++) // [*] 벡터에 1부터 100 까지 채움
        v.push_back(i);  
    
//    std::mutex m;
//    int sum = 0;

    std::atomic<int> sum = 0;
    
    // [*] 벡터의 값을 람다에 전달하는 코드
    std::for_each(std::execution::par, v.begin(), v.end(), [&](int n) {  // [*] 람다에서 지역변수(sum)를 capture해서 씀. 따라서 동기화 필요
            // [*] 동기화는 앞서 배운 mutex로 해도 된다. 
            //std::lock_guard<std::mutex> lg(m);
            //sum += n; // [*] 1 부터 100까지 더하니까 5050이 나와야 하는데..

            sum.fetch_add(n, std::memory_order_relaxed); // [*] 또는 동기화를 atomic을 이용해서 진행, 
                                                        //  [*] memory_order_relaxed가 가장가벼워서 이거씀( 본 예제는 순서를 지킬필요가 없음)
            std::this_thread::sleep_for(1ms);
        } );

    std::cout << sum << '\n';
}

// 위에서 sum은 지역변수, 따라서 쓰레드 마다 각각 다르지 않나? 라고 생각할텐데... 그게 아님
// 위에서 쓰레드로 돌리는 코드는 람다안의 코드기 때문에 여기 코드만 따로 도는것, 즉 캡쳐로 전달된 main의 변수들은 다 같이 공유 되는것
// 중요! => 즉 쓰레드에서 도는 코드에 있는 변수들만 따로따로 stack에 구성된다고 봐야 할듯...