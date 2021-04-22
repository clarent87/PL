/// Q.2 그럼 템플릿으로 만든다면?
#include<iostream>
using namespace std;

struct Resource1{
    Resource1() {cout << "Resource1()" << endl;}
    ~Resource1() {cout << "~Resource1()" << endl;}
};

struct Resource2{
    Resource2() {cout << "Resource2()" << endl;}
    ~Resource2() {cout << "~Resource2()" << endl;}
};

template<typename T> struct TEST{
    Resource1 res1; //이건 main의 stack에 잡힘
    static Resource2 res2; // 전역 메모리에 생김
};
// 템플릿은 static 멤버 외부 선언을 아래와 같이 해줘야한다. 
template<typename T> Resource2 TEST<T>::res2; 

int main(){
    cout << "main" <<endl;
    TEST<int> t;
    // main 실행시 불리는 생성자 호출 순서
    // "main"
    // "Resource1()"
    // res2는 사용한 적이 없어서 컴파일러가 instantiation 하지 않았음
    // 만약 res2의 생성자에 무언가 작업을 해두었다면, 일반 sturct였다면 문제 없이 호출이 되었겠지만
    // 템플릿인 경우 호출이 되지 않으니, 주의 해야 한다. 
} 

