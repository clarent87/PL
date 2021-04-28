/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : integral_constant.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

/*
// C++11에는 int2type을 발전시킨 아래 템플릿을 제공합니다

// 이제 모든 정수계열 type에 대해 가능
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

// 사용법
//integral_constant<int,   0> n0;
//integral_constant<short, 0> s0;

// true/false           : 참거짓을 나타내는 값, 같은 타입
// true_type/false_type : 참거짓을 나타내는 타입, 다른 타입.
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// 그리고 is_pointer는 아래 처럼 만들게 됩니다.
template<typename T> struct is_pointer     : false_type { }; // body에 value없어도 됨 base class에 있으니까.
template<typename T> struct is_pointer<T*> : true_type {};

*/


#include <type_traits>  // 이 안에 위코드가 있습니다.
//------------------------------

template<typename T> void printv_imp(T a, false_type) // 타입만 적어줌.. 변수는 안쓰니까 생략
{
	cout << a << endl;
}

template<typename T> void printv_imp(T a, true_type)
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv(T a)
{
	printv_imp(a, is_pointer<T>()); // is_pointer 임시객체 생성.
	                                // [*] c++에서는 child 객체를 parent type으로 받아서 쓸수 있음. 
									//    ( 이때는 virtaul 함수가 아니면 parent의 것이 쓰이지.. 그리고 parent의 함수들만 사용가능 인듯)
}

int main()
{
	int n = 3;

	printv(n);
	printv(&n);
}

// 핵심개념.
// 1. int뿐 아니라 모든 정수 계열(bool, char, short, int, long, long long)의 상수 값을 타입으로 만들 수 있게 하자. 
//    ( 참고, 실수는 템플릿 인자로 사용할 수 없다. )
// 2. integral_constant :  "모든 정수 계열의 컴파일 시간 상수"를 타입으로 만드는 템플릿.
// 3. true_type, false_type
//    - true/false           : 참거짓을 나타내는 값, 서로 같은 타입
//    - true_type/false_type : 참거짓을 나타내는 타입, 서로 다른 타입.
// 4. is_pointer 등의 type_traits를 만들 때 integral_constant 를 기반 클래스로 사용한다. 
//    - T가 포인터가 아니라면, value=false, 즉 기반 클래스는 false_type
//    - T가 포인터 라면 value=true, 즉 기반 클래스는 true_type






