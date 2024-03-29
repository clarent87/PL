﻿/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : factorial.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// template meta programming
template<int N> struct factorial
{
	//int value = 10; // [*] c++ 표준 문법에서는 구조체 안에서 변수 선언하면서, 초기값줄수 없었음
					  // 그래서 예전에는 구조체 안에 초기값을 줄수 있는 유일한 문법인 enum을 많이 씀 
					  // 요즘에는 static constexpr int 이렇게 쓰면됨
	//enum { value = N * factorial<N-1>::value };
	static constexpr int value = N * factorial<N - 1>::value;

	// [*] 옛날에는 메타 프로그래밍 많이 썻는데, 요즘에는 c++11 나오고 constexpr를 대신해서 많이 씀

};
// 재귀의 종료를 위해 특수화 문법 사용
template<> struct factorial<1>
{
	//enum { value = 1 };
	static constexpr int value = 1;
};

int main()
{
	int n = factorial<5>::value; // 5 * 4 * 3 * 2 * 1  => 120 
	//			5 * f<4>::v
	//				4 * f<3>::v
	//					3 * f<2>::v
	//						2 * f<1>::v
	//							1	

	cout << n << endl;
}

