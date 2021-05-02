#include <type_traits>
using namespace std;

template<bool b, typename T = void> struct enable_if
{

};

// 부분 특수화인데 T값이 없어도 primary의 default가 사용됨을 주의
template<typename T> struct enable_if<true,T>
{
    typedef T type;
};

int main()
{
    // [*] 템플릿의 사용법은 primary의 형태를 보고 결정하는 것

    enable_if<true,int>::type t0; // int type
    // enable_if<true>::type t1; // [*] void type ( 사실 void type은 변수를 만들수 없으므로.. 변수를 만들땐 type*라고 해서 void*를 만들면 된다. )
   
    enable_if<false, int>::type t1; // error, primary에 type이란게 없음
    enable_if<false>::type t1;      // error, primary에 type이란게 없음
}

// enable_if
// 1. c++표준에서 지원하는 도구
// 2. 1번쨰 인자가 true일 경우만 type이 정의 된다. 
//    - enable_if<true, int>::type => int
//    - enable_if<true>::type => void
//    - enable_if<false, int>::type => error
//    - enable_if<false>::type => error