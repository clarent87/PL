/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : generic_copy_constructor2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


#include <iostream>
using namespace std;

template<typename T> class complex
{
	T re;
	T im;
public:
	complex(T a = T(), T b = T()) : re(a), im(b) {}
	
	// 복사 생성자 모양 1.
	//complex(const complex<T>&);		// complex<double> c3 = c1; 일때 c1은 반드시 complex<double> 이어야 한다.
										// complex(const complex& c); 모양은 이렇게 해도 된다.( 앞서 설명 했듯.)

	// 복사 생성자 모양 2.
	//complex(const complex<int>&);		// complex<double> c3 = c1; 일때 c1은 반드시 complex<int> 이어야 한다.
										// 즉, 복사생성자는 complex<int> 버전 하나있는거,, (모양1, default 복사생성자는 이제 안만들어줌)
										// 강사의 예에서는 complex<short>이런게 문제라고 했는데, complex<double>도 이제는 문제일듯.


	// 복사 생성자 모양 3. 일반화된 복사 생성자
	// "U가 T로 복사 가능하다면 complex<U> 는 complex<T> 로 복사 가능해야 한다."
	template<typename U> complex(const complex<U>&);		// complex<double> c3 = c1; 일때 c1은 complex<U> 이므로, 임의의 타입의 complex 이다.

	// template<typename U> friend class complex; // [*] 여기서 U는 실제로 쓰지 않고 있으니까, 빼도된다. 즉 아래처럼 쓸수있는것.
	template<typename> friend class complex;
};

template<typename T> template<typename U>
complex<T>::complex(const complex<U>& c) : re(c.re), im(c.im) // [*] 복사 생성자도 생성자니까, 초기화 리스트로 초기화를 쓰는게 좋다.
{
}

int main()
{
	complex<int> c1(1, 2); // ok
	complex<int> c2 = c1;  // ok. 복사 생성자
	complex<double> c3 = c1; // error. c1, c3 는 다른 타입이다.!

	// 핵심정리
	// - Complex<int> 와 Complex<double>은 다른 타입인다. 
	// - 복사 생성자는 같은 타입으로 초기화 될 때 사용된다. 
	// 일반화된 복사 생성자
	// 1. 클래스 템플릿의 멤버 함수 템플릿으로 구현하는 복사 생성자.
	// 2. U(int)가 T(double)로 복사(대입) 가능하다면 Complex<U>도 Complex<T>에 복사(대입)가능해야 한다. 
	// 3. friend class로 선언 되어야한다. 
}