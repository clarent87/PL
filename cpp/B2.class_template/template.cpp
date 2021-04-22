/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : template.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

class Test
{
public:
	template<typename T> static void f() {}; // �Լ� ���ø�
	template<typename T> class Complex {};
};

template<typename T> typename T::template Complex<int> foo(T a)  // T �� Test
{
	Test::f<int>(); // ok. �Լ� ���ø��̴ϱ� f�� <int> ����.

	T::f<int>();    // error. < �� �ؼ��Ҽ� ����.
	T::template f<int>();    // ok [*] f�� ���ø����� �˷���.
	
	// [*] �߿� point! �� f�� ��� () �����ڿ� ���� �Ἥ �����Ϸ��� f�� �Լ����� �ȴ�. 

	// [*] �����Ϸ��� ���ø��� �����Ҷ�, T�� ������ ���������� ���� �����ϴ� ���� �ƴ�.
	// [*] �ܼ��� ���ø��� ���� �ϴ� ������ ����? �ϴµ�
	// [*] �� foo(t) �� �������� T�� Test�ϱ� T::f�� �Լ� ���ø� �̴�~ ��� �Ǵ��ؼ� T::f<int>();�� ������ �ȳ��� �ϴ°� �ƴ϶�°�!!
	// [*] ��, ���ø��� ���� �ϴ� �����ϴϱ� T::f<int>()���� "<" ������ ���� ����
 


	Test::Complex<int> c1; // ok.. Test�� ������ �����Ҽ� �ִ�.
	T::Complex<int> c2;    // error.
	typename T::Complex<int> c3;    // error. T::Complex�� Ÿ���ΰ� �˰ڴµ�, "<"�� �񱳿��������� �ƴ��� ���� error
	typename T::template Complex<int> c4;    // ok

	// [*] template Ű���� ���� ����� �߿�!!

	return c4;
}

int main()
{
	Test t;
	foo(t);
}