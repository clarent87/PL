/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : variadic2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

void goo(int n, double d, const char* s)
{

}
// Parameter Pack
template<typename ... Types> void foo(Types ... args)
{
	// args : Parameter Pack
	cout << sizeof...(args) << endl;  // 3
	cout << sizeof...(Types) << endl; // 3, type의 갯수도 알아볼수 있다. 

									  //goo(args); // error.(파라메터 팩 자체는 함수인자가 될수 없다.) 
	goo(args...); // args... : pack 안의 요소들을 , 를 사용해서 나열해 달라. 
				  // goo( 1, 3.4, "aaa")
				  // args... : Pack Expansion 이라고 한다. 
				  // 사실 정확한 의미는, args에 있는 내용을 ,를 사용해서 풀어달라는것 즉, 예제 처럼 1, 3.4, "aaa" 이렇게 풀어달라는것
}

int main()
{
	foo();
	foo(1);
	foo(1, 3.4, "aaa"); // Types : int, double, const char*  
						// args : 1, 3.4, "aaa"
}
// 핵심개념
// 1. Parameter Pack
// 2. sizeof...(args) : Parameter Pack에 있는 요소의 갯수
// 3. Pack Expansion