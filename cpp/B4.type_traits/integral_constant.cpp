/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : integral_constant.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

/*
// C++11���� int2type�� ������Ų �Ʒ� ���ø��� �����մϴ�

// ���� ��� �����迭 type�� ���� ����
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

// ����
//integral_constant<int,   0> n0;
//integral_constant<short, 0> s0;

// true/false           : �������� ��Ÿ���� ��, ���� Ÿ��
// true_type/false_type : �������� ��Ÿ���� Ÿ��, �ٸ� Ÿ��.
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// �׸��� is_pointer�� �Ʒ� ó�� ����� �˴ϴ�.
template<typename T> struct is_pointer     : false_type { }; // body�� value��� �� base class�� �����ϱ�.
template<typename T> struct is_pointer<T*> : true_type {};

*/


#include <type_traits>  // �� �ȿ� ���ڵ尡 �ֽ��ϴ�.
//------------------------------

template<typename T> void printv_imp(T a, false_type) // Ÿ�Ը� ������.. ������ �Ⱦ��ϱ� ����
{
	cout << a << endl;
}

template<typename T> void printv_imp(T a, true_type)
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv(T a)
{
	printv_imp(a, is_pointer<T>()); // is_pointer �ӽð�ü ����.
	                                // [*] c++������ child ��ü�� parent type���� �޾Ƽ� ���� ����. 
									//    ( �̶��� virtaul �Լ��� �ƴϸ� parent�� ���� ������.. �׸��� parent�� �Լ��鸸 ��밡�� �ε�)
}

int main()
{
	int n = 3;

	printv(n);
	printv(&n);
}

// �ٽɰ���.
// 1. int�� �ƴ϶� ��� ���� �迭(bool, char, short, int, long, long long)�� ��� ���� Ÿ������ ���� �� �ְ� ����. 
//    ( ����, �Ǽ��� ���ø� ���ڷ� ����� �� ����. )
// 2. integral_constant :  "��� ���� �迭�� ������ �ð� ���"�� Ÿ������ ����� ���ø�.
// 3. true_type, false_type
//    - true/false           : �������� ��Ÿ���� ��, ���� ���� Ÿ��
//    - true_type/false_type : �������� ��Ÿ���� Ÿ��, ���� �ٸ� Ÿ��.
// 4. is_pointer ���� type_traits�� ���� �� integral_constant �� ��� Ŭ������ ����Ѵ�. 
//    - T�� �����Ͱ� �ƴ϶��, value=false, �� ��� Ŭ������ false_type
//    - T�� ������ ��� value=true, �� ��� Ŭ������ true_type






