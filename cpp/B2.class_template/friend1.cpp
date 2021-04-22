/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : friend1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	friend ostream& operator <<(ostream& os, const Point& p);
};

ostream& operator <<(ostream& os, const Point& p)
{
	return os << p.x << ", " << p.y;
}
int main()
{
	Point p(1, 2);
	cout << p << endl; // 이렇게 하기 위해서 추출연산자(<<) 재정의를 진행한다. ( c++ 기본이라고함.. ;)
}

