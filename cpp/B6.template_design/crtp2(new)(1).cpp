// 기본적인 싱글톤 형태,, 책이랑은 약간 다름
class Cursor
{
private:
    Cursor(){}
public:
    // 싱글톤 만들떄에는 복사생성자, 대입생성자는 전부 날린다
    Cursor(const Cursor& c) = delete;
    void operator=(const Cursor& c) = delete;

    static Cursor& getInstance()
    {
        static Cursor instance; // .bss에 생성되겠지..
        return instance;
    }
};

int main()
{
    Cursor& c1 = Cursor::getInstance();
}

// 1. 싱글톤: 하난의 객체만 생성할 수 있게 하는 디자인 패턴. (특징,만드는법)
//    1. private 생성자
//    2. 복사와 대입 금지.
//    3. 하나의 객체를 만들어서 리턴하는 static 멤버 함수

