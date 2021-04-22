/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : friend3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename T> 
void foo(T a) 
{
	cout << "T" << endl;
}

// void foo(int a){
// 	cout << "int" << endl;
// }

// Q. 선언만 있는경우, template버전을 이용해 정의를 만들까? NO!!!
void foo(int a); // { cout << "int" << endl; }

int main()
{
	foo(3); // link error.

}

// 핵심 정리
// 1. 함수 템플릿 보다는 일반 함수가 우선해서 선택된다. (exactly matching)
// 2. 함수 템플릿 있어도 동일한 타입의 인자를 가지는 일반 함수의 선언만 있으면 link 에러가 발생한다. 
//    즉, void foo(Point<int> a) 가 선언되어 있다면, template<typename T> void foo(Point<T> a) 가 정의되어 있어도 link error
