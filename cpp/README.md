# MOOC 정리

- [www.isocpp.org](https://isocpp.org/)
  - cpp표준위원회가 공식적으로 운영하는 사이트
  - 여기 current iso c++ status 에서 현재 c++ 상태 확인이 가능하다. ( 버전 확인 가능 좋음 ㅎ )
- [www.cppreference.com](https://en.cppreference.com/w/) 은 표준문서 내용을 잘 설명하고 있다.
  
## 목차

## 기초

1. 기초
2. 기초2

## c++ 11/14/17 기본

1. [c++11/14기본문법-1](A1.cpp11_14-basic/cpp11_14기본문법1.md)
2. [c++11/14기본문법-2](A1.cpp11_14-basic/cpp11_14기본문법2.md)
3. [c++11/14기본문법-3](A1.cpp11_14-basic/cpp11_14기본문법3.md)
4. [c++11/14기본문법-4](A1.cpp11_14-basic/cpp11_14기본문법4.md)

## c++ 11/14/17 고급

## 따로 알아본 것

const참조  
<https://boycoding.tistory.com/208>

참조형이란?
<https://boycoding.tistory.com/207>

new Cache?
: new 에서 ()안쓴 형태..
: new는 동적할당의미하고 ()나 {}를 안쓴건 초기화를 안한다는거 같음. 즉 new cache는 cache 구조체를 그냥 heap에 생성하고 끝?
: mutable없이 위문제 해결하는 법의 예제..
<https://boycoding.tistory.com/204>

## 궁금증

java에서 제네릭으로 특정 base class의 하위 class만 사용가능한 class, method 만드는게 가능한데..
c++ 템플릿도 특정 class만 사용가능한 class, method 만들수 있나? ( type_traits 사용해야하나? )
> 정답 : enable_if이용한다. [link][1]
  
class에서 멤버로 포인터가 좋은가 참조가 좋은가?  기본적으로는 참조를 써야하는데, class 멤버로는 포인터를 써야 한다는 거 같기도..

## 헷갈렸던것

```c++
class point{

  point(const point&){} // 이렇게 복사생성자를 만들면 default생성자는 생성안됨
  virtual ~point(){} // 소멸자는 virtual로 작업해서 자식 객체를 base로 캐스팅한 경우도 자식의 소멸자가 호출되게 함

}

int main(){
  point p; // 이렇게 stack에 변수 잡아도 생성자 호출됨

  // RAII개념은 이렇게 쓰기도 하고, class 멤버 변수로 쓸수도 이쏘.
  std::unique_ptr<point> pa(new point()); 
}

// [*] class의 멤버 변수로 Point p가 있었다면 객체 생성시 멤버 변수의 생성자가 먼저 호출됨 (notion에 정리됨) 
// [*] 아마 멤버 변수 소멸자도 자동으로 호출될거 같긴한데.. 


```



## link

auto_ptr
:여기 링크 내용 좋은듯
<https://psychoria.tistory.com/42>

RAII개념
: notion c++기초의 생성자 예외에 내용이 더 좋은듯.
<https://modoocode.com/229>

자동으로 추가되는 함수 규칙
http://egloos.zum.com/sweeper/v/2995404

cpp 인터페이스
https://igotit.tistory.com/entry/C%ED%81%B4%EB%9E%98%EC%8A%A4-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4-%ED%81%B4%EB%9E%98%EC%8A%A4-interface

참조자 vs pointer
https://gracefulprograming.tistory.com/11

복사,대입연산자
: 포인터를 가지는 경우는 반드시 두개가 필요하다고 하네.
https://link2me.tistory.com/1755

const&
https://rieulpost.tistory.com/54

[1]:https://stackoverflow.com/questions/30687305/c-equivalent-of-using-t-extends-class-for-a-java-parameter-return-type


