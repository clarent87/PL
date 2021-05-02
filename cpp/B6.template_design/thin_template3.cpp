
/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : thin_template3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/


// ��� 2. void* ��� �����̳� + ĳ������ å������ �Ļ� Ŭ���� 
//			=> �� T�� ����ϴ� �������� ������ base class�� �ű�� ���� void*�� ����
//			=> �ڽ� class�� base class ������ ȣ���ϵ� ���� Ÿ�� ĳ������ ����.


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

// ĳ���ø� å������ �Ļ� Ŭ����
// [*] �̰��� thin template�̶�� �θ���.
// [*] ������̳� �Ӻ���� ���� Vector�� �Ʒ��� ���� �������. 
template<typename T> class Vector : private VectorBase // private�� �� ������ ��� class������ ����ڰ� ȣ���Ҽ� ������ �ϱ� ���� 
{
public:
	inline int size() const   { return VectorBase::size(); } // private VectorBase ������ �߰�
	inline bool empty() const { return VectorBase::empty(); } // private VectorBase ������ �߰�
	inline void push_front(const T& a) { VectorBase::push_front(static_cast<void*>(a)); }
	inline T& front() { return static_casst<T&>(VectorBase::front());	}

	// ĳ���� �Լ��� ���� inline ó���ؼ� ���� ���ϵ� ����, ���� �Լ��� ����� ������ �ʴ´�. 
};

int main()
{
	Vector<int>    v1;
	Vector<short>  v2;
	Vector<double> v3;
}