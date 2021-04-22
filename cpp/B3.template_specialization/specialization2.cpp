/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : specialization2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename T, typename U> struct Test
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U> struct Test<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};

template<typename T, typename U> struct Test<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};

// 핵심 : 부분 특수화 시에 템플릿 인자의 갯수는 변할수 있다
// "템플릿 인자 T나U의 갯수가 변할 수있다" 임. Test<T,T> 처럼 뒤에는 두개가 와야함 (primary처럼 )
template<typename T> struct Test<T, T>
{
	static void foo() { cout << "T, T" << endl; }
};

template<typename U> struct Test<int, U>
{
	static void foo() { cout << "int, U" << endl; }
};

// int, int : 특수화..
// 이것은 struct Test<T, T>, struct Test<int, U> 가 두개가 있어서 Test<int, int>:를 사용시 에러가 나는것을 막기위해
// 특수화를 int,int에 대해 진행한것.
template<> struct Test<int, int>
{
	static void foo() { cout << "int, int" << endl; }
};

template<> struct Test<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};


// 템플릿 인자가 3개일때, 부분 특수화.. 이런 모양 많이 나오니까 잘 봐둬야 한다. 
template<typename T, typename U, typename V> struct Test<T, Test<U,V>>
{
	static void foo() { cout << " T, Test<U,V>" << endl; }
};

int main()
{
	Test<int, double>::foo();	// T,  U
	Test<int*, double>::foo();  // T*, U
	Test<int*, double*>::foo(); // T*, U*
	Test<int, int>::foo();     // T, T => int, int (템플릿 특수화추가했기 때문에 int, int 로 나중에 결과가 바뀐것)
	Test<int, char>::foo();    // int, U
	Test<int, short>::foo();   // int, short

	// 템플릿 인자가 3개
	Test<double, Test<char, short>>::foo(); // T, Test<U,V>
}

// 부분 특수화 만들 때 핵심 사항
// 1. primary template의 템플릿 인자가 2개라면, 사용자는 반드시 템플릿 인자를 2개 전달해야 한다. (디폴트 인자가 없다면.. )
// 2. 하지만, 부분특수화 버전을 만들때 템플릿 인자의 개수는 Primary Template 인자의 개수와 가를 수 있따. 단, 부분 특수화의 
//    선언에는 반드시 템플릿 인자를 2개 전달해야 한다. 
//    예시) 위의 template<typename T> struct Test<T, T> 
// 3. 재귀적 모양의 부분 특수화를 만드는 모양이 중요. 많이 쓰인다. 
//    예시) 위의 struct Test<T, Test<U,V>> 















