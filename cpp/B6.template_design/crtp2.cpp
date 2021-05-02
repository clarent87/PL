/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : crtp2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// CTRP 를 이용한 singleton만들기 
// 이건 기본 싱글톤 예제. 책이랑 같음

template<typename T> class Singleton
{
public:
	static T* instance;

	static T& getInstance()
	{
		if (instance == 0)
			instance = new T;
		return *instance;
	}
};

template<typename T> T* Singleton<T>::instance = 0;

class Cursor : public Singleton<Cursor>
{
};

int main()
{
	// 마우스를 따라 움직이는 커서는 시스템에 하나 밖에 존재하지 않음
	Cursor& c = Cursor::getInstance();
}