/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : int2type2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

template<int N> struct int2type
{
	enum { value = N }; // ���� ��Ÿ��, ������ constexpr ���.
};

void foo(int n) {}

// 0, 1 �� ���� �Լ� �����ε�.
void foo(int2type<0>) {}
void foo(int2type<1>) {}

int main()
{
	foo(0);	
	foo(1);	// 0, 1�� ���� Ÿ��.. foo(0), foo(1)�� ���� �Լ� ȣ��
	
	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1 �� �ٸ� Ÿ���̹Ƿ� foo(t0), foo(t1)�� �ٸ� �Լ� ȣ��.
}

// int2type����
// 1. ������ �ð� ������ ����� ������ ������ Ÿ������ ����� ����.
// 2. int2type�� ����ϸ� "������ �ð��� ������ ������ ���"�� ��� �ٸ� Ÿ������ ���� �� �ִ�. 
	// 77,78�� ���� Ÿ���� ��������, int2type<77>, int2type<78>�� �ٸ� Ÿ���̴�. 
// 3. int2type�� ����ϸ� "������ �ð��� ������  ������ ���"�� ������ �Լ� ���� �ε��� ����ϰų�, ������ ����, ��� ��� ����� �� �ִ�. 