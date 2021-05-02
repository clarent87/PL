#include<iostream>
#include<tuple>
using namespace std;

template<typename ... Types> void foo(Types ... args)
{
    // int x[] = {args...}
    tuple<Types...> tp(args...); // 만약 args의 타입들이 제각각 일때.. 배열에 넣을수 없으니 튜플을 쓴다. 

    cout << get<0>(tp) << endl;
    cout << get<1>(tp) << endl;
    cout << get<2>(tp) << endl;
    // 근데 tuple을 이용하면 값을 for문으로 뺄수 없나봄 위처럼 get을 써야 하는데 템플릿이라서 tuple의 index를 컴파일 타임상수를 써야함
    // 이거 해결하는 것은 뒤에 나온다함. 
}

int main()
{
    foo(1,3.4,"AA"); // args : 1,3.4,"AA"
}

// parameter pack에서 각 요소를 꺼내는 방법
// 1. pack expansion -> 배열 또는 tuple에 담아서 쓴다. 
// 2. 재귀 호출과 유사한 호출식을 사용한다. (다음예제에서 나옴.)