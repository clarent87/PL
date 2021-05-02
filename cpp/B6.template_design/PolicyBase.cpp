template<typename T, typename ThreadModel = NoLock> class List // 멀티 쓰레드 안쓸땐 default로 nolock이 쓰임
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.Lock(); // NoLock일땐 inline함수가 아무일도 안하니까 컴파일러 최적화에 의해 이 구문 삭제됨
				   // Lock일땐 inline함수 여기에 그대로 복사되니까. 함수 호출 overhead는 없음.
		//......
		tm.Unlock();
	}
};

// 동기화 정책을 담은 정책 클래스 : 반드시 Lock()/Unlock() 이 있어야 한다.
// [*] 아래와 같은게 정책 클래스 라고 하는 것들이고 지켜야 하는 규칙이 있다.
// [*] 여기서는 "반드시 Lock()/Unlock() 이 있어야 한다." 가 반드시 지켜야 하는 규칙이고
// [*] 이건 코드로 표현될수는 없어서 문서화해서 제공 필요 - c++20의 concept문법이 나오면 가능할수도 잇다함
struct NoLock
{
	inline void Lock() {}
	inline void Unlock() {}
};

struct Win32Lock
{
	inline void Lock()   { } // implement lock using win32 api
	inline void Unlock() { }
};

struct LinuxLock
{
	inline void Lock() { } // implement lock using linux system call
	inline void Unlock() { }
};


List<int, NoLock> st;

int main()
{
	st.push_front(10);
}

// Policy Base Design
// 1. 클래스가 사용하는 정책을 템플릿 인자를 통해서 교체 할 수 있게 만드는 디자인
// 2. 성능 저하 없이 정책을 교체 할 수 있다. 
// 3. 대부분 정책을 담은  "단위 전략 클래스"는 지켜야 하는 규칙이 있다. 
//   - 규칙을 표현하는 코딩 방식은 없다. (인터페이스 사용시 가상 함수 이므로 약간의 오버해드 발생, c++20 concept으로는 가능할수도.. )
//   - 우리가 만든 동기화 정책 클래스는 "lock/unlock" 함수가 필요하다. 
//   - 템플릿 기반 라이브러리, 특히 STL에서 널리 사용되는 디자인 기법