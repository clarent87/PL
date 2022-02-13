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

java.time에 있는 각종 api 소개

- 불변 클래스 (396)
  
사용해 보지 않으면 이해하기 어렵고, 내용이 크게 중요하지 않을거 같음

## 13. 디폴트 메서드

- interface에 static method, default method 추가됨
  - 왜 쓰는지는 대강 알고..
  - default method는 주로 라이브러리 설계자들이 사용

- 자바8에서는 인터페이스에 static method 가능하므로, static method가 정의된 Collections같은 유틸리티 class를 없애도되지만
  과거 버전의 호환성을 위해 유틸리티 클래스는 남겨둠.

- 바이너리 호환성, 소스 호환성, 동작 호환성 (416)
- (417) 내용 중요
- 디폴트 메서드 활용 패턴 (419)
  - optional method :
    - 자바 8 이전에는 interface에서 필요없는 method더라도 impl에서 빈 구현을 했었음
    - 이제는 interface에서 default method를 주면 되므로.. 안 그래도 됨
  - multiple inheritance of behavior
    - 다중상속 가능하다는 얘기고. (물론 class 상속은 하나 + n개의 인터페이스를 이용)
    - 예시 (421)에서 템플릿 패턴 비슷하게 default method를 사용하는 것을 보임

- 같은 시그니쳐 default 메소드를 impl 했을때 뭐가 호출? (424)
  - 퀴즈(427) 중요
  - 신규 문법이 나옴.

- 기본적으로 c++와는 다르게 interface는 변수를 선언하지 못하므로, 다이아몬드 문제가 규칙 3개로 나름 쉽게 해결됨

## 14. 자바 모듈 시스템 (자바9)

> 여기는 소스가 없음

- 추론하기 쉬운 SW (434)
  - 관심사 분리
  - 정보 은닌

대충 모듈 수준에서 가시성을 만들어 주는 형태.  
이거 없었을때 문제점이 중요할거 같다. ( jdk랑 클래스 경로 지옥 문제)
그리고 메이븐 예시는 한번 볼만함  

> spring java 9 이상 선택하면 모듈 시스템 쓰이나?
  
기본적으로 module-info.java가 핵심인데, 이게 없으면 자동모듈이 되어서 모듈의 모든 내용을 공개하는 형태가 된다고함.  
  
## 15. CompletableFuture와 리액티브 프로그래밍 컨셉의 기초 (자바9)

아직 까지는 크게 구체적인 내용은 없음 ( 뭐가 자바9 인지 판단이 안됨)

- Future 형식의 API
- 리액티브 형식 API
  - > 이거 예제는 비동기도 아니고, 병렬도 안된다..
  
이해가 안가는 내용들이 꽤 있는데. 일단 핵심은 core 수만큼은 계속 thread를 돌리는 거아닌가 싶네..  
i/o같은거는 어떻게 비동기로 처리하지?? -> 운영체제 nonblock i/o이용.. 이걸 지원하는 java api가 필요  

- box and channel model
  - 동시성 모델을 설계하고 개념화 하는 방법( 그림 그리는 방법임)

- CompletableFuture 와 combinators
- CompletableFuture (483)
  - future를 조합
    - composablefuture라고 해야 하지 않나? -> 아닌 이유가 나옴
  
역시 예시의 장점이 이해는 가지 않는다..
  
- 리액티브는 기본적으로 옵져버 패턴이랑 거의 유사하네..
  - 이번장의 내용많으로는..
  
이번장은 16,17을 위한 사전 소개 인듯..

- 중요 link
  - <https://umbum.dev/1080>

## 16. CompletableFuture : 안정적 비동기 프로그래밍

- CompletableFuture 사용법 (503)
  - > complete로 값을 넘길수 있음
  - > 일반 Future는 어떻지? ( 값 세팅하는걸 본적이 없음..)
  - > 예외 핸들링이 중요 하네. (505)
    - > thread에서 발생한 예외는 해당 thread에서 처리해야 할듯.. 해당 thread 예외를 전역 exception handler로 보낼수가 있나?
  - > get 대신 join씀 (509)

- 비동기 api 만들기
- 비블록 코드 만들기
  - BestPriceFinderMain
- type 추론 검토 필요. (람다 및 제네릭)
  
- (512)에 병령스트림 보다 CompletableFuture가 장점인 부분이 나옴
  - custom executor 사용가능

- (513) 스레드 수 조절 방법 나옴
  - > 근데 스레드는 cpu지원하는 스레드만큼 할당하는게 좋은거 아닌가?
  - > 아니면 block 당할거 고려해서 더 만들어 두나?? 짜파 쓰레드도 라운드 로빈으로 교체 될테니..?

- (514)
  - 언제 병렬스트림을 써야 하는지, 언제 completablefuture를 쓰는지 나옴
    - > 병렬스트림은 forkjoinpool의 기본 pool을 씀 (이거 쓰레드 수가 작나봄./)

- 병령 스틑림 vs completablefuture ( 514 )
  - > 이거 매우 중요 point  
  
뒷쪽 부터 예제가 난해 한듯

- thenApply, thenCompose(521), thenCombine(486)
  - 이건 completableFuture를 만드는 연산이지 실행 연산이 아님
  - 둘다 function을 param으로 받음. 즉 future가 실행되면 param으로 받은 람다가 수행되는것.
  - > param으로 람다를 받는데. 이때 람다의 param 이랑 return은 ? -> 보통 function type 람다이므로 직전 job의 return(get으로 받는) 게 param으로 들어옴
  - > thenApply나 thenCompose나 뭔차이지..

- get vs join
  - <https://tedblob.com/completablefuture-join-vs-get/>

- thenApply vs thenCompose
  - <https://stackoverflow.com/questions/43019126/completablefuture-thenapply-vs-thencompose>
    - > 이거 답변이 잘나와 있네.. thenCompose는 flatmap 같은 개념임.
  - (522)
  - <https://umanking.github.io/2020/10/15/java-completable-future/>
    - > 이거 진짜 좋다. 책보다 나은듯. 예외처리도 마지막에 조금 나옴

- thenApply vs thenApplyAsync
  - <https://stackoverflow.com/questions/47489338/what-is-the-difference-between-thenapply-and-thenapplyasync-of-java-completablef>
  - 풀을 어떤걸 쓰냐 및 스케쥴링의 차이.
    - > 그래도 아직 이해가 애매하다. 비슷한 얘기는 523에도 나옴
    - > asynce 아닌것은 같은 스레드 풀에서 바로 실행하고. async는  prejob이 끝나고 async의 람다를 쓰레드 풀에 제출하는 거 같음.. ( 해당 task는 스케쥴링이 다시 됨)

- thenCombine 소개(522)

> SuppressWarning unchecked 때문에 코드에서 에러 unchecked인줄 착각한거 있었음..  
  
- 👍 completableFuture에서 제공하는 thenApply 같은 것들은..
  - > 원래 logic을 쪼개서 i/o 있는 부분 아닌 부분들을 나누어서 completableFuture로 만드는데 도움을 주는.. 그런거 같음

completableFuture는 많이 써봐야 알수 있을거 같다.  
주의점 정리 필요 ( 병렬스트림보다 유리 할때 등등..)
병렬스트림의 풀 뭐였는지 확인 필요

- (자바9) 타임아웃 (525)
  - (498)에는 future의 get으로 타임아웃을 걸었음
  - > completeOnTimeout에 세팅하는 default 값은 get으로 받을떄 나오는 T 타임의 결과 일듯

- stream에 toArray 있네..

## 17. 리액티브 프로그래밍 (자바9)

- 리액티브 애플리케이션 vs 시스템 (538)
  - 애플리케이션은 이벤트 주도
  - 시스템은 메시지 주도

> 예제가 쫌 난해 하네.

주제 자체는 당장은 필요 없는데, 개념적인 측면을 이해해보는 목적으로 진행 ( 결국 옵져버 패턴이랑 같긴함.)  
  
- observable은 map, filter 함수 제공하는데 언제 이게 동작하는지?

## 21. 결론 그리고 자바의 미래

- 자바 10 
  - 지역 변수 추론 : 초기값이 있을떄만 가능

> 앞선 내용들을 정리해주는 챕터

## A.기타 언어 업데이트

- 어노테이션 반복
- java8의 제네릭 param 추론 기능 강화

## B. 라이브러리 업데이트

- map의 computeIfAbsent
- 여러 스레드에서 읽기 동작보다 갱신 동작을 많이 하면. atomic class보다 LongAdder, LongAccumulator 사용을 권고
- ConcurrentHashMap
  - foreach, reduce, search 제공하는데 병렬성 한계값을 세팅해서 사용하는 거라고 함 (669)
