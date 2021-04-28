/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : remove_pointer1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// T에 변형 타입 구하기
// primary template : typedef 제공
template<typename T> struct xremove_pointer
{
	typedef T type;
};

template<typename T> struct xremove_pointer<T*>
{
	typedef T type;
};

template<typename T> void foo(T a)  // T : int*
{
	// 반드시 typename 있어야 합니다.
	typename  xremove_pointer<T>::type n;  

	// n의 타입 이름 출력
	cout << typeid(n).name() << endl;
}

int main()
{
	int n = 10;
	foo(&n);
}

// 굉장히 중요한 개념, 뒤에서 많이 쓰임
// 아직 완벽한거 아님, const랑 volatile 고려해야 함. => is_pointer 예제 처럼, const,  volatitle, const volatile 버전 부분특수화 해주면됨
// - 강의에선 만들었음. 

// * 변형 타입을 구하는 traits 만드는 방법
// 1. primary template을 만들고 "typedef T type"을 제공한다. (c++11 using도 사용가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할" 한다. 
// 3. cv(const, volatile)버전이 필요한지를 고려한다. 