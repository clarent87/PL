/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : PackExpansion1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int print(int a)
{
	cout << a << ",";
	return 0;

}

template<typename ... Types> void foo(Types ... args) 
{
	// print(args); // 당연 error,
	// print(args...); // print(1,2,3) 인데 print는 parameter가 하나인 함수.. 따라서 error
	// print(args)...; // print(1), print(2), print(3) 으로 풀리긴하지만 parameter pack은 사용할수 있는 위치가 한정적이다. 
					   // 따라서 error
					   // 강사는 여기서 이걸 전역적으로 expansion하고 있다고 표현함.. 근데 전역 아니지 않나?

	int x[] = { args... }; // { 1,2,3 }, [*] 이게 list 초기화(comma 초기화).. 기본적으로 배열의 초기화 구문인데 c++11에서 여러곳에 쓰이게 된듯?
	int x[] = { print(args)... }; // 이건 가능, 이렇게 하면 print에 의해 값이 화면에 출력되고, return값이 배열의 초기화 값이됨
								  // { print(1),print(2),print(3) }
								  // 이게 가능한 이유는 list 초기화가 필요한 공간이었기 떄문, 즉 ,(comma)로 초기화 되는거..
							      // foo() 호출시 {}가 되는데 배열은 이렇게 아무것도 없는 것으로 초기화 할수는 없다. 
								  // 따라서 아래 처럼 0을 배열의 첫번째 값으로 넣어준다. 
	int x[] = { 0, print(args)... }; // 근데 이것도 문제 인게.. print의 선언이 return이 void였다면..
									 // { 0,void } 가 되니까 에러.. 
									 // 따라서 최종적으로 아래와 같이 해주면 에러 없이 모든게 통과된다. 
	int x[] = { 0, (print(args),0)... };
				// { 0, (print(1),0), (print(2),0), (print(3),0) };
				// ( print(1),0 ) 표현은 c에서 print(1)를 실행하고 전체식 ( print(1),0 )의 return은 0으로 한다는 의미

	// 또는~ 아래껄 쓴다.
	initializer_list<int> e = { (print(args),0)... }; // initializer_list는 empty 배열이 가능하므로.. 

	// c++17에서는 이것보다 더 깔끔하게 구현가능.. 뒤에 나오는 fold ex~를 이용.
}

int main()
{
	foo(1, 2, 3); // args : 1, 2, 3
	foo();
}
// Pack Expansion
// 1. "Paramter Pack을 사용하는 패턴"... => 패턴(e1), 패턴(e2), 패턴(e3)
//    즉 위 예와 같다. (ex: (++args)... 에서 (++args)가 "Paramter Pack을 사용하는 패턴" 이므로,, =>  ++E1, ++E2, ++E3 가됨)
// 2. ...의 위치에 주의 한다. 
//    - goo(hoo(args...)) => goo(hoo(e1,e2,e3))
//    - goo(hoo(args)...) => goo(hoo(e1),hoo(e2),hoo(e3))
// 3. Pack Expansion은 '함수 호출의 인자' 또는 'list 초기화를 사용한 표현식'에서만 사용할 수 있다. 











