/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : parameter5.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

// 3. template paramter

template<typename T> class list {};

// [*] 두번째 템플릿 인자로, 템플릿을 받고 있다. (type이 아님. type이었으면 typename T였겠지..)
template<typename T, template<typename> class C> class stack
{
	//C c; // error, list c
	C<T> c; // ok.. list<int> c
};

// 정확한 type 보는 법.
// ./a.out | c++filt -t 


int main()
{
	list      s1; // error. list 는 타입은 아니고 템플릿
	list<int> s2; // ok.    list<int>는 타입.

	stack<int, list > s3; // ok. list는 템플릿임.
}

// 템플릿 인자로 템플릿 받는것은 너무 많이 쓰이는것.
