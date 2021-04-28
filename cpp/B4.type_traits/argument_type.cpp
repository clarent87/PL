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
// ����� ����
template<typename T, int N> struct result
{
	// typedef T type; 
};

/* �̷��� ����� ? �� ä����� ����. .
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
	typename result<T,0>::type n; // �Լ��� ù��° ���� type���� n�� ����.

	cout << typeid(n).name() << endl;
}

int main()
{
	foo(hoo);
}

// *�Լ��� ������ ���ϴ� traits�����
// 1. primary template�� ����� "typedef T type"�� �����Ѵ�. (c++11 using�� ��밡��)
// 2. �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���� �� �ֵ��� "T Ÿ���� ����"�Ѵ�. 
// 3. �κ� Ư��ȭ�� ���ؼ� �Լ�Ÿ��( int(int,char) ) ����� T�� ���� Ÿ�� (int)�� ������ (����Ÿ��)���� �и��Ѵ�. 
//     - ���� R(A1,A2) ó��.. T�� ��ü��
// 4. primary template�� "typedef T type"�� �ʿ���� ���� �����ص� �ȴ�. 