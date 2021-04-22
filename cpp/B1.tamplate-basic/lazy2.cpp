/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : lazy2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

template<typename T> void foo(T a)
{
	*a = 10; // a가 값 타입으로 결정되면 역참조 에러남. (당연 주소여야 *연산이 가능하니까)
}

int main()
{
	//foo(0); // error

	if (false)	// if문은 실행시간 조건문이므로
		foo(0);	//  이 코컴파일시에드는 사용된다고 판단.

	if constexpr(false) // C++17 static-if 문법
		foo(0);

}