/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : traits_concept.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename T> void printv(T a)
{
	if (T is Pointer) // 이런걸 조사 하고 싶을 때 쓰는 기술이 type traits
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}


int main()
{
	int n = 3;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}


