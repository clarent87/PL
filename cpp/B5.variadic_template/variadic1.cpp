/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : variadic1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

// 가변인자 클래스 템플릿. (관례상 Types라고 씀)
template<typename ... Types> class tuple
{
};

// 가변인자 함수 템플릿
template<typename ... Types> void foo(Types ... args) // 관례상 args 라고 쓴다. 복수 형으로..
{
}

int main()
{
	tuple<int>      t1;   // Types : int
	tuple<int, int> t2;   // Types : int, int
	tuple<int, int, char> t3;

	tuple<> t4;

	foo(1);
	foo(1, 3.4); // [*] Types : int, double   args : 1, 3.4  => parameter pack
	foo();
}

// 가변인자 템플릿
// 1. c++11	부터 지원되는 문법
// 2. 가변 인자 템플릿 (클래스 템플릿, 함수 템플릿)의 기본 모양
// 3. 가변 인자 템플릿의 템플릿 읹인 "Types"는 여러개의 타입을 나타낸다. 
// 4. 가변 인자 함수 템플릿의 함수 인자인 args 안에는 여러 개의 값이 들어 있다. "Parameter Pack"이라고 한다. 