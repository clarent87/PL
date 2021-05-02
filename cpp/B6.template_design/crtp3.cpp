/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : crtp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// T를 쓸려고 하는것은 아니다. 
// 단지 서로 다른 기반 class를 사용해주기 위함( 내용 보면 앎)
template<typename T> struct Count
{
private:
	static int cnt;
public:
	Count() { ++cnt; }
	~Count() { --cnt; }

	static int count() { return cnt; }
};
template<typename T> int Count<T>::cnt = 0; // static은 외부에서 선언이 필요

class Mouse : public Count<Mouse>
{
};
class Keyboard : public Count<Keyboard>
{
};

int main()
{
	Mouse m1, m2;
	Keyboard k1, k2;

	cout << k1.count() << endl;
}
// CRTP를 활용한 Unique한 기반 클래스 만들기
// 1. 기반 클래스의 static member data는 모든 파생 클래스에 의해 공유된다. 
// 2. 파생 클래스 별로 다른 static member data가 필요한 경우, 서로 다른 기반 클래스를 사요해야 한다. 
// 3. CRTP를 사용하면 모든 파생 클래스 별로 다른 타입의 기반 클래스를 만들수 있다. 