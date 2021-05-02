#include<iostream>
#include<type_traits>
using namespace std;

// 이전 강의의 printv예제

/*
template<typename T> void printv(const T& v)
{
    if constexpr (is_pointer<T>::value) // constexpr은 c++17만 가능
        cout << v << ":" << *v << endl;
    else 
        cout << v << endl;
}
*/

// c++17이 아닐경우는 아래 처럼
/*
template<typename T> void printv_imp(T& a, false_type)  
{
	cout << a << endl;
}

template<typename T> void printv_imp(T& a, true_type)
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv(T& a)
{
	printv_imp(a, is_pointer<T>());  // pointer일떄와 아닐떄 base class가 각각 true_type/false_type 임
                                     // [*] 이형태 잘기억해야함.. is_pointer는 함수가 아님!
}
*/

// T가 포인터 일때 아래 사용
template<typename T> 
typename enable_if<is_pointer<T>::value>::type printv(const T& v) 
{
    cout << v << ":" << *v << endl;
}

// T가 포인터가 아닐떄 아래 사용
// T가 포인터 일때는 is_pointer의 type 은 없으므로 error 발생 따라서 아래 함수는 instantiate되지 않음
template<typename T> 
typename enable_if<!is_pointer<T>::value>::type printv(const T& v) 
{
    cout << v << endl;
}

int main()
{
    int n = 0;
    printv(n);
    printv(&n);
}

// 타입의 종류에 따라 다르게 동작하는 함수 만드는 방법
// 1. type_traits (is_pointer) + if constrexpr
// 2. type_traits + 함수 오버로딩 (true_type/false_type)
// 3. type_traits + enable_if => 이거 오픈소스에서 많이 쓴다고 함 (constrexpr는 17에서 등장한거라.. 아직 많지는 않나봄)

// [*] 중요한 점!!!
// const T& v 로 인자를 받을떄 type_deduction 에 따라 ref type만 &게 떨어지는것
// 위에서 printv(&n)는 n의 주소값(포인터)를 넘기는 거니까 포인터 int* type이 넘어감
// 여기 &연산자는 int& x의 type이랑은 다른거임. !!
