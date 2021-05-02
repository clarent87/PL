/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : result_using_variadic_template.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
#include <type_traits>
using namespace std;

/*
* type traits���� ����� �����̶� ���غ��� ����. 
*/


template<typename T> struct result
{
	// typedef T type; // 1. T�� �Լ��� �ƴϾ����� error�� ���ֱ� ���� ����

	// 2. static_assert�� �̿��ϸ� error �޽����� �̻ڰ� ���� �ִ�. 
	static_assert(is_function<T>::value, "error"); 
		// ���� assert�� �׻� ���̱⸦ �ٶ�� �ڵ�. �� function�̸� ���̴ϱ� ������ ���� �ʴ´�. 
		// �ٵ� �� �ڵ忡�� ���� ���� �Դٴ� ���� �Լ��� �ƴ϶� ���.
};

// [*] �Ʒ�ó�� primary�� ���� ����� ���� ���� ���� ���δ�. (primary�� ���� ������ �翬 ��������, �κ�Ư��ȭ�� �ִٸ� ����)
//     �̷��� primary�� ���� �ִ� �ڵ���� �� ���ٰ� ��

// template<typename T> struct result;

template<typename R, typename ... Types> struct result<R(Types...)> 
{                                                                   
	typedef R type;
};

template<typename T> void foo(T& a)  
{
	typename result<T>::type n;  

	cout << typeid(n).name() << endl;  
}

int main()
{
	int n = 0;
	foo(n);
}

// traits �� �� �� ����� �� ó�� ���
// 1. "typedef T Type"�� �������� �ʴ´�. 
// 2. static_assert()�� ����ؼ� ���� �޽����� ���
// 3. primary template�� ���� �����Ѵ�. 