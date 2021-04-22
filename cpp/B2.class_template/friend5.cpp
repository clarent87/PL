/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : friend5.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


#include <iostream>
using namespace std;
// 해결책 1.
// 클래스와 friend 함수
// 1 : 1, 
// 1 : N, 
// N : 1, 
// N : N   =>
template<typename T> class Point
{
	T x, y;
public:
	Point() : x(0), y(0) {}
	Point(T a, T b) : x(a), y(b) {}
	
	// 함수 템플릿이 아님..
	//friend ostream& operator <<(ostream& os, const Point<T>& p);

	// 함수 템플릿.
	template<typename U>
	friend ostream& operator <<(ostream& os, const Point<U>& p); // [*] friend 위치는 함수 이름 앞.
};

// 함수 템플릿
template<typename T>
ostream& operator <<(ostream& os, const Point<T>& p)
{
	return os << p.x << ", " << p.y;
}

int main()
{
	Point<int> p(1, 2);
	cout << p << endl;
}

// 클래스 템플릿 안데 friend 함수를 선언하는 방법
// 방법1. friend 함수 선언시에 함수 자체를 템플릿 모양으로 선언
//        > 이경우 class와 friend함수간 N:N관계가됨 (아래 처럼.)
//        > class Point<int>  operator<<(Point<T>) {}
//        > class Point<int>  operator<<(Point<int>) {}
//        > class Point<int>  operator<<(Point<double>) {}
//        > class Point<double>  operator<<(Point<T>) {}
//        > class Point<double>  operator<<(Point<int>) {}
//        > class Point<double>  operator<<(Point<double>) {}

