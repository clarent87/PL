/// Q.1 생성자의 호출 순서
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

struct TEST{
    Resource1 res1;
    static Resource2 res2; // 전역 변수에 메모리가 잡힘
};

// static멤버 변수는 전역에서 초기화 해주어야 함
// https://webnautes.tistory.com/1434
// 클래스의 static 멤버변수는 클래스 내에 선언하는 것만으로는 공간이 할당되지
// 않는다. 클래스 내에 선언된 형태를 바탕으로, 클래스 밖에서 변수를 선언해야 메모리
// 공간을 할당받고 변수를 사용할 수 있게 된다. (이 작업을 하지 않으면 확인할 수
// 없는 외부참조 오류가 난다.) 또한 클래스의 static 멤버 변수는 클래스 객체의 생성
// 시 클래스의 일부분으로서 저장되는 것이 아니라 별도로 저장이 된다
Resource2 TEST::res2; 

int main(){
    cout << "main" <<endl;
    TEST t;
    // main 실행시 불리는 생성자 호출 순서
    // "Resource2()"
    // "main"
    // "Resource1()"
} 


