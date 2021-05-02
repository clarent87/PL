/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : concept2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
/* 컨셉 조건 만들어줌.. 이거 주석 삭제하면 컴파일시 컨셉 만족해서 잘 컴파일됨
	bool operator<(const Point&  p)
	{
		return x < p.x;
	}
*/
};

// 1. concept 만들기
template<typename T> 
concept bool LessThanComparable = requires(T a, T b) // ab 는 같은 타입이어야 하고, 컨셉의 이름은 LessThanComparable return은 bool
{
	{ a < b } -> bool; // 비교연산이 가능해야 하고 return은 bool이어야 한다. 
};

// 2. concept적용,,템플릿 함수 return 앞에 requires와 함꼐 만든 컨셉 써준다.
//    즉, template 만들떄 concept 표기법
// template<typename T> requires LessThanComparable<T>
// T Min(T x, T y)
// {
// 	return (y < x) ? y : x;
// }

// 2_1. 또는 아래와 같이 함수 뒤에 써도됨
// template<typename T> 
// T Min(T x, T y) requires LessThanComparable<T>
// {
// 	return (y < x) ? y : x;
// }

// 2_2. 또는 제일 편한게 아래와 같이 정의 하는것.
//      인터페이스 포인터? 와 유사한 형태 라는데?
LessThanComparable Min(LessThanComparable x, LessThanComparable y)
{
	return (y < x) ? y : x;
}
// 앞으로 c++20이 되면 템플릿 코드가 위처럼 바뀔가능성이 크다함

int main()
{
	Point p1, p2;
	Min(p1, p2);
}

// 컴파일은
// g++ concept2.cpp -fconcepts