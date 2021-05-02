#include <iostream>
using namespace std;

struct Base
{
	int value = 10; // c++11부터는 struct안에서 이렇게 초기화 하는게 가능
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20
	cout << d.Base::value << endl; // 10 // base class의 value 뽑아줄때 이렇게 할수 있음
										 // 또는 아래처럼 cast를 이용

	cout << (static_cast<Base>(d)).value << endl;  // 10 
												   // 이코드는 d를 가지고 복사생성 해서 임시객체를 만듬. 즉 value는 임시객체의 value임 
	cout << (static_cast<Base&>(d)).value << endl; // 10 
												   // 이 코드는 임시 객체를 생성하는 코드가 아님. d를 base처럼 생각하라는 의미
												   // int& x = a 와 같은 의미라고 보여지네.. (즉 참조형의 의미..를 말함.)
		
	(static_cast<Base>(d)).value = 30;	// error . 임시객체는 lvalue가 될수 없다. 
	(static_cast<Base&>(d)).value = 30;	// ok

	//* 강사는 위 코드에서 ()는 제거하고 썻음.즉 static_cast<Base&>(d).value이렇게 씀

	// [*] 값 캐스팅은 절대 쓰면안된다. !
	// 이거 c++ intermediate과정의 temporary에 나온다는데?
}

// 기반 클래스의 멤버에 접근 하는 방법
// 1. 기반 클래스의 멤버와 파생클래스의 멤버의 이름이 동일할 때는 자신(파생클래스)의 멤버가 수선시 된다. (위 d.value 예시)
// 2. 기반 클래스의 멤버에 접근하는 방법
//    - d.Base::value
//    - static_cast<Base&>(d).value
// 3. 값 캐스팅과 참조 캐스팅
//    - static_cast<Base>(d) : 임시객체 생성. lvalue가 될 수 없다. 
//    - static_cast<Base&>(d): 임시객체 생성 안함. lvalue가 될 수 있다. 