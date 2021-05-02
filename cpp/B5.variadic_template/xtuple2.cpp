/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : xtuple2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template <typename... Types>
struct xtuple
{
	static constexpr int N = 0;
};

// Step 2. 하나의 값을 보관할수 있도록 부분 특수화
// 근데 현재까지는 하나의 요소만 저장 가능
template <typename T, typename... Types> // [*] 첫번째가 어떤 type이 오면 이게 쓰임 ( 사실생 primary가 쓰일일이 인자가 없을떄 빼곤 없을듯) -> 이거 신기함.
struct xtuple<T, Types...>
{
	T value;
	xtuple() = default;				 // default생성자도 하나 만들어 주고
	xtuple(const T &a) : value(a) {} // 값도 전달받아서 초기화 할수 있도록

	static constexpr int N = 1;
};

int main()
{
	xtuple<> t0;
	xtuple<int> t1(3); // 특수화 버전의 템플릿이 쓰임
	xtuple<int, char, double> t3(3); // 특수화 버전의 템플릿이 쓰임
}

// tuple 만들기. 
// 1. 가변 인자 템플릿을 사용해서 primary template을 만든다. 
// 2 . 1개의 요소를 보관할 수 있도록 부분 특수화를 사용한다. 
