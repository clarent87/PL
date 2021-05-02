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
* type traits���� ����� �����̶� ���غ��� ����. 
*/


int f(int a, double b) { return 0; }
int goo() {return 0;}


// ���� ���� ���ø� ����� ����ؼ� �Լ��� ���� Ÿ���� ���ϴ� �ڵ� �Դϴ�.
template<typename T> struct result
{
	typedef T type;
};

template<typename R, typename ... Types> struct result<R(Types...)> // �������� �Լ� type => R(Types...) �̰� �ߺ��־���. 
{                                                                   // ���� �������� �Լ��� void foo(Types ... args) �̷� ���
	typedef R type;
};

template<typename T> void foo(T& a) // ���⼭ T�� int(int, double) Ÿ���Դϴ�.
{
	typename result<T>::type n;  

	cout << typeid(n).name() << endl;  // int �� ���;� �մϴ�.
}

int main()
{
	foo(f);
	foo(goo); //goo�� ���ڰ� ���� �Լ�����, �̰͵� ����
}

// �������� �Լ� void foo(Types ... args) �� ���ڰ� �־ �ǰ� ��� �ȴٴ� �ǹ�. 

// �Լ��� ������ ���ϴ� traits�����
// 1. primary template�� ����� "typedef T type"�� �����Ѵ�. 
// 2. �Լ� Ÿ���� T �ȿ� �ִ� ���� Ÿ��(double)�� ���� �� �ֵ��� �κ� Ư��ȭ �Ѵ�. 
//    - T => R(A1,A2)
// 3. ���� ������ ������ ���ֱ� ���ؼ� ���� ���� ���ø� ���.
//    - T => R(Types...)
