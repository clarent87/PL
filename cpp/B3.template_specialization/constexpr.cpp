#include <iostream>
using namespace std;

template<int N> struct check {};

// constexpr 함수 - C++11
constexpr int add(int a, int b)
{
	return a + b;
}

int main()
{
	int n = add(1, 2);

	check< add(1, 2) > c; // ok.. (add가 실행시간에 계산되는거였으면, 컴파일 실패가 났을것)


	int n1 = 1, n2 = 2;

	int c = add(n1, n2); // ok

	//check< add(n1, n2) > c; // error
}

// [*] constexpr를 붙이면 성능 향상도 있을수 있고 ( 컴파일 타임 상수를 parameter로 주는경우 컴파일 타임에 계산되므로..)
// [*] 그리고 템플릿 인자로도 쓸수 있으니, c++라이브러리의 간단간단한 함수는 대부분 constexpr이 붙어 있다.

// QUIZ. 답
// [*] 생성자도 constexpr이 될수 있다. 
// [*] 가상함수는 constexpr이 될수 없다. 











