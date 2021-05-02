/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : print_tuple.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <tuple>
using namespace std;

/*
* 가변인자 템플릿을 이용해서 튜플 내용 출력하기
*/

// template<size_t ... N> struct index_sequence {};

template<typename TP, size_t ... I >  // size_t ... I  요 표현이 중요
void print_tuple_imp(const TP& tp, const index_sequence<I...>& ) // I : 0, 1, 2
{
	int x[] = { get<I>(tp)... }; // get<0>(tp), get<1>(tp), get<2>(tp)
								 // [*] 컴파일 타입에 get을 풀어야 하는데 index변수는 컴파일 타임 상수만 가능
								 // [*] 이를 위해 c++표준은 index_sequence을 제공 ( 위 주석과 정확히 일치하는 모습은 아니지만.. )

	for (auto& n : x)
		cout << n << ", ";
}

template<typename TP> void print_tuple(const TP& tp)
{
	print_tuple_imp(tp, make_index_sequence<tuple_size<TP>::value>());
}

int main()
{
	tuple<int, int, int> tp(1, 2, 3);

	// print_tuple_imp(tp, index_sequence<0,1,2>()); // index_sequence를 임시객체로 만들어서 넘겨야함.
	// print_tuple_imp(tp, make_index_sequence<3>()); // c++표준은 index_sequence를 쉽게 만들수 있는make_index_sequence도 제공
	print_tuple(tp);
}

// make_index_sequence는 만드는게 까다롭다네.
