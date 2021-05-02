#include <iostream>
using namespace std;

// CRTP : Curiously Reccuring Template Pattern
// 책내용을 같이 봐야 정확히 이해할수 있다.
// 아래는 책에서 언급하는 issue의 해답만 나옴
template<typename T> class Window
{
public:
	void msgLoop() // void msgLoop(Window* this)
	{
		static_cast<T*>(this)->onKeyDown(); // this는 MyWindow의 객체 였으니까. 캐스팅해서 자기꺼 호출가능
	}
	void onKeyDown() { cout << "Window onKeyDown" << endl; }
};

class MyWindow : public Window<MyWindow>
{
public:
	void onKeyDown() { cout << "Window onKeyDown" << endl; }
};

int main()
{
	MyWindow w;
	w.msgLoop();
}

// CTRP 활용
// 1. 비 가상 함수를 가상 함수 처럼 동작하게 만들기.
//   - this 포인터를 파생 클래스 타입으로 캐스팅 한 후 함수 호출
//   - Microsoft의 ATL 라이브러리 등 많이 나오는 기법
//   - 가상 함수를 줄일수 있어서 size 줄이는데 매우 좋은가봄 ( + vtable도 줄어드니까.. 이득)