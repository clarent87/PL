#include <iostream>
#include <boost\type_index.hpp> // boost를 설치해야 한다. 
using namespace std;
using namespace boost::typeindex; // 원하는 함수는 boost namespace의 typeindex namespace안에 있다. 

template<typename T> void foo(const T a)
{
    
    // cvr은 const, volatile, reference
    cout << type_id_with_cvr<T>().pretty_name() << endl; 
    
    // 기본적으로 type_id_with_cvr는 type밖에 조사가 안됨
    // 따라서 변수 조사할때는, c++ 11의 decltype을 이용한다. 
    cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl; 

}

int main()
{
    foo(3); // T : int,   a : const int
    foo(3.3);// T : double,   a : const double
}

// 빌드 방법 "boost 사용하기"  동영상 참고
// g++ deduction2.cpp -Ic:\\boost경로