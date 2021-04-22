/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : lazy1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

/*
class A
{
	int data;
public:
	void foo() { *data = 10; } // error : integer 역참조 했기 때문
};

int main()
{
	A a;
}
*/

template<typename T> class A
{
	int data;
public:
	void foo() { *data = 10; } 
};

// 컴파일러는 템플릿 class를 만들때 member함수가 실제로 쓰이지 않은경우 컴파일 하지 안는다.
// 즉, 멤버함수가 100개인데 10개만 실제로 사용하고 있으면, 10개만 실행파일에 들어감
// 이런 개념이 lazy instantiation

int main()
{
	A<int> a;
	a.foo(); // foo를 사용해야만 에러가 발생합니다.
}
