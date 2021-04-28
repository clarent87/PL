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

int f(int a, char c) { return 0; }

// primary template
template<typename T> struct result
{
	typedef T type; // [*] 의도적으로 제거해서 함수타입이 안오는경우 error가 나게 할수도 있다. 
};

// 핵심 !!: 부분 특수화을 통해서 원하는 타입을 구할수 있도록 타입 분할을 한다.
// 아래는 함수type이 return에 인자가2개인 것만 가능
template<typename R, typename A1, typename A2> struct result<R(A1, A2)>
{
	typedef R type;
};

template<typename T> void foo(T& t)  // T : int(int, char)
{
	typename result<T>::type n; 

	cout << typeid(n).name() << endl;
}

int main()
{
	foo(f);
	result<int>::type ret; // [*] 이경우는 위처럼하면 ret은 그냥 primary에 의해 int가 나옴..
						   // [*] 이런경우 error를 내주고 싶다면? primary version의 type을 삭제함. 
}

// *함수의 정보를 구하는 traits만들기
// 1. primary template을 만들고 "typedef T type"을 제공한다. (c++11 using도 사용가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할"한다. 
// 3. 부분 특수화를 통해서 함수타입( int(int,char) ) 모양인 T를 리턴 타입 (int)와 나머지 (인자타입)으로 분리한다. 
//     - 위의 R(A1,A2) 처럼.. T를 대체함
// 4. primary template의 "typedef T type"이 필요없는 경우는 제거해도 된다. 
