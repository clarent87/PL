#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

int main()
{
    std::chrono::hours        h(10); // duration의 alias들.. 
    std::chrono::minutes      m(10); // 객체 생성.. 생성관련 내용들 다시 볼필요있네.    
    std::chrono::seconds      s1(10);
    std::chrono::milliseconds s2(10);
    std::chrono::nanoseconds  s3(10);

    std::cout << s1.count() << std::endl; // 이렇게 해서 가지고 있는 값 추출 가능

    std::chrono::duration<long long>    d1(10);

    auto a1 = 10s; // chrono안에 있는 사용자 정의 literal을 사용하려면 std::literals 네임스페이스 필요 (아마 각각 타입의 객체가 나올듯)
    auto a2 = 10ms;
    auto a3 = 10min;

    std::this_thread::sleep_for( std::chrono::duration<long long>(10) ); // sleep_for의 파라메터도 duration이다.  예제는 임시객체를 넘김
    std::this_thread::sleep_for( std::chrono::seconds(10) ); // 임시객체 넘김, 오픈소스에서 이걸 많이씀 
    std::this_thread::sleep_for( 10s );                      // 이거는 회사에서 환대받지 못하기도 한다함( 너무 급격한? 변화라...)
}

// literals는 cpp11_14 기본문법4에 있다.
// 변환 생성자, 변환 연산자 (아직은 notion에 있다. )
    // 변환 연산자 : 객체 -> other 로 전환 할때, 이때는 operator가 필요
    // 변환 생성자 : other-> 객체로 전환 할때. 만약 other에 변환 연산자 정의가 가능하면 변환 연산자를 쓸수도 있음


