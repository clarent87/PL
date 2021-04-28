/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : result_traits.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

int f(int a, char c) { return 0; }

// primary template
template<typename T> struct result
{
	typedef T type; // [*] �ǵ������� �����ؼ� �Լ�Ÿ���� �ȿ��°�� error�� ���� �Ҽ��� �ִ�. 
};

// �ٽ� !!: �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���Ҽ� �ֵ��� Ÿ�� ������ �Ѵ�.
// �Ʒ��� �Լ�type�� return�� ���ڰ�2���� �͸� ����
template<typename R, typename A1, typename A2> struct result<R(A1, A2)>
{
	typedef R type;
};

template<typename T> void foo(T& t)  // T : int(int, char)
{
	typename result<T>::type n; 

	cout << typeid(n).name() << endl;
}

int main()
{
	foo(f);
	result<int>::type ret; // [*] �̰��� ��ó���ϸ� ret�� �׳� primary�� ���� int�� ����..
						   // [*] �̷���� error�� ���ְ� �ʹٸ�? primary version�� type�� ������. 
}

// *�Լ��� ������ ���ϴ� traits�����
// 1. primary template�� ����� "typedef T type"�� �����Ѵ�. (c++11 using�� ��밡��)
// 2. �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���� �� �ֵ��� "T Ÿ���� ����"�Ѵ�. 
// 3. �κ� Ư��ȭ�� ���ؼ� �Լ�Ÿ��( int(int,char) ) ����� T�� ���� Ÿ�� (int)�� ������ (����Ÿ��)���� �и��Ѵ�. 
//     - ���� R(A1,A2) ó��.. T�� ��ü��
// 4. primary template�� "typedef T type"�� �ʿ���� ���� �����ص� �ȴ�. 
