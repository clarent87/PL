/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : using_traits.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// type_traits를 사용하는 방법
#include <type_traits>     // 이 헤더가 필요하고!

template<typename T> void goo(T a, true_type) { cout << "포인터" << endl; }
template<typename T> void goo(T a, false_type) { cout << "포인터 아님" << endl; }

template<typename T> void foo(T a)
{
	// 1. traits<T>::value를 사용하는 방식 - 결국 if문
	//    단점 : 포인터일때라도 "*a" 등의 표현식은 사용할수 없다. if문은 실행시간 분기문이므로!!
	if (is_pointer<T>::value)
		cout << "포인터" << endl; // *a 식의 표현을 사용할수 없다.
	else
		cout << "포인터 아님" << endl;


	// 2. 함수 오버로딩 사용 - 컴파일 시간 분기문, 포인터 일때 *a 등의 표현 사용가능

	goo(a, is_pointer<T>());
}




int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}

// 템플릿을 만들떄 타입을 조사하는 방법. 
// 1. <type_traits> 헤더 포함
// 2. ::value값을 조사하는 방법.(is_pointer<T>::value)
//    - if 문 사용시에는 *v등의 표현을 사용할 수 없다. 
//    - c++17의 if constexpr 사용시에는 *v 사용할 수 있다. 
//    - c++17 부터는 is_pointer_v<T> 표현식도 제공
// 3. true_type/false_type을 사용한 함수 오버로딩



