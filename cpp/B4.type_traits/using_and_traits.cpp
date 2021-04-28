/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : using_and_traits.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

// using�� c++ 11���� �߰���

// C++14 �� ���� ǥ�� (c++14�̻󿡼��� �̰� ���̾�)
//template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;

// C++17 (variable template�� �̿��� ���)
//template<typename T> inline constexpr bool is_pointer_v = is_pointer<T>::value;

template<typename T> void foo(T a)
{
	//typename remove_pointer<T>::type n; // n : int
	remove_pointer_t<T> n; // ���� ������ ǥ��.

	//if ( is_pointer<T>::value)
	if (is_pointer_v<T>)
	{

	}
}

int main()
{
	int n = 10;
	foo(&n);
}