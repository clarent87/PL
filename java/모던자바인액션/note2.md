# 모던자바 인 액션

## 8. 컬렉션 api 개선 (자바9)

- 컬렉션 팩토리
  - CreatingCollections 참조
  - 자바8
    - `Arrays.asList` 같은 api가 있었다.
      - 이 거 고정길이 List가 만들어 지므로. add 연산은 안됨 set으로 값 갱신은 가능
    - Set을 쉽게 만들어 주는 팩토리 api는 없었음
      - HashSet 생성자나 Stream으로 만드는 수밖에..
  - 자바9
    - 작은 리스트, 집합, 맵을 쉽게 만들수 있게 하는 팩토리 메소드 제공
    - `List.of , Set.of, Map.of , Map,ofEntries`
      - 이 api의 결과는 전부 불변 객체 이다. 즉 add, set 불가. -> 예외 발생함

- 컬렉션 처리
  - 리스트, set
  - 맵
    - HashMap 성능

- 개선된 ConcurrentMap

## 9. 리팩터링, 테스팅, 디버깅

- 가독성 리팩토링
  - 익명을 람다로
    - > 안되는 case 있음
  - 람다를 메소드 참조로
  - 명령형 데이터 처리를 스트림으로.
    - > break, contiue, return 등을 모두 고려해서  스트림으로 치환하는것은 쉬운일이 아님. -> 도구들이 있긴한가봄..

- 유연성 개선
  - 조건부 연기 실행(conditional deferred execution), 실행 어라운드 패턴 관련 내용
  - > 로거 예제 좋네. 이거 mvc1 강좌의 로거의 내용와 의미적으로 비슷한 부분이 있음

- 람다로 디자인 패턴 리팩터링
  - 전략
  - 템플릿 메서드
  - 옵저버
  - chain of responsibility
  - 팩토리

- 람다 테스팅
- 디버깅
  - .peek

## 10. 람다를 이용한 도메인 전용 언어

- 도메인 전용 언어
  - > dsl 의 분류 및 개념 정도..
- 최신 자바 API의 작은 DSL
  - > 결국 dsl은 그냥 class 만든거라고 보면될듯. steam api로 data를 저리하기 위한 dsl 이라고 함..
  - > 즉, 특정 도메인의 문제를 쉽게 처리할수 있도록 잘 추상화 시킨 class. ( 근데 fluent 적인 특징? 있는게 특징인거 같기도?.. 아닌가.)
- 자바로 DSL을 만드는 패턴과 기법
  - > 예시가 핵심인데?
  - DSL 패턴 장단점 표 (353)
    - 메서드 체인
    - 중첩 합수
    - 람다를 이용한 함수 시퀀싱
- 실생활의 자바8 DSL

결국 내부 DSL의 개념. DSL의 패턴을 소개함  

## 11. null 대신 optional 클래스

`Optional<T>` 에 대한 소개

- null 대신 항상 Optional을 쓰는건 좋지 않을수 있음.
  - 코드 컨텍스트상 변수의값이 null이 가능한 case에 사용하는게 좋다. 
  - 만약 반드시 null이면 안되는 변수라면, 그냥 에러 나게 두는게 좋다.
- 초기화를 위한 method 들이 준비 되어 있음
- map, flatmap 지원함. 스트림의 그것과 유사
  - **중요 point는 값이 없을때는 아무런 연산이 일어 나지 않는다는것!**
    - 그래서 값이 null인지 아닌지 체크 없이 map 연산을 수행할수 있음
    - > 다른 optional 의 연산들도 비슷한 개념이 지원된다. 기본적으로 if문으로 null check하는 것을 없애려는 거라서.
- 기본적으로 Optional은 반환값을 위해 설계된것, 즉 field 변수를 Optional로 두는것은 설계에 고려되지 않음 (377)
  - 그래서 optional 변수는 직렬화가 안됨.
  - 그럼에도 저자는 class에 optional 변수 쓰는것을 권장
- (자바9)
  - Optional에 stream method가 추가됨 (378)
  - > 이거 유용하겠음
- 디폴트 액션 and unwrap
  - wrapping 푸는 여러 api 제공함 (379)
  - (자바9) ifPresentOrElse

- filter도 지원
  - 스트림의 그것과 유사 하긴하지만.. 동작이 일단 특이한 부분이 있어서. 잘 이해 해야함

- Optional class의 메소드 표 (383)
- 실용적인 예제
  - > 내용 좋음. ReadPositiveIntParam

이번 장은 실제 코딩을 해서 익숙해 져야 할것으로 보임

## 12. 새로운 날짜와 시간 API

## 13. 디폴트 메서드

## 14. 자바 모듈 시스템
