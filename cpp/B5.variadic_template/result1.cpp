/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : result_using_variadic_template.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

/*
* type traits에서 배웠던 내용이랑 비교해보면 좋다. 
*/


int f(int a, double b) { return 0; }
int goo() {return 0;}


// 가변 인자 템플릿 기술을 사용해서 함수의 리턴 타입을 구하는 코드 입니다.
template<typename T> struct result
{
	typedef T type;
};

template<typename R, typename ... Types> struct result<R(Types...)> // 가변인자 함수 type => R(Types...) 이거 잘봐둬야함. 
{                                                                   // 보통 가변인자 함수는 void foo(Types ... args) 이런 모양
	typedef R type;
};

template<typename T> void foo(T& a) // 여기서 T는 int(int, double) 타입입니다.
{
	typename result<T>::type n;  

	cout << typeid(n).name() << endl;  // int 가 나와야 합니다.
}

int main()
{
	foo(f);
	foo(goo); //goo는 인자가 없는 함수지만, 이것도 가능
}

// 가변인자 함수 void foo(Types ... args) 는 인자가 있어도 되고 없어도 된다는 의미. 

// 함수의 정보를 구하는 traits만들기
// 1. primary template을 만들고 "typedef T type"을 제공한다. 
// 2. 함수 타입인 T 안에 있는 리턴 타입(double)을 얻을 수 있도록 부분 특수화 한다. 
//    - T => R(A1,A2)
// 3. 인자 개수에 제한을 없애기 위해서 가변 인자 템플릿 사용.
//    - T => R(Types...)
