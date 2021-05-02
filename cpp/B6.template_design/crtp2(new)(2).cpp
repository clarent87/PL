// CRTP 싱글톤
// 안드로이드 오픈소스가 이렇게 되어있다. 
template<typename T>class Singleton
{
protected: // 여기는 private으로 하면 파생 클래스는 객체를 만들수가 없음.. 
    Singleton(){}
public:
   
    Singleton(const Singleton& c) = delete;
    void operator=(const Singleton& c) = delete;

    static T& getInstance()
    {
        static T instance; // .bss에 생성되겠지..
        return instance;
    }
};


// 마우스도 싱글톤으로 만들고 싶을때.
// 싱글톤 코드를 복붙하지 말고 CRTP를 이용한다. 
class Mouse : public Singleton<Mouse>
{

};

int main()
{
    Mouse& m = Mouse::getInstance();
    
}

// 1. 싱글톤: 하난의 객체만 생성할 수 있게 하는 디자인 패턴. (특징,만드는법)
//    1. private 생성자
//    2. 복사와 대입 금지.
//    3. 하나의 객체를 만들어서 리턴하는 static 멤버 함수

