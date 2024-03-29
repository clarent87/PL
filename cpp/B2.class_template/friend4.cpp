﻿/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : friend4.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
/*
template<typename T> class Point
{
	T x, y;
public:
	Point() : x(0), y(0) {}
	Point(T a, T b) : x(a), y(b) {}
	friend ostream& operator <<(ostream& os, const Point<T>& p);
};
*/
// 컴파일러가 생성한 코드..
class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	friend ostream& operator <<(ostream& os, const Point<int>& p); // [*] 즉, 함수 템플릿이 아니다. (중요 point)
};


// [*] 함수 템플릿의 정의, 즉 class Point의 friend 함수의 정의와는 별개 이다. ( firend3.cpp 이슈)
template<typename T>
ostream& operator <<(ostream& os, const Point<T>& p)
{
	return os << p.x << ", " << p.y;
}

int main()
{
	Point<int> p(1, 2);
	cout << p;// operator<<(cout, p) => operator<<(ostream, Point<int> )
}




