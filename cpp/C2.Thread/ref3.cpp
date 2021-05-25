#include <iostream>

template<typename T> struct reference_wrapper
{
    T* obj;
public:
    reference_wrapper(T& t) : obj(&t) {}  // 복사 생성자.. 라고 봐야 할듯? const가 없지만.. 보통 const를 복사생성에 쓰는 이유는 rvalue때문.
    operator T&() { return *obj;}
};


void foo(int& a) { a = 200; }

template<typename T> 
void call_foo(T arg) // reference_wrapper<int> arg , 이떄 arg의 obj는 n의 주소를 가지게 된다. ( 주소가 복사됨.)
{
    foo(arg);
}

template<typename T> reference_wrapper<T> ref(T& obj ) // 이미 표준에 있따. 
{
    return reference_wrapper<T>(obj);
}

int main()
{
    int n = 0;

    // [*] 원리
    //call_foo(n);
    //reference_wrapper<int> rw = n;
    //call_foo(rw); // T는 reference_wrapper<int> 가 되고, 여기서는 reference_wrapper<int> arg = rw 즉 복사생성자가 호출

    // 위 내용을 간단하게 아래처럼.
    call_foo( ref(n) ); // std::ref(n)

    std::cout << n << std::endl; // 200
}