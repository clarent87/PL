/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : xtuple3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;


template<typename ... Types> struct xtuple
{
	static constexpr int N = 0;
};

// Step 3. N개를 보관하는 tuple
template<typename T, typename ... Types> struct xtuple<T, Types...> : public xtuple<Types...> // 단순히 자신을 상속만 하면 일단 모든게 저장됨 ( 사실 자신 상속은 아님.. 왜냐면 템플릿이니까 각각 인자수에 따른 class가 생성됨)
{
	T value;
	xtuple() = default;
	xtuple(const T& a, const Types& ... args) : value(a), xtuple<Types...>(args...) {}
	// 인자를 받을땐 상수 참조가 좋기때문에  const Types& ... args를 썻는데 c++11의 perfect forwording으로 받는게 더좋다. 
	// args...는 함수의 인자로 전달해야 하기 때문에 pack expanssion을 사용한 모양
	// Types...는 type expanssion
	
	static constexpr int N = xtuple<Types...>::N + 1;
};


int main()
{
	xtuple<>		          t0;
	xtuple<int, char, double> t3(3, 'A', 3.4);
}


// tuple 만들기. 
// 1. 가변 인자 템플릿을 사용해서 primary template을 만든다. 
// 2 . 1개의 요소를 보관할 수 있도록 부분 특수화를 사용한다. 
// 3. 상속을 사용해서 N개를 보관할 수 있게 만든다. 
// 4. 생성자등 필요한 멤버를 추가한다. 

// 상속을 이용한 모양을 설명하면 다음과 같다.
// 첫째의 parent class가 둘째, 둘째의 parent class가 셋쨰

// 넷째. tuple<> stucture -> end recursive (primary template이 호출됨)
// 셋째. tuple<char> stucture -> char value 저장 
// 둘째. tuple<double,char> stucture -> double value 저장 
// 첫째. tuple<int,double,char> stucture -> int value 저장 