/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : fold_expression1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename ... Types> void foo(Types ... args)
{
	int x[] = { args... }; // PATTERN...

	int n = (args + ...); // pack op ... ( fold expenssion쓸땐 반드시 괄호 줘야함.)
						  // E1 op ( E2 op ( E3 op ( E4 op E5) ) )
						  // 1 + (2 + (3 + (4 + 5)))

	int n = (... + args  );  // ((1+2)+3)+4
	int n = (args + ... + 10);  // 1 + (2 + (3 + (4 + (5 + 10))))
	int n = (10+ ... + args); // (((10+1)+2)+3)+4
	cout << n << endl;
}
int main()
{
	foo(1, 2, 3, 4, 5);
}

// fold expression
// 1. 이항 연산자를 사용해서 parameter pack 안에 있는 요소에 연산을 수행하는 문법
// 2. parameter pack의 이름에서 ...을 붙이지 않고 사용한다. ( 그리고 연산자도 함께)
//   - args... : pack expenssion
//   - args + ... : fold expenssion
// 3. 4가지 형태 가능
//   - unary right fold : (args op ...) ==> E1 op ( E2 op ( E3 op E4))
//   - unary left fold  : ( ... op args) ==> ((E1 op E2) op E3) op E4
//   - binary right fold : (args op ... op init) ==> E1 op ( E2 op ( E3 op (E4 op init)))
//   - binary left fold : ( init op ... op args) ==> (((init op E1) op E2) op E3) op E4