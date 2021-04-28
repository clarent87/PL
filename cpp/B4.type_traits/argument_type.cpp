/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : result_traits.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

double hoo(int a, char c) { return 0; }

// primary template
// 배운대로 만듬
template<typename T, int N> struct result
{
	// typedef T type; 
};

/* 이렇게 만들면 ? 를 채울수가 없음. .
template<typename R, typename A1, typename A2, int N> struct result<R(A1, A2), N>
{
	typedef ? type;
};
*/

template<typename R, typename A1, typename A2> struct result<R(A1, A2), 0>
{
	typedef A1 type;
};

template<typename R, typename A1, typename A2> struct result<R(A1, A2), 1>
{
	typedef A2 type;
};

template<typename T> void foo(T& t)  // T : double(int, char)
{
	typename result<T,0>::type n; // 함수의 첫번째 인자 type으로 n을 생성.

	cout << typeid(n).name() << endl;
}

int main()
{
	foo(hoo);
}

// *함수의 정보를 구하는 traits만들기
// 1. primary template을 만들고 "typedef T type"을 제공한다. (c++11 using도 사용가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할"한다. 
// 3. 부분 특수화를 통해서 함수타입( int(int,char) ) 모양인 T를 리턴 타입 (int)와 나머지 (인자타입)으로 분리한다. 
//     - 위의 R(A1,A2) 처럼.. T를 대체함
// 4. primary template의 "typedef T type"이 필요없는 경우는 제거해도 된다. 