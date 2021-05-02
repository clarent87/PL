/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : IsPointer.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


#include <iostream>
using namespace std;

// type traits : 템플릿 인자 T의 다양한 특성을 조사/변화하는 다양한 메타 함수

// 만드는 방법
// primary template : false 리턴( value = false )라는 의미.
// 부분 전문화 버전  : true 리턴(value = true)라는 의미


// 구조체(클래스)안에서 =로 초기화 가능한 방법

// 1. enum { value = true } : 예전 부터 지원
// 2. static const bool value = true; 2000년 이후 지원
// 3. bool value = true;     // C++11은 모든 변수를 = 초기화 가능.

template<typename T> struct IsPointer
{
	//enum { value = false }; // 예전 스타일
	//static const bool value = false;  // 
	static constexpr bool value = false;  // C++11의  constexpr 사용
};

// [*] 핵심 : 포인터 타입에 대해서 부분 특수화!!!
template<typename T> struct IsPointer<T*> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11의  constexpr 사용
};


template<typename T> void foo(const T& a)
{
	if (IsPointer<T>::value) // enum일때도 가능한 구문, 즉 enum은 static value라고 보면 될듯
		cout << "포인터입니다." << endl;
	else
		cout << "포인터가 아닙니다." << endl;
}

int main()
{
	int n = 0;
	foo(n); // not pointer
	foo(&n); // pointer

	// [*] int& a = x 이건 참조자이고, int *c  = &b 에서 &b는 b의 주소 즉, 포인터를 추출하는 것.
	// [*] 중요한건 이떄 a는 x의 별칭처럼 쓰이지만 type은 참조타입이다. !!
}


// [*] 정리
// type query를 위한 type traits 만드는 일반적인 방법
// 1. primary template에서 false를 리턴(value=false)
// 2. partial specialization에서 true를 리턴(value=true)