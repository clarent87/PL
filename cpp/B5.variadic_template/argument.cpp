/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : argument.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int f(int, double, char) { return 0; }

// 함수의 N 번째 인자 타입 구하기.
template<int N, typename T> struct argument
{
	typedef void type;
};

// N == 0 일때
template<typename R, typename A1, typename ... Types> struct argument<0, R(A1, Types...)>
{
	typedef A1 type;
};

// N != 0 일때
template<int N, typename R, typename A1, typename ... Types> struct argument<N, R(A1, Types...)>
{
	typedef typename argument<N-1, R(Types...)>::type type; // ::type이 템플릿에 의존적이라 값인지 type인지 모르니 typename붙임.
															// [*] 근데 ::으로 값이나 type은 뺀적있지만 template을 뺀적은 없는거 같음. 
															// [*] using은 그냥 alias 만들던거고..
};


template<typename T> void foo(T& t)
{
	typename argument<1, T>::type n;

	cout << typeid(n).name() << endl; // double
}

int main()
{
	foo(f);
}

// 이번 예제의 형태는 너무나도 많이 쓰이고 뒤에서도 나오니 반드시 알아둬야함.
	// 0번째를 먼저 구하고, 0이 아닐때는 재귀를 도는 형태를 말함.

// 함수의 정보를 구하는 traits 만들기
// 1. primary template을 만들고 "typeef T type"을 제공한다. 
// 2. 함수 타입인 T 안에 있는 함수 인자 타입을 얻을 수 있도록 부분 특수화 한다. 
//  - T => R(A1,A2) -> traits챕터예, T => R(A1,Types...)  -> 이번 챕터 예. 
// 3. N번쨰 인자 타입 구하는 방범
//  - 0번쨰 인자의 타입을 구하는 부분 특수화 작성
//  - N번쨰 인자의 타입을 구하는 부분 특수화 작성하고
//    - N == 0 이 될때까지 recursive를 사용한다. 
//    - Recursive사용시, 함수의 0번째 인자를 제거한고 N-1을 사용한다. (위예제 처럼) 

