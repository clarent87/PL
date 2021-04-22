/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : template.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

class Test
{
public:
	template<typename T> static void f() {}; // 함수 템플릿
	template<typename T> class Complex {};
};

template<typename T> typename T::template Complex<int> foo(T a)  // T 는 Test
{
	Test::f<int>(); // ok. 함수 템플릿이니까 f에 <int> 붙임.

	T::f<int>();    // error. < 를 해석할수 없다.
	T::template f<int>();    // ok [*] f가 템플릿임을 알려줌.
	
	// [*] 중요 point! 위 f의 경우 () 연산자와 같이 써서 컴파일러가 f가 함수임을 안다. 

	// [*] 컴파일러가 템플릿을 빌드할때, T에 무엇이 쓰였는지를 보고 빌드하는 것이 아님.
	// [*] 단순히 템플릿만 보고 일단 일차적 빌드? 하는듯
	// [*] 즉 foo(t) 가 쓰였으니 T가 Test니까 T::f가 함수 템플릿 이다~ 라고 판단해서 T::f<int>();가 에러가 안나게 하는게 아니라는것!!
	// [*] 즉, 템플릿만 보고 일단 빌드하니까 T::f<int>()에서 "<" 에러가 나는 거임
 


	Test::Complex<int> c1; // ok.. Test의 선언을 조사할수 있다.
	T::Complex<int> c2;    // error.
	typename T::Complex<int> c3;    // error. T::Complex가 타입인건 알겠는데, "<"가 비교연산자인지 아닌지 몰라서 error
	typename T::template Complex<int> c4;    // ok

	// [*] template 키워드 쓰는 방법이 중요!!

	return c4;
}

int main()
{
	Test t;
	foo(t);
}