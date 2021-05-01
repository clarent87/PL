/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : PackExpansion1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int a, int b, int c)
{
	cout << a << ", " << b << ", " << c << endl;
}

int hoo(int a) { return -a; }

// Pack Expansion : (pack을 사용하는 패턴)...
template<typename ... Types> void foo(Types ... args) // args : 1,2,3 
{
	//int ar[] = { args... }; // 1, 2, 3

	//int ar[] = { (++args)... }; // ++E1, ++E2, ++E3,  즉 ++1, ++2, ++3
								  //  (++args)패턴으로 풀린다는 것
	//int ar[] = { hoo(args...) }; // hoo(1,2,3) error, 이건 당연..

	int ar[] = { hoo(args)... }; // { hoo(1), hoo(2), hoo(3) }

	goo(args...); // goo( 1, 2, 3)
	goo(hoo(args)...); // goo( hoo(1), hoo(2), hoo(3))
	goo(hoo(args...)); // goo( hoo( 1,2,3)) // error


	// c++ 11에서 나온 range for 다른 언어의 foreach와 같음
	for (auto n : ar)
		cout << n << endl;
}

int main()
{
	foo(1, 2, 3);
}
// Pack Expansion
// 1. "Paramter Pack을 사용하는 패턴"... => 패턴(e1), 패턴(e2), 패턴(e3)
//    즉 위 예와 같다. (ex: (++args)... 에서 (++args)가 "Paramter Pack을 사용하는 패턴" 이므로,, =>  ++E1, ++E2, ++E3 가됨)
// 2. ...의 위치에 주의 한다. 
//    - goo(hoo(args...)) => goo(hoo(e1,e2,e3))
//    - goo(hoo(args)...) => goo(hoo(e1),hoo(e2),hoo(e3))












