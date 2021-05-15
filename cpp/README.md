# MOOC 정리 

- [www.isocpp.org](https://isocpp.org/)
  - cpp표준위원회가 공식적으로 운영하는 사이트
  - 여기 current iso c++ status 에서 현재 c++ 상태 확인이 가능하다. ( 버전 확인 가능 좋음 ㅎ )
- [www.cppreference.com](https://en.cppreference.com/w/) 은 표준문서 내용을 잘 설명하고 있다.
  
## 목차

### 기초

1. 기초
2. 기초2

### c++ 11/14/17 기본

1. [c++11/14기본문법-1](c++11,14기본문법(1).md)
2. [c++11/14기본문법-2](c++11,14기본문법(2).md)
3. [c++11/14기본문법-3](c++11,14기본문법(3).md)
4. c++11/14기본문법-4

### c++ 11/14/17 고급

### 따로 알아본 것

const참조  
https://boycoding.tistory.com/208

참조형이란?   
https://boycoding.tistory.com/207

new Cache?
: new 에서 ()안쓴 형태.. 
: new는 동적할당의미하고 ()나 {}를 안쓴건 초기화를 안한다는거 같음. 즉 new cache는 cache 구조체를 그냥 heap에 생성하고 끝?
: mutable없이 위문제 해결하는 법의 예제..
https://boycoding.tistory.com/204

### 궁금증.. 

java에서 제네릭으로 특정 base class의 하위 class만 사용가능한 class, method 만드는게 가능한데..
c++ 템플릿도 특정 class만 사용가능한 class, method 만들수 있나? ( type_traits 사용해야하나? )
> 정답 : enable_if이용한다. [link][1]

[1]:https://stackoverflow.com/questions/30687305/c-equivalent-of-using-t-extends-class-for-a-java-parameter-return-type