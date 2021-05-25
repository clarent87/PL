#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

template<typename T> void call_foo(T arg) // 기본적으로 값이 넘어온다.  (이때 foo 의 int&는 T arg를 참조하는것,, 그래서 n의 값에 영향을 안줌)
{
    foo(arg);
}

int main()
{
    int n = 0;
    
    //foo(n); // [*] n은 200이됨
    //call_foo(n); // [*] n은 0그대로.. 왜냐면 T가 int가 되서 값이 넘어감
    call_foo( std::ref(n) ); // [*] 그런데 이렇게 하면 n이 200이 나온다. 

    std::cout << n << std::endl;
}