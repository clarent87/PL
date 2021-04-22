/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : type_deduction2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost::typeindex;

// 규칙 2. 템플릿 인자를 참조 타입(T& a)으로 받을때
//		   인자의 reference 속성을 제거하고 T를 결정, const, volatile 속성은 유지 된다. (원본을 가르키는 의미이기 때문에 원본 속성 유지)
//         cvr에서 r만 제거되고 cv는 유지, 값 타입일떄는 cvr모두 제거
template<typename T> void foo(T& a)
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

	foo(n); // int			T : int			a : int&
	foo(r); // int&			T : int			a : int&
	foo(c); // const int	T : const int   a : const int& 
			// a가 int&는 되서는 안되는게 c++ 에서 const를 일반 참조로 가리킬수 없기 때문
			// 이게 가능하면 const 값을 변경 할 수 있다는 거니가.. 따라서 int&가 아닌 const int&여야한다. 
	foo(cr);// const int&   T : const int	a : const int&


}
