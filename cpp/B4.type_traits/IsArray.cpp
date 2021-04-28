/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : IsArray.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
//			변수이름    타입

// int a;		a		int
// int* p;		p		int*
// int x[10];	x		int[10]	=> T[N]

// int[] : 옆형태는 크기를 알수 없는 배열 타입 

template<typename T> struct IsArray
{
	static const int size = -1;
	static const bool value = false;
};

// 크기가 있는 배열인경우
template<typename T, size_t N> struct IsArray<T[N]>
{
	static const int size = N;
	static const bool value = true;
};

// 크기를 알수 없는 배열인 경우 부분 특수화는 아래와 같이 진행
// IsArray<int[]>::value 쓰면 true가 나오게 됨.
template<typename T> struct IsArray<T[]>
{
	static const int size = N;
	static const bool value = true;
};

// 주의 점 T&가 아닌 T로 쓰면 배열은 타입 pointer가됨.. (앞쪽 type deduction에 나옴)
// 강의 예제에서는 const T& 대신 T&만씀
template<typename T> void foo(const T& a) // int[10]
{
	if (IsArray<T>::value)   // 위 코드를 수정해서 IsArray<>만들어 보세요.. 1차 배열만 고려해 보세요
		cout << "배열 입니다. 크기는 " << IsArray<T>::size << endl;
	else
		cout << "배열이 아닙니다." << endl;

	// 보통 함수 인자로 배열을 주는경우 크기도 파라메터로 줘야하는데, 위 개념을 이용하면 배열의 크기를 안줘도 알수 있음
	// 위 개면으로는 1차원 배열의 크기만 알수있는데, c++ 11표준의 extent<T,N> 이용하면 N차 배열의 크기 알수있음
}

int main()
{
	int x[10] = { 1,2,3 };
	foo(x);
}


// * is_array 만들기
// 이런건 항상 구조체로 만드는 것이다. ( is_array, is_pointer)
// 1. primary tempalte에서는 false를 리턴 (value=false)
// 2. 배열 모양으로 부분 특수화 모양을 만들고 true 리턴(value=true)
// 3. 타입을 정확히 알아야 한다. 
	// int x[3] : 에서 x는 변수 이름, 변후 이름을 제외한 나머지 요소(int[3])은 타입이다. 
// 4. unknown size array type(T[])에 대해서도 부분 특수화를 제공한다. 

// *배열의 크기
// 1. 배열의 크기도 구할 수 있다. 
//    - c++11 표준 - extent<T,0>::value // 여기서 0은 차원. 
// 2. 함수 템플릿 의 인자를 값(T)으로 만들 경우 배열을 전달하면 T의 타입은 배열이 아닌 포인터로 결정된다. 