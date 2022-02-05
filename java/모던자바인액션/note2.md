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
- 최신 자바 API의 작은 DSL
- 자바로 DSL을 만드는 패턴과 기법
- 실생활의 자바8 DSL