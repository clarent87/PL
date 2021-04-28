#include <iostream>
using namespace std;

template<typename T> struct xisPointer
{
	// bool value = false; // �̰� �Ұ�.. ������ Ÿ�� ����� �ƴ϶�.. 
	                       // ��, ����� �ƴ϶� ������ ��Ÿ�ӿ� ���� �˼� ����. ( ���� ���������� �ƴ����� ������Ÿ�ӿ� �˼� ����)
						   // �׸��� c++ 11������ struct���� ���� �ʱ�ȭ�� �Ұ�.. (���Ŀ� ����)
	// enum {value =false};// �׷��� �׵��� enum�� ��.. �ٵ� �̰� data type�� ��� �Ͻ������� int ���.. �׷��� ������
	static constexpr bool value = false;  // C++11��  constexpr ���
};


//[*] �ٵ� �Ʒ� Ư��ȭ�� "����" �����͸� �ɸ�.. �� const ������ �Ȱɸ�.
//[*] ���� �Ʒ� ó�� ������ ������ ��������. 
template<typename T> struct xisPointer<T*> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11��  constexpr ���
};

template<typename T> struct xisPointer<T* const> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11��  constexpr ���
};

template<typename T> struct xisPointer<T* volatile> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11��  constexpr ���
};

template<typename T> struct xisPointer<T* const volatile> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11��  constexpr ���
};


int main()
{
	cout << xisPointer<int>::value <<endl;
	cout << xisPointer<int*>::value <<endl;
	cout << xisPointer<int* const>::value <<endl;
	cout << xisPointer<int* volatile>::value <<endl;
	cout << xisPointer<int* const volatile>::value <<endl;
	cout << xisPointer<int* volatile const>::value <<endl; // ? �ϴ� ��ó�� Ư��ȭ���� ���ָ� �̰͵� �����ͷ� ���� �ν��ϱ� ��.. 

	//[*]int* const �� int* const value�� �ǹ��ϴ°� ����.. �� value�� �Һ�, *value�� ���� ���氡��.. 
	//[*]int* volatile�� ��������.. �Ƹ� value�� ����Ǵ� �ǹ̰� �´°� ����.

	//[*]�� ���ǿ����� �� ������ ���� ����� �ִ°� ��������
}


