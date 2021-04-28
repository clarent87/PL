/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : int2type5.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> struct IsPointer { static constexpr bool value = false; };
template<typename T> struct IsPointer<T*> { static constexpr bool value = true; };

// if 문을 사용한 함수 분기 : 실행시간 결정..
// 함수 오버로딩을 사용한 분기 : 컴파일 시간에 결정..

// 숫자로 함수 오버로딩하는 도구
template<int N> struct int2type
{
	static const int value = N;
};

template<typename T> void printv_imp(T a, int2type<0>) //[*] int2type<0>는 변수의 이름은 필요 없다. ( 번수를 전달 받을껀 아니고, type만 받을꺼라서. )
{
	cout << a << endl;
}

template<typename T> void printv_imp(T a, int2type<1>)
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv(T a)
{
	// 함수 오버로딩은 컴파일 시간에 인자에 타입으로 함수 호출이 결정된다

	printv_imp(a, int2type< IsPointer<T>::value >());
				// 함수의 인자로는 type이 아니라 객체가 필요
				// [*] 따라서 int2type<1> 구조체/class타입에 ()를 붙여서 임시객체를 만들어서 넘김 
				// 포인터 : 1
				// 포인터 아님 : 0

}

int main()
{
	int n = 3;

	printv(n);
	printv(&n);
}

// 해결책
// 1. 동일한 이름을 가진 함수가 여러 개 있을 때, 어느 함수를 호출할지 결정하는 것은 컴파일 시간에 이루어 진다. 
//    선택되지 않은 함수가 템플릿이었다면 "instatntiation"되지 않는다. 

// int2type은 2000년대 기술인데 c++11 표준에서는 해당 기술이 너무 좋다고 판단하여, integral_constant 라는 이름으로 발전시켜서 표준에 넣음ㄴ




