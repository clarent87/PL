
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : thin_template1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

// 멤버 함수 4개 * 3개 타입 => 12개 함수 생성
// [*] 물론 함수를 안쓰면 해당 함수는 instantiation되지 않는데,, 본 예제에서는 template class의 모든 함수를 쓴다고 가정
template<typename T> class Vector
{
	T* buff;
	int sz;
public:
	int size() const;
	bool empty() const;
	void push_front(const T& a);
	T& front();
};

int main()
{
	Vector<int>    v1;
	Vector<short>  v2;
	Vector<double> v3;
}