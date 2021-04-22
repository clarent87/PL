#include <iostream>
using namespace std;

// T의 타입이 알고 싶은 경우
template<typename T> void foo(const T a)
{
    cout << "T: " << typeid(T).name() << endl; // "typeid 연산자"를 이용해서 T 타입의 객체(typeinfo)를 받을수 있다. 
    cout << "T: " << typeid(a).name() << endl; // 변수 조사도 가능
}
// c++ 표준의 typeid로는 const, volatile, reference를 조사할수 없다. 
// 따라서 boost의 type_index 라이브러리를 사용

int main()
{
    // foo<int>(3); 이렇게 명시적으로 instantiation 해도 되고..
 
    foo(3); // T : int,   a : const int
    foo(3.3);// T : double,   a : const double
}