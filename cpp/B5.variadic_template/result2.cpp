/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : result_using_variadic_template.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
#include <type_traits>
using namespace std;

/*
* type traits에서 배웠던 내용이랑 비교해보면 좋다. 
*/


template<typename T> struct result
{
	// typedef T type; // 1. T가 함수가 아니었을때 error를 내주기 위해 제거

	// 2. static_assert를 이용하면 error 메시지를 이쁘게 낼수 있다. 
	static_assert(is_function<T>::value, "error"); 
		// 원래 assert는 항상 참이기를 바라는 코드. 즉 function이면 참이니까 에러가 나지 않는다. 
		// 근데 이 코드에서 여기 까지 왔다는 것은 함수가 아니란 얘기.
};

// [*] 아래처럼 primary의 선언만 만드는 것이 가장 많이 쓰인다. (primary의 선언만 있으면 당연 에러지만, 부분특수화가 있다면 갠춘)
//     이렇게 primary의 선언만 있는 코드들이 꽤 많다고 함

// template<typename T> struct result;

template<typename R, typename ... Types> struct result<R(Types...)> 
{                                                                   
	typedef R type;
};

template<typename T> void foo(T& a)  
{
	typename result<T>::type n;  

	cout << typeid(n).name() << endl;  
}

int main()
{
	int n = 0;
	foo(n);
}

// traits 를 잘 못 사용할 때 처리 방법
// 1. "typedef T Type"을 제공하지 않는다. 
// 2. static_assert()를 사용해서 에러 메시지를 출력
// 3. primary template을 선언만 제공한다. 