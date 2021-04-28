#include <iostream>
using namespace std;

template<typename T> struct xisPointer
{
	// bool value = false; // 이건 불가.. 컴파일 타임 상수가 아니라서.. 
	                       // 즉, 상수가 아니라 변수라 런타임에 값을 알수 있음. ( 따라서 포인터인지 아닌지를 컴파일타임에 알수 없음)
						   // 그리고 c++ 11전에는 struct에서 변수 초기화는 불가.. (이후엔 가능)
	// enum {value =false};// 그래서 그동안 enum을 씀.. 근데 이건 data type이 없어서 암시적으로 int 취급.. 그래서 안좋음
	static constexpr bool value = false;  // C++11의  constexpr 사용
};


//[*] 근데 아래 특수화는 "비상수" 포인터만 걸림.. 즉 const 붙은거 안걸림.
//[*] 따라서 아래 처럼 각각의 버전을 만들어야함. 
template<typename T> struct xisPointer<T*> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11의  constexpr 사용
};

template<typename T> struct xisPointer<T* const> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11의  constexpr 사용
};

template<typename T> struct xisPointer<T* volatile> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11의  constexpr 사용
};

template<typename T> struct xisPointer<T* const volatile> 
{
	//enum { value = true };
	//static const bool value = false;
	static constexpr bool value = true;  // C++11의  constexpr 사용
};


int main()
{
	cout << xisPointer<int>::value <<endl;
	cout << xisPointer<int*>::value <<endl;
	cout << xisPointer<int* const>::value <<endl;
	cout << xisPointer<int* volatile>::value <<endl;
	cout << xisPointer<int* const volatile>::value <<endl;
	cout << xisPointer<int* volatile const>::value <<endl; // ? 일단 위처럼 특수화들을 해주면 이것도 포인터로 정상 인식하긴 함.. 

	//[*]int* const 는 int* const value를 의미하는거 같음.. 즉 value는 불변, *value의 값은 변경가능.. 
	//[*]int* volatile도 마찬가지.. 아마 value에 적용되는 의미가 맞는거 같음.

	//[*]뒷 강의에서는 위 내용을 쉽게 만들수 있는게 나오나봄
}


