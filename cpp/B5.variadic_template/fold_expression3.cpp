/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : fold_expression3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename ... Types> void foo(Types ... args)
{
	// I : initial value
	// I + ... + args;  // (((I + E1) + E2) + E3)

	(cout << ... << args); // ((( cout << 1) << 2) << 3) 
						   // 앞 내용의 binary left fold
}
int main()
{
	foo(1, 2, 3);

	//	(((cout << 1) << 2) << 3) << endl; // 123
		// [*] (cout << 1) 은 1출력후 return 값은 cout이다.. 그러니까 위같은 코드가 가능.. 

}

// 즉 초기값이 객체이고 연산자 재정의가 되어 있으면, fold expenssion으로 많은 일들을 할 수 있다. 