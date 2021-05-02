/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : xget3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


#include <iostream>
using namespace std;

template<typename ... Types> struct xtuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct xtuple<T, Types...> : public xtuple<Types...>
{
	T value;
	xtuple() = default;
	xtuple(const T& v, const Types& ... args) : value(v), xtuple<Types...>(args...) {}
	static constexpr int N = xtuple<Types...>::N + 1;
};
//--------------------------------------------- 

// xtuple_element_type
// 튜플 N번쨰 요소의 type을 구하는 것
// TP는 튜플을 의미함
template<size_t N, typename TP> struct xtuple_element_type;

// 0번째를 위한 부분특수화
template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>> // xtuple<TP, Types...> 요 형태 잘 봐둬야함
{
	typedef T type;
	typedef xtuple<T, Types...> tupleType;
};

// N번째를 위한 부분특수화
template<size_t N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::type      type;
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::tupleType tupleType;

	// 사실 typedef대신 using도 가능할듯.
	// 그리고 c++ 표준의 tuple_element에서는 기반클래스 type을 얻는 방식이 위의 tupleType 과 같은 방식은 아님 ( 더 복잡하다고 함)
};

// [*] 위를 이용 get 을 만들었다. 
template<size_t N, typename TP> 
typename xtuple_element_type<N, TP>::type& xget(TP& tp)
{
	return static_cast<typename xtuple_element_type<N, TP>::tupleType&>(tp).value;
}

int main()
{

	xtuple_element_type<1, xtuple<int, double, char>>::type n; 
	cout << typeid(n).name() << endl; // double이 출력됨

	xtuple_element_type<2, xtuple<int, double, char>>::tupleType t; // tuple<char>

	xtuple<int, double, char> t3(1, 3.4, 'A'); // 0번째 요소의 타입 : int
											   // 0번째 요소를 저장하는 타입 : xtuple<int, double, char>  -> 이걸 알아야지 해당 클래스에서 저장하는 요소를 뽑을수 있다. ( 앞쪽 기반 클래스 내용 보면 앎)

	xget<0>(t3) = 10;

	cout << xget<0>(t3) << endl; // 10
	cout << xget<1>(t3) << endl; // 3.4
	cout << xget<2>(t3) << endl; // 'A'
}

// tuple_element
// 1. tuple이 가진 N번째 요소의 타입을 구하는 템플릿.
// 2. primary tempalte을 만든다. -> 의도적으로 선언만 할 수도 있다. 
// 3. 0번째 요소를 구하는 부분 특수화를 만든다. 
// 4. N번쨰 요소를 위한 부분 특수화를 만들고 Recursive를 사용한다