template<typename T, typename ThreadModel = NoLock> class List // ��Ƽ ������ �Ⱦ��� default�� nolock�� ����
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.Lock(); // NoLock�϶� inline�Լ��� �ƹ��ϵ� ���ϴϱ� �����Ϸ� ����ȭ�� ���� �� ���� ������
				   // Lock�϶� inline�Լ� ���⿡ �״�� ����Ǵϱ�. �Լ� ȣ�� overhead�� ����.
		//......
		tm.Unlock();
	}
};

// ����ȭ ��å�� ���� ��å Ŭ���� : �ݵ�� Lock()/Unlock() �� �־�� �Ѵ�.
// [*] �Ʒ��� ������ ��å Ŭ���� ��� �ϴ� �͵��̰� ���Ѿ� �ϴ� ��Ģ�� �ִ�.
// [*] ���⼭�� "�ݵ�� Lock()/Unlock() �� �־�� �Ѵ�." �� �ݵ�� ���Ѿ� �ϴ� ��Ģ�̰�
// [*] �̰� �ڵ�� ǥ���ɼ��� ��� ����ȭ�ؼ� ���� �ʿ� - c++20�� concept������ ������ �����Ҽ��� �մ���
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
// 1. Ŭ������ ����ϴ� ��å�� ���ø� ���ڸ� ���ؼ� ��ü �� �� �ְ� ����� ������
// 2. ���� ���� ���� ��å�� ��ü �� �� �ִ�. 
// 3. ��κ� ��å�� ����  "���� ���� Ŭ����"�� ���Ѿ� �ϴ� ��Ģ�� �ִ�. 
//   - ��Ģ�� ǥ���ϴ� �ڵ� ����� ����. (�������̽� ���� ���� �Լ� �̹Ƿ� �ణ�� �����ص� �߻�, c++20 concept���δ� �����Ҽ���.. )
//   - �츮�� ���� ����ȭ ��å Ŭ������ "lock/unlock" �Լ��� �ʿ��ϴ�. 
//   - ���ø� ��� ���̺귯��, Ư�� STL���� �θ� ���Ǵ� ������ ���