#include<iostream>
#include<tuple>
using namespace std;

int main()
{
    tuple<> t0; // 아무것도 저장하지 않겠다는것
    tuple<int> t1; 
    tuple<int, double, int, chr> t4(1,3.4,2,'A'); // 아마 템플릿 직접 명시 안해도 객체의 생성자로 추론해주긴 할듯

    get<2>(t4) = 10 // get은 참조를 return해주기 때문에 이겄도 가능하다함.
    cout << get<2>(t4) << endl;

}

//tuple
//1. 서로 다른 타입의 객체를 N개 보관하는 템플릿.
//2. 요소를 접근할 떄는 get을 사용한다. 
//3. c++11 부터 표준으로 제공. <tuple>헤더

