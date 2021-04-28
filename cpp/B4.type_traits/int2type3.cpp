/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : int2type3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> struct IsPointer     {	static constexpr bool value = false; };
template<typename T> struct IsPointer<T*> {	static constexpr bool value = true;  };

template<typename T> void printv(T a)
{
	if (IsPointer<T>::value ) // if (false)
		cout << a << " : " << *a << endl; // [*] T가 int여도 컴파일 됨, 즉 int를 역참조 하니까 error.
	else
		cout << a << endl;

	/* C++17 을 사용했다면 해결됨.
	if constexpr (IsPointer<T>::value)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
	*/

}

int main()
{
	int n = 3;

	printv(n);   // error (if constexpr쓰면 에러 안남)
	printv(&n);  // ok.
}

// 핵심 개념
// 1. if문은 실행 시간 조건 문이다. 컴파일 시간에 조건이 false로 결정되어도,  if문의 코드는 컴파일 된다. 