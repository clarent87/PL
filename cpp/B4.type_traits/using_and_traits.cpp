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

// using은 c++ 11부터 추가됨

// C++14 의 공식 표준 (c++14이상에서는 이걸 많이씀)
//template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;

// C++17 (variable template을 이용한 기법)
//template<typename T> inline constexpr bool is_pointer_v = is_pointer<T>::value;

template<typename T> void foo(T a)
{
	//typename remove_pointer<T>::type n; // n : int
	remove_pointer_t<T> n; // 위와 동일한 표현.

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