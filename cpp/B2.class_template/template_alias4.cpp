/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : template_alias4.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <set>
#include <functional>
using namespace std;

template<typename T> using SET = set<T, greater<T>>;

int main()
{
	SET<int> s1;

//	set<int,    greater<int> > s1;
	set<double, greater<double> > s2;

	s1.insert(10); // <, less 함수객체
	s1.insert(20); 
	s1.insert(15);

	for (auto n : s1)
		cout << n << endl;
	
}

// 이부분 강의 안함. 책에는 내용이 있고. using의 유용성을 얘기하는 예제
