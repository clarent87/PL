/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : template_alias2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


// template alias
template<typename T> class List {};

// typedef : type 별칭을 만들지만... template 의 별칭을 만들수 없다.
typedef List<int> IntList; // ok..

//template<typename T> typedef List<T> MyList<T>;  // error. 

template<typename T> using MyList = List<T>;

///////////////////////////////////////////////////////////////////
template<typename T, typename U> struct Pair{
	T v1;
	U v2;
};

// typedef Pair Point ; // error
// using Point = Pair // 근데 Pair가 템플릿 임을 알려줘야함. ( using은 type , 템플릿 모두의 별칭 만드는 것에 가능)
					  // 따라서  using Point = Pair<T,U>; 인데.. T와 U가 무엇인지.. Pair가 템플릿인지 알려줘야해서
					  // template<typename T, typename U>가 필요.
template<typename T, typename U> using Point = Pair<T,U>;

// 아래처럼 템플릿 파라메터인자 고정도 가능
template<typename T> using Point2 = Pair<T,T>;
template<typename T> using Point3 = Pair<T,short>;

int main()
{
	//List<int> s;
	//IntList s; 

	MyList<int> s; // List<int> 

	Point<int, double> p;// Pair<T,U>
	Point2<int> p2;// Pair<int,int>
	Point3<int> p3;// Pair<int,short>
}


// 핵심 정리
// 1. typedef : type의 별칭만 만들수 있다. 
// 2. using : type 뿐아니라 template의 별칭도 만들수 있다. 
