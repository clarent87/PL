#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 벡터 1~10으로 초기화
    std::vector<int> v2(10);                               // 10개짜리 벡터 만듬

    std::promise<void> pm1; // [*] 그냥 쓰레드 sync맞추는 용도로 쓸꺼라,, 값을 전달하진 않기땜문에 void씀
    std::future<void> ft1 = pm1.get_future(); // [*] void이기 때문에 return값이 없음

    std::promise<int> pm2;
    std::future<int> ft2 = pm2.get_future();

    std::thread t([&] { // [*] 함수대신 그냥 람다 씀, 대신 레퍼런스 캡쳐를 써서 v2에 값을 넣을수 있게 함 ( 원본의 ref)
        std::partial_sum(v1.begin(), v1.end(), v2.begin()); // 부분합 구하기, v2에 결과가 추가됨 [*] 연산이 오래 걸린다 가정 

        pm1.set_value(); // 1번째 연산이 종료되었음을 알린다.
                        // [*] pm1이 void였기때문에, 파라메터 없이 호출 가능
                        // [*] 앞선예에서는 promise를 thread 생성자의 파라메터로 넘겼는데(ref나 move이용해서)
                        // [*] 여기서는 람다 레퍼런스 캡쳐를 썻으니 pm1을 다이렉트로 접근해서 쓸수 있음

        int s = std::accumulate(v2.begin(), v2.end(), 0); // 구간의 합 구하기 [*] 연산이 오래 걸린다 가정

        pm2.set_value(s);
    });

    ft1.get();
    for (auto n : v2) // [*] get으로 blocking안해주면, 주쓰레드, 쓰레드 sync가 안맞으니까, v2의 값들이 계산 전의 0값이 출력됨
        std::cout << n << ", ";

    int ret = ft2.get();
    std::cout << "\n" << ret << std::endl;

    t.join();
}
