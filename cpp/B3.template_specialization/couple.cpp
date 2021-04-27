/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : couple.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std; 

template<typename T> void printN(const T& a) { 
	cout << T::N << endl; // [*] 기본적으로 컴파일러는 T::N의 N을 값으로 인식!! 중요!!
}


// 임의의 타입 2개를 보관하는 구조체 
template<typename T, typename U> struct couple
{
	T v1;
	U v2;

	static constexpr int N = 2;
};

// 2번째 인자가 recursive일때를 위한 부분전문화
template<typename A, typename B, typename C> struct couple<A, couple<B, C>> // c++ 템플릿은 인자로 자기자신을 보낼수 있음
{
	A         v1;
	couple<B, C> v2;
	static constexpr int N = couple<B, C>::N + 1; // 핵심!
};

// 1번째 인자가 recursive일때를 위한 부분전문화
template<typename A, typename B, typename C> struct couple<couple<A, B>, C>
{
	couple<A, B>  v1;
	C         v2;
	static constexpr int N = couple<A, B>::N + 1; // 핵심!
};

// 1,2번 인자 동시 특수화
template<typename A, typename B, typename C, typename D> struct couple<couple<A, B>, couple<C, D>>
{
	couple<A, B>  v1;
	couple<C, D>  v2;
	static constexpr int N = couple<A, B>::N + couple<C, D>::N; // 핵심!
};


int main()
{
	couple<couple<int, int>, couple<int, int>> d4; 
	// 이거 그냥 돌리면 에러남, 컴파일러 입장에서 1번 인자/2번인자 부분특수화중 뭘쓸지 몰라서..
	// 그래서 1,2번 인자에 동시에 특수화 한 버전이 필요 

	printN(d4); // 4나와야 합니다.
}




/*
int main()
{
	couple<couple<int, int>, int> d3;
	couple<couple<couple<int, int>, int>, int> d4;

	printN(d3); // 3
	printN(d4); // 4 나오게 해보세요
}
*/

/*
int main()
{
	couple<int, double> d2;
	couple<int, couple<int, int>> d3;
	couple<int, couple<int, couple<int, int>>> d4;

	printN(d2); // 2
	printN(d3); // 3 --> 부분특수화가 필요한 이유 3,4등의 값을 내주기 위해
	printN(d4); // 4
}
*/


