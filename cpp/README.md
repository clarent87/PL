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
  
그.. cpp 의 생성자에서 파라메터 여러개? 해서 뭐가 된다고 한게 뭐였지? 원래는 생성자 인자 한개만 가능했는데. 여러개 가능하다던거.. ( 변환생성자는 아니고..)  
템플릿 쪽이었나..

그 structure만 선언에서 변수 초기화가 됬다고 한거 같은데,, class는 원래 안되다가 되게 되었고,, 이거 무슨 챕터 내용이지? -> factorial.cpp

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

- friend 함수는 상속되지 않는다.

```cpp

Point t; // default 생성자 호출됨
Point t2 = t; // 여기서 호출되는것은 복사생성자. 
Point t3;

t3 = t2; // 여기서 호출되는것은 복사대입연산자.

Point t = 10; // 만약 Point에 Point(int) 생성자가 있었다면.. 즉 변환생성자가 있었다면.. 여기서는 변환 생성자가 호출됨 (int->Point)

int x = t; // 만약 변환연산자가 t에 있었다면, 여기서는 t의 변환연산자가 호출됨

```

- RAII라고 하면 file이나 malloc같은 자원 할당을 생성자에서하고, 소멸자에서 해제 하도록 하는 class 디자인을 말하는 듯
  이를 이용하면 RAII class객체를 stack에서 생성해서 쓰면 block에서 벗어날때 소멸자가 호출되니까, 자동으로 자원이 해제됨
  > 특정 함수에서 RAII를 안쓰고 직접 fopen-fclose를 썻다고 하면 만약 함수 중간에 excpetion이 발생한경우 fclose가 안불려서
  > 자원 누수 생기는데, 이럴떄 RAII를 썻다면 stack 객체의 소멸자 호출은 보장되므로 문제가 없다.
- class의 멤버 변수로 RAII객체를 가지고 있어도,, RAII디자인이라고 봐도 될듯
  만약 해당 class 생성자에서 멤버 RAII변수에 자원을 할당했는데,  생성자에서  exception발생 하더라도, 멤버의 소멸자 호출은 보장되어서
  문제 없이 자원이 반환됨

- `Singleton& s = Singleton::getInstance();`
  - 이때 getInstance의 return type이 Singleton&
  - 이경우 s는 그냥 이름만 붙이는 동작으로 보임 
    - 변수 선언의 참조type은 이름붙이는 작업으로 보임..
    - return type의 참조는 주소? return으로 봐야하나? -> 아닌듯, 그냥 임시객체 반환으로 보면될거 같음
  - **참조타입은 무조건 선언시 초기화가 되야함**
- `Singleton s = Singleton::getInstance();` 
  - 이건 Singleton 초기화니까, 복사생성자가 호출된다고 봐야할듯( 복사생성자의 param이 const Singleton& 니까)

## link

auto_ptr
:여기 링크 내용 좋은듯
<https://psychoria.tistory.com/42>

RAII개념
: notion c++기초의 생성자 예외에 내용이 더 좋은듯.
<https://modoocode.com/229>

자동으로 추가되는 함수 규칙
<http://egloos.zum.com/sweeper/v/2995404>

cpp 인터페이스
<https://igotit.tistory.com/entry/C%ED%81%B4%EB%9E%98%EC%8A%A4-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4-%ED%81%B4%EB%9E%98%EC%8A%A4-interface>

참조자 vs pointer
<https://gracefulprograming.tistory.com/11>

복사,대입연산자
: 포인터를 가지는 경우는 반드시 두개가 필요하다고 하네.
<https://link2me.tistory.com/1755>

const&
<https://rieulpost.tistory.com/54>

static 멤버 변수 정의
: 이거 몰랐었따
<https://m.blog.naver.com/tipsware/221676342281>

복사생성자
: 설명은 아는내용이고, 여기서 볼껀 책 사진찍은거.. 이런 내용이 나온 cpp책도 있네..
https://huiyu.tistory.com/entry/C-%EB%B3%B5%EC%82%AC-%EC%83%9D%EC%84%B1%EC%9E%90%EC%9D%98-%ED%98%B8%EC%B6%9C%EC%8B%9C%EC%A0%90

[1]:https://stackoverflow.com/questions/30687305/c-equivalent-of-using-t-extends-class-for-a-java-parameter-return-type
