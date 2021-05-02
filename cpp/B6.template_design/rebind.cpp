/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : rebind.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

// 실제 allocator 소스는 user_define_allocator.cpp 소스를 참고 하세요.
template<typename T> class allocator
{
public:
	T* allocate(int sz)   { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }

	// 
	template<typename U> struct rebind
	{
		typedef allocator<U> other;
	};
};
// rebind
template<typename T, typename Ax = allocator<T> > class list
{
	struct NODE	{	T data;	NODE *next, *prev;	};

	//Ax ax; // allocator<int>
	//allocator<int>::rebind<NODE>::other ax;     // allocator<NODE> ax;
	typename Ax::template rebind<NODE>::other ax; // allocator<NODE> ax;
									// rebind<NODE>가 컴파일러는 비교연산인지 템플릿인지 모르므로.. template 키워드 필요

	// [*] 즉 list는 node의 연속이므로 T 타입만큼 메모리를 할당 받는게 아닌 NODE 크기많큼 받아야 한다. 
	// [*] 이걸위해서 allocator는 rebind라는 함수를 제공하는것

public:
	void push_front(const T& a)
	{	
		ax.allocate(1);
	}
};

int main()
{
	list<int> s;
	s.push_front(10);

}









