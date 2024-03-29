/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : tuple_using_couple.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
template<typename T, typename U> struct couple
{
	T v1;
	U v2;
	enum { N = 2 };
};

// couple의 선형화 기술
struct Null {}; // empty class(struct), sizeof(Null) : 1  
				// 아무 멤버도 없지만 분명한 타입이다.
				// 1. 함수 오버로딩이나
				// 2. 템플릿 인자로 주로 활용

// 2개이상 5개 미만의 타입전달만 가능
// [*] c++ 11전에는 최대 10개 까지만 가능한 tuple을 제공하였음
// [*] c++ 11이후는 가변인자 템플릿이 가능해서 무한대까지 가능
template<typename P1 = Null,
	typename P2 = Null,
	typename P3 = Null,
	typename P4 = Null,
	typename P5 = Null> class xtuple : public couple<P1, xtuple<P2, P3, P4, P5, Null>> // 이부분이 핵심
{
};

// 2개를 저장하는 xtuple을 위한 부분 전문화
template<typename P1, typename P2>
class xtuple<P1, P2, Null, Null, Null> : public couple<P1, P2>
{
};


#include<iostream>
using namespace::std;
int main()
{
	//								  couple<short, long>  
	//						couple<char, xxtuple<s, l, Null, Null, Null>>
	//			couple<double, xtuple<c, s, l, Null, Null>>
	// couple<int, xtuple<d, c, s, l, Null>>
	xtuple<int, double, char, short, long> t5; // 상속 받은후 추가한것이 없으므로
											  // 부모와 모양이 같다. 부모만 알면 이 객체의 모양을
											  // 알수 있다.

	xtuple<int, int, int> t3;

	cout << sizeof t5  << endl; // c++에서는 구조체의 char 변수를 실제로는 4byte할당( 구조체 패딩 포함, 나머지도 해당 내용 고려해야함)
								// 이걸 잘 고려해야 크기를 알수 있음
}




