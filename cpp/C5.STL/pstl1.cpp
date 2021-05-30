#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <execution>

void foo(int n)
{
    std::cout << n << " : " << std::this_thread::get_id() << std::endl; // thread의 id 출력 ( 싱글 쓰레드에서는 당연히 같은 id들이 출력됨)
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::for_each( v.begin(), v.end(), foo); // v의 모든 요소를 foo로 전달해라.. 라는 코드

    std::for_each(std::execution::par, v.begin(), v.end(), foo); // [*] par 는 parallel의 약어
                                                                //  [*] 병렬로 처리 해달라는 코드
                                                                //  [*] mingw는 지원못함
                                                                //  [*] 이거 실행해 보면 foo에서 출력하는 thread id가 다른것을 확인할수 있음 
}