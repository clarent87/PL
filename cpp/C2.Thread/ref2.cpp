#include <iostream>

template<typename T> struct reference_wrapper
{
    T* obj;
public:
    reference_wrapper(T& t) : obj(&t) {}    
    operator T&() { return *obj;} // 변환 연산자
};

int main()
{
    int n = 0;
    reference_wrapper<int> rw = n; // n은 int, T는 int가 되었을꺼고,, 아마 변환생성자가 호출되는 거일듯.. ( int&받는 생성자도 아마 변환에 쓰일듯... )
  
    int& r = rw; // rw.operator int&()  즉, 변환 연산자 호출, 즉  T& 로 암시적 변환이 된것
    r = 100;
  
    std::cout << n << std::endl; // 100
}