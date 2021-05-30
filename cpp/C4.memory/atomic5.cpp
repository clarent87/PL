#include <iostream>
#include <atomic>

struct Point
{
    int x, y;
    Point() = default;

    //Point(const Point& ) {} // [*] 멀티 코어에 안전하려면, 복사생성자 자체가 lock이 걸려야 한다. 
                            //   [*] 실제로 복사생성자 재정의하고 atomic의 템플릿 인자에 Point를 넣고 빌드하면, 
                            //   [*] atomic structure의 static_assert때문에 컴파일 실패한다. (T의 복사계열, Move계열 함수가 모두 trivial해야함)
                            

    Point(const Point &) = default; // [*] trivial한 복사생성자로 재정의. 따라서 이제 에러 없이 사용가능
};

std::atomic<Point> pt; // [*] 전역 변수 하나 잡음

int main()
{
    Point ret = pt.load(); // [*] pt를 멀티코어에 안전하게 ret에 넣어 달라는 예제, 여기서는 복사 생성자 호출됨
                            //[*] 근데, 복사생성자 재정의 안하고 쓰면 복사생성사 호출없이 그냥 메모리 복제하나봄.. 강의내용은 그랬음
}
