/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : type_deduction3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost::typeindex;

// 규칙 2. 템플릿 인자를 참조 타입으로 받을때
//		   인자의 reference 속성을 제거하고 T를 결정, const, volatile 속성은 유지 된다.
// (핵심) reference type은 원본을 그대로 가리켜야 한다는 사실이 중요. 그렇다면 cv는 유지되어야 함을 알수 있음
//        const가 붙는경우 아래 예에서 T에 const를 떼도 a가 원본을 정확히 가리킬수 있기 때문에 괜찮을 것으로 보임
//        따라서 컴파일러가 T를 int로 결정
template<typename T> void foo(const T& a)
{
	--a;

	cout << "T : " << type_id_with_cvr<T>().pretty_name() << endl;
	cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

int main()
{
	int		n = 10;
	int&    r = n;
	const int c = n;
	const int& cr = c;

	foo(n); // int			T : int		a : const int&
	foo(r); // int&			T : int		a : const int&
	foo(c); // const int	T : int		a : const int&
	foo(cr);// const int&   T : int		a : const int&

	// 위에서 const는 제거해서 T를 결정해도 된다, 왜냐면 foo 의 a에 이미 const가 있어서.

}
