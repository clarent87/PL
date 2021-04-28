/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : int2type2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

template<int N> struct int2type
{
	enum { value = N }; // 옛날 스타일, 요즘은 constexpr 사용.
};

void foo(int n) {}

// 0, 1 에 따른 함수 오버로딩.
void foo(int2type<0>) {}
void foo(int2type<1>) {}

int main()
{
	foo(0);	
	foo(1);	// 0, 1은 같은 타입.. foo(0), foo(1)은 같은 함수 호출
	
	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1 은 다른 타입이므로 foo(t0), foo(t1)은 다른 함수 호출.
}

// int2type개념
// 1. 컴파일 시간 정수형 상수를 각각의 독립된 타입으로 만드는 도구.
// 2. int2type을 사용하면 "컴파일 시간에 결정된 정수형 상수"를 모두 다른 타입으로 만들 수 있다. 
	// 77,78은 같은 타입의 수이지만, int2type<77>, int2type<78>은 다른 타입이다. 
// 3. int2type을 사용하면 "컴파일 시간에 결정된  정수형 상수"를 가지고 함수 오버 로딩에 사용하거나, 템프릿 인자, 상속 등에서 사용할 수 있다. 