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

// �ٽ� : �κ� Ư��ȭ �ÿ� ���ø� ������ ������ ���Ҽ� �ִ�
// "���ø� ���� T��U�� ������ ���� ���ִ�" ��. Test<T,T> ó�� �ڿ��� �ΰ��� �;��� (primaryó�� )
template<typename T> struct Test<T, T>
{
	static void foo() { cout << "T, T" << endl; }
};

template<typename U> struct Test<int, U>
{
	static void foo() { cout << "int, U" << endl; }
};

// int, int : Ư��ȭ..
// �̰��� struct Test<T, T>, struct Test<int, U> �� �ΰ��� �־ Test<int, int>:�� ���� ������ ���°��� ��������
// Ư��ȭ�� int,int�� ���� �����Ѱ�.
template<> struct Test<int, int>
{
	static void foo() { cout << "int, int" << endl; }
};

template<> struct Test<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};


// ���ø� ���ڰ� 3���϶�, �κ� Ư��ȭ.. �̷� ��� ���� �����ϱ� �� ���־� �Ѵ�. 
template<typename T, typename U, typename V> struct Test<T, Test<U,V>>
{
	static void foo() { cout << " T, Test<U,V>" << endl; }
};

int main()
{
	Test<int, double>::foo();	// T,  U
	Test<int*, double>::foo();  // T*, U
	Test<int*, double*>::foo(); // T*, U*
	Test<int, int>::foo();     // T, T => int, int (���ø� Ư��ȭ�߰��߱� ������ int, int �� ���߿� ����� �ٲ��)
	Test<int, char>::foo();    // int, U
	Test<int, short>::foo();   // int, short

	// ���ø� ���ڰ� 3��
	Test<double, Test<char, short>>::foo(); // T, Test<U,V>
}

// �κ� Ư��ȭ ���� �� �ٽ� ����
// 1. primary template�� ���ø� ���ڰ� 2�����, ����ڴ� �ݵ�� ���ø� ���ڸ� 2�� �����ؾ� �Ѵ�. (����Ʈ ���ڰ� ���ٸ�.. )
// 2. ������, �κ�Ư��ȭ ������ ���鶧 ���ø� ������ ������ Primary Template ������ ������ ���� �� �ֵ�. ��, �κ� Ư��ȭ�� 
//    ���𿡴� �ݵ�� ���ø� ���ڸ� 2�� �����ؾ� �Ѵ�. 
//    ����) ���� template<typename T> struct Test<T, T> 
// 3. ����� ����� �κ� Ư��ȭ�� ����� ����� �߿�. ���� ���δ�. 
//    ����) ���� struct Test<T, Test<U,V>> 















