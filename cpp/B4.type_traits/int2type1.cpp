/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : int2type1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int    a) {}
void foo(double a) {}

int main()
{
	// 타입에 따른 함수 오버로딩
	foo(3);		// foo(int) 
	foo(3.4);	// foo(double)

	// 값에 따른 오버로딩 ?? - 0, 1 은 같은 타입이므로 같은 함수 호출
	foo(0);	// foo(int)
	foo(1);	// foo(int);
}
// 핵심개념
// 1. 함수 오버 로딩은 인자의 개수가 다르거나, 인자의 타입이 다를 떄 사용한다. 
// 2. 인자의 개수와 타입이 동일 할떄, 인자의 값 만으로는 오버로딩 할 수 없다. 