/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : xget2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename ... Types> struct xtuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types> struct xtuple<T, Types...> : public xtuple<Types...>
{
	T value;
	xtuple() = default;
	xtuple(const T& a, const Types& ... args) : value(a), xtuple<Types...>(args...) {}

	static constexpr int N = xtuple<Types...>::N + 1;
};
//----- 위 까지는 지난 강의의 xtuple만든내용

int main()
{
	//xtuple<			  >        // primary template
	//xtuple<			  double>  // 3.4을 보관
	//xtuple<		char, double>  // 'A'을 보관
	xtuple<int, char, double> t3(3, 'A', 3.4); // 3을 보관

	cout << t3.value << endl;

	cout << static_cast<xtuple<char, double>&>(t3).value << endl; // 'A'
																  // t3를 기반클래스로 형변환해서 value를 뽑음 
	cout << static_cast<xtuple<double>&>(t3).value << endl;       // 3.4

//	double d = xget<2>(t3);
}
// 위 내용에 따라 xget의 기본형태를 그리면 다음과 같음
/*
template<int N, typename T> // T는 튜플
튜플 T의 N번째 요소의 타입&
xget(T& tp)
{
	return static_cast<tp의 N번쨰 기본 타입&>(tp).value;
}
*/


// tuple의 요소에 접근하는 get 만들기

// 세번째 기반클래스. tuple<> stucture -> end recursive (primary template이 호출됨)
// 두번째 기반클래스. tuple<char> stucture -> char value 저장 
// 첫번째 기반클래스. tuple<double,char> stucture -> double value 저장 
// child.            tuple<int,double,char> stucture -> int value 저장 

// 즉
// 1. tuple의 0번째 요소는 자기 자신이 보관한다. 
// 2. tuple의 N번쨰 요소는 N번째 기반 클래스가 저장한다. 


// [*] 기타
// xget1.cpp도 마찬가지고 참조리턴에 대해 이해할 필요가 있으
// 위에서 "튜플 T의 N번째 요소의 타입&"란 것도 	"T value;"의 참조 리턴이라는 말이고. static_cast에서 참조도 참조 리턴과 유사한 개념같다. 
// 즉, value가 int이면 return value의 타입은 당연히 int인데, 해당 함수의 형태가 int& foo() 라면 return (int&) value 처럼 형변환 되어 
// 나가는 거라는 생각이 드네.. 즉 값복사된 임시객체가 나가는게 아니라. value의 객체 주소가 넘어가는 형태 (value가 int가 아닌 객체라고 한다면.. )




