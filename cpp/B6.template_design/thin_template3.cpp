
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : thin_template3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


// 방법 2. void* 기반 컨테이너 + 캐스팅을 책임지는 파생 클래스 
//			=> 즉 T를 사용하던 내용들까지 모조리 base class로 옮기고 전부 void*로 변경
//			=> 자식 class는 base class 내용을 호출하되 전부 타입 캐스팅을 해줌.


class VectorBase
{
protected:
	void* buff;
	int sz;
public:
	int size() const;
	bool empty() const;

	void  push_front(const void* a);
	void* front();
};

// 캐스팅만 책임지는 파생 클래스
// [*] 이것을 thin template이라고 부른다.
// [*] 모바일이나 임베디드 장비용 Vector는 아래와 같이 만든다함. 
template<typename T> class Vector : private VectorBase // private을 한 이유는 기반 class내용을 사용자가 호출할수 없도록 하기 위해 
{
public:
	inline int size() const   { return VectorBase::size(); } // private VectorBase 때문에 추가
	inline bool empty() const { return VectorBase::empty(); } // private VectorBase 때문에 추가
	inline void push_front(const T& a) { VectorBase::push_front(static_cast<void*>(a)); }
	inline T& front() { return static_casst<T&>(VectorBase::front());	}

	// 캐스팅 함수를 전부 inline 처리해서 성능 저하도 없고, 실제 함수로 만들어 지지도 않는다. 
};

int main()
{
	Vector<int>    v1;
	Vector<short>  v2;
	Vector<double> v3;
}