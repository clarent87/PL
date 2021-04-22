/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : template_alias2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


// template alias
template<typename T> class List {};

// typedef : type ��Ī�� ��������... template �� ��Ī�� ����� ����.
typedef List<int> IntList; // ok..

//template<typename T> typedef List<T> MyList<T>;  // error. 

template<typename T> using MyList = List<T>;

///////////////////////////////////////////////////////////////////
template<typename T, typename U> struct Pair{
	T v1;
	U v2;
};

// typedef Pair Point ; // error
// using Point = Pair // �ٵ� Pair�� ���ø� ���� �˷������. ( using�� type , ���ø� ����� ��Ī ����� �Ϳ� ����)
					  // ����  using Point = Pair<T,U>; �ε�.. T�� U�� ��������.. Pair�� ���ø����� �˷�����ؼ�
					  // template<typename T, typename U>�� �ʿ�.
template<typename T, typename U> using Point = Pair<T,U>;

// �Ʒ�ó�� ���ø� �Ķ�������� ������ ����
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


// �ٽ� ����
// 1. typedef : type�� ��Ī�� ����� �ִ�. 
// 2. using : type �Ӿƴ϶� template�� ��Ī�� ����� �ִ�. 