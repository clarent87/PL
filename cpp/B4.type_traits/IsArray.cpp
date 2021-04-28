/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : IsArray.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
//			�����̸�    Ÿ��

// int a;		a		int
// int* p;		p		int*
// int x[10];	x		int[10]	=> T[N]

// int[] : �����´� ũ�⸦ �˼� ���� �迭 Ÿ�� 

template<typename T> struct IsArray
{
	static const int size = -1;
	static const bool value = false;
};

// ũ�Ⱑ �ִ� �迭�ΰ��
template<typename T, size_t N> struct IsArray<T[N]>
{
	static const int size = N;
	static const bool value = true;
};

// ũ�⸦ �˼� ���� �迭�� ��� �κ� Ư��ȭ�� �Ʒ��� ���� ����
// IsArray<int[]>::value ���� true�� ������ ��.
template<typename T> struct IsArray<T[]>
{
	static const int size = N;
	static const bool value = true;
};

// ���� �� T&�� �ƴ� T�� ���� �迭�� Ÿ�� pointer����.. (���� type deduction�� ����)
// ���� ���������� const T& ��� T&����
template<typename T> void foo(const T& a) // int[10]
{
	if (IsArray<T>::value)   // �� �ڵ带 �����ؼ� IsArray<>����� ������.. 1�� �迭�� ����� ������
		cout << "�迭 �Դϴ�. ũ��� " << IsArray<T>::size << endl;
	else
		cout << "�迭�� �ƴմϴ�." << endl;

	// ���� �Լ� ���ڷ� �迭�� �ִ°�� ũ�⵵ �Ķ���ͷ� ����ϴµ�, �� ������ �̿��ϸ� �迭�� ũ�⸦ ���൵ �˼� ����
	// �� �������δ� 1���� �迭�� ũ�⸸ �˼��ִµ�, c++ 11ǥ���� extent<T,N> �̿��ϸ� N�� �迭�� ũ�� �˼�����
}

int main()
{
	int x[10] = { 1,2,3 };
	foo(x);
}


// * is_array �����
// �̷��� �׻� ����ü�� ����� ���̴�. ( is_array, is_pointer)
// 1. primary tempalte������ false�� ���� (value=false)
// 2. �迭 ������� �κ� Ư��ȭ ����� ����� true ����(value=true)
// 3. Ÿ���� ��Ȯ�� �˾ƾ� �Ѵ�. 
	// int x[3] : ���� x�� ���� �̸�, ���� �̸��� ������ ������ ���(int[3])�� Ÿ���̴�. 
// 4. unknown size array type(T[])�� ���ؼ��� �κ� Ư��ȭ�� �����Ѵ�. 

// *�迭�� ũ��
// 1. �迭�� ũ�⵵ ���� �� �ִ�. 
//    - c++11 ǥ�� - extent<T,0>::value // ���⼭ 0�� ����. 
// 2. �Լ� ���ø� �� ���ڸ� ��(T)���� ���� ��� �迭�� �����ϸ� T�� Ÿ���� �迭�� �ƴ� �����ͷ� �����ȴ�. 