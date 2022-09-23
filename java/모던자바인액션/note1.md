# 모던 자바 인 액션

- [모던 자바 인 액션](#모던-자바-인-액션)
  - [1. 자바 8,9,10에 무슨일이 일어나고 있는가](#1-자바-8910에-무슨일이-일어나고-있는가)
  - [3. 람다 표현식](#3-람다-표현식)
  - [4. 스트림 소개](#4-스트림-소개)
  - [5. 스트림의 활용](#5-스트림의-활용)
  - [6. 스트림으로 데이터 수집](#6-스트림으로-데이터-수집)
  - [7. 병렬 데이터 처리와 성능](#7-병렬-데이터-처리와-성능)

## 1. 자바 8,9,10에 무슨일이 일어나고 있는가

## 3. 람다 표현식

- 람다 규칙
  - 아래중 틀린것은?

  ```java
  () -> {} // void 리턴
  () -> "Raoul" // 문자열 반환
  () -> {return "Mario";} 
  (Integer i) -> return "Alan" + i; // 틀림. statement는 {}및 ;가 필요
  (String s) -> {"Iron Man";} //틀림 expression인 경우  (String s ) -> "Iron man" 이라고 해야함 아니면 return을 쓰던지
  () -> System.out.println("test") // 한개의 void method 호출은 중괄호 필요없음 
  ```

- 함수형 인터페이스
  - 정확히 하나의 추상 메서드만 있는 인터페이스
    - default method가 여러개 있어도 괜찮음. 단 오직 하나의 추상 메서드만 있어야함
    - 이경우 람다를 사용할수 있다.

- 함수 디스크립터
  - abstract method의 signature는 사실 람다 표현식의 시그니쳐가 된다. ( method signature는 decomplie할때 많이 봣음)
  - 즉, 람다 표현식의 시그니쳐가 있는 메서드의 시그니쳐를를 함수 디스크립터라고 함
    - 즉, 람다 표현식에 매칭되는 추상메서드의 시그니쳐가 함수 디스크립터임
    - 결론 추상메서드의 시그니쳐 = 함수 디스크립터
  - > `() -> Integer` 처럼 책에서 signature를 표기하는데 이거 유용한거 같다. 이를테면 predicate 같은거에 람다 잘 썻는지 비교할때..

- 실행 어라운드 패턴 (execute arround)
  - 초기화/준비 코드, 작업, 정리/마무리 코드
    - 이 형태인경우 실행 어라운드 패턴을 쓰면 작업부분을 strategy pattern 처럼 교체해서 쓸수 있음
    - ExecuteAround class 참조
      - 쨋든 람다 이용하는거

- `@FunctionalInterface`
  - > TODO: 이거랑 람다를 변수에 할당하는거 알아봐서 정리 필요
- `try-with-resource`

- java.util.function 패키지에는 여러 함수형 인터페이스 제공
- 자바8은 오토박싱을 피할수 있는 특별한 한수형 인터페이스도 제공 (103)
  - 보통 제네릭을 쓰고 있는 인터페이스는 참조형 type만 제네릭에 전달가능.. ( primitive가 return되거나 하는 경우는 오토 박싱 진행됨.. 이거 비용임)

- 함수 인터페이스 정리 (105)
  - 특화 인터페이스 (103)
  - > Comparator 는 표에 없네.. 이것도 여러 default method 제공

- 예외
  - 람다에서 예외 던지고 싶다면 추상메서드 정의에서 throws 로 예외를 정의해야함
    - 그렇지 않으면 람다 안에서 try/catch로 예외를 처리해야한다.

- 람다 형식 추론 (108)
  - 자바가 람다 형식 추론을 어떻게 하는지 소개
  - 결국 추상메소드의 시그니쳐를 람다의 형식으로 추론하는 것!
  - > 근데 제네릭 일땐 어떻게 추론해야 하는건지 궁금했음. 추상메소드에 제네릭의 실제 type은 없기때문에 람다를 보고 추론해야하잖아..
    - > 이건 제네릭 추론에 엮이는 문제 같음. 아마 좌변의 변수 type을 이용해서 추론하는 것일듯. -> 아래 형식 추론 참조

- 람다 void 호환 규칙 (110)
  - `Consumer<String> b = s -> list.add(s);`
    - > ;는 람다식의 것이 아님
    - 이경우 Consumer는 void 반환값을 갖는데, list.add(s)는 boolean을 반환. 그래도 유효한 코드임
    - 즉, 람다 바디의 일반 표현식은 void를 반환하는 함수 디스크립터와 호환됨

- 퀴즈. (111) 👍

  ```java
  execute(()->{}) // 아래 둘중 뭐가 걸릴까? -> 명확하지 않기때문에 이럴땐 execute((Action)()->{}) 이렇게 캐스팅 필요
  public void execute(Runnable runnable){
      runnable.run();
  }
  public void execute(Action<T> action){
      action.act()
  }
  ```

- 형식 추론
  - 람다 쓸때  `(a,b) -> {}`처럼 a,b의 타입이 없어도 되는 이유
  - 컴파일러는 함수 디스크립터를 알수 있으므로, 람다 시그니쳐를 알고 있기 때문에 생략가능
  - 근데 명시적으로 type을 주는게 명확할 때도 있음 👍
  - **람다 형식 추론 대상 파라미터가 하나 뿐이면, 해당 파라미터명을 감싸는 괄호도 생략가능**

- 지역 변수 캡쳐
  - > heap에 생성되는 인스턴스 변수는 캡쳐되는게 아님. 모든 쓰레드에서 heap은 공유.
  - 익명class일때랑 같음 final 변수만 캡쳐 가능
  - 람다는 값이 단 한 번만 할당되는 지역변수만을 캡처할 수 있으며,
  - 만일 람다에서 캡처되는 지역변수의 값을 재할당되는 경우 컴파일 에러가 발생한다.
  - 즉, 명시적으로 final로 선언되었거나, 실질적으로 final인 지역변수만 람다식 바디에 들어올 수 있다는 것이다.
  - <https://github.com/woowacourse-study/2022-modern-java-in-action/issues/22>
  - 원리
    - final 지역 변수를 쓰면 지역변수에 접근하는것이 아니라 변수 값이 람다로 넘어가는 거라고 함

- (추가) 람다식은 호출 시 매번 객체가 heap에 생성되는가?
  - 값 캡처하지 않으면, 싱글톤인데,, 캡쳐하게 되면 매번 생성되는듯.. 
  - 근데, jvm 스펙상 동작이 정확하게 나오지는 않았나봄.
  - https://stackoverflow.com/questions/27524445/does-a-lambda-expression-create-an-object-on-the-heap-every-time-its-executed

- 메서드 참조
  - 람다보다 가독성이 좋아서 쓴다고함
  - 람다 body에서 특정 method하나만 호출하였을때 사용가능

- 메서드 참조 만드는 법 (115)
  - 정적 메서드 참조
  - 다양한 형식의 인스턴스 메서드 참조
  - 기존 객체의 인스턴스 메서드 참조
  - > 생성자, 배열 생성자, super 호출에서 사용할 수 있는 특별한 형식의 method 참조도 있음

- 메서드 참조로 바꾸는 법 (117)
- 메서드 참조 호환성 확인 (117,118)
  - > 이부분은 내의견
  - 호환성 확인 이해가 어려운 부분은 2번 형태인데
  - `(List<String>, String) -> boolean` 함수 디스크립터가 있을떄 `List::contains`를 사용했다면
    - contains의 함수 디스크립터는 `(String) -> boolean` 이기 때문에 첫번째 param을 인스턴스로 활용했을시 함수 디스크립터가 맞음을 알수 있음
    - > 121 장 참조해보니 이런식의 논리로 호환성 확인하는듯.

- 생성자 참조 (119)
  - `()->Apple`같은 함수 디스크립터가 있다면 `Apple::new`를 사용가능

- 람다 표현식을 조합할수 있는 유용한 메소드 (124)
  - 그냥 함수 인터페이스에서 제공하는 여러 default method들이 있다는것.
  - > 근데 사용법은 한번 써보지 않으면 정확히 기억하기 어렵다.

## 4. 스트림 소개

일단 스트림을 쓰면 멀티쓰레드와 락을 신경안써도된다.  
스트림 api는 비싼 연산이다.

- 중간연산, 최종연산
  - 중간 연산 : filter, map, limit 같은거
  - 최종 연산 : collect, foreach, count
  - **중간 연산은 최종 연산 호출 전까지는 수행되지 않음**
  - 표는 (153) 에 존재

- 스트림은 질의를 수행할 데이터 소스가 있을때 사용하는 듯
- 스트림 파이프라인 개념은, 빌더 패턴이랑 비슷

## 5. 스트림의 활용

스트림관련 기능들 소개  
  
- 필터링
  - .filter : predicate필터링
  - .distinct : 고유요소 필터링 (중복제거)
    - 스트림에서 만든 객체의 hashcode,equals로 중복 확인

- 스트림 슬라이싱 (자바9) (158)
  - .takeWhile : 스트림이 이미 정렬되어 있을떄 사용 ( filter의 경우 스트림이 정렬되어 있던 말던 전부 순회함)
  - .dropWhile : 스트림이 이미 정렬되어 있을떄 사용
  - .limit : n개 요소만 선택
  - .skip : 처음 n개 요소를 제외

- 매핑
  - .map : 변환에 가까운 매핑이라는 단어로 쓴다. ( 그냥 함수의 return으로 값이 나오는 것)
  - .flatmap : 스트림을 하나의 스트림으로 만들어 줌

    ```java
        words.stream()
        .flatMap((String line) -> Arrays.stream(line.split(""))) // 람다 시그니쳐를 보면 string -> stream 임. 즉 스트림 결과를 뽑아서 하나의 스트림으로 만들어줌
        .distinct()
        .forEach(System.out::println);
    ```

    > 여기는 퀴즈를 풀어보는것이 좋다. (166)

- 검색 과 매칭
  - .anyMatch : 이거 최종연산임
  - .allMatch : 이거 최종연산임
  - .noneMatch : 이거 최종연산임
  - .findAny : optional 반환
  - .findFirst : optional 반환
    - 순서가 있는 스트림에서 사용하면 유용
  - 위 모두 쇼트서킷 기법이 적용됨
    - a && b 연산처럼 a가 false면 b는 판단안하는 기법
    - 무한 스트림에서 중요한 포인트임
  - 병렬 스트림에서는 findFirst 보다는 findAny를 써야함 ( 병렬은 순서가 없다)

- 리듀싱
  - 스트림의 모든 요소를 처리해서 값으로 도출하는 기능 ( 함수형 언어에서는 fold라고 부름)
  - .reduce -> 터미널 연산
    - 초기값 및 `BinaryOperator<T>` 를 인수로 받음
    - 초기값 안받는 버전의 경우 optional을 반환
  - 합 : `Integer::sum` 을 reduce의 인수로 넣으면된다.
  - 최대값 : `Integer::min`
  - 최소값 : `Integer::max`
  - > param 3개 짜리도 존재
  - > 기본적으로 immutable 연산임 (불변형 연산) (207)

- reduce 메서드와 병렬화 (174)
  - reduce를 병렬화 하기 위한 조건이 있음
    - 람다의 상태가 변하면 안된다.
    - 연산이 어떤 순서로 실행되더라도 결과가 바뀌지 않아야 한다.

- 상태 있음 vs 상태 없음 (175)
  - map, filter
    - 입력->출력 형태. 따라서 이들은 보통 stateless operation임
    - 당연히 람다,메소드참조 내부에 가변 상태가 없다는 가정이 있음
  - reduce, ( sum, max )
    - 연산의 결과를 누적해야할 내부 상태가 필요
    - 내부 상태 크기는 bound(한정) 되어 있음
      - > 각연산의 return의 크기가 고정이라는 말같음..
  - sorted, distinct
    - 스트림의 요소를 정렬하거나, 중복을 제거하려면 과거의 이력을 알고 있어야 함
    - 즉 모든 요소가 버퍼에 추가되어 있어야함
    - 이 경우 data stream의 크기가 크거나 무한이면 문제 발생
    - 이런 연산을 stateful operation이라고 함

- 중간 연산 최종 연산 표 (176)
  - > 👍

- 숫자형 스트림
  - 박싱 비용 제거용
    - 즉, 원래 stream은 Integer같은 참조타입만 가능하므로.. int값들은 모두 boxing됨. 이런 boxing을 없애기 위한게 특화 스트림
  - 특화 스트림이 제공됨 -> 104p와 유사
  - IntStream, DoubleStream 등등이 있고, 이걸 쓰면 .reduce 없어도 되도록 .sum같은 함수가 제공됨
  - 기본 스트림을 특화스트림으로 만들려면..
    - .mapToInt 같은 중간연산을 쓰면된다.
  - **특화 스트림의 모든 연산은 특화된 type으로만 진행된다.**
    - 즉.IntStream map에 들어가는 람다 형식도 IntUnaryOperator 만 받음.
  - 특화스트림을 기본스트림으로 복원하는 법
    - 특화 스트림의 `.boxed()` 이용하면 `Stream<Integer>` 처럼 boxing된 스트림 나옴
  - 특화 스트림 버전의 optional
    - 특화 스트림에서 값이 0이 나왔다면, 이게 연산의 결과가 0인지 아니면 값이 아에 없었던건지 모름
    - 그래서 나온것들
    - OptionalInt, OptionalDouble 등등 있음 (183) , 코드 NumericStreams 를 참조
      - > ex: 특화 스트림의 .max를 썻을떄 위 특화 optional이 반환된다.
  - 숫자 범위
    - IntStream, LongStream에서 제공하는 기능
    - .range, .rangeClosed 제공 -> static method임  

- 스트림 만들기
  - 값, 배열, 파일, 함수를 이용한 무한 스트림 만들기(BuildingStreams참조)
  - 값으로 스트림 만들기 : Stream.of 사용
  - (자바9) null이 될 수 있는 객체를 스트림으로 만들기 : Stream.ofNullable
  - 배열로 스트림 만들기 : Arrays.stream 사용
  - 파일로 스트림 만들기
    - 자바의 NIO api (비블록 i/o) 도 스트림 api가 추가됨
    - ex: Files.lines api
  - 함수로 무한 스트림 만들기 ( 보통 limit랑 같이 씀)
    - Stream.iterate
      - 인수로 초기값, 람다를 받음
      - 기존 결과에 의존해서 값을 순차적으로 만들어냄
      - 무한 스트림 = unbounded stream
      - (자바9) iterate에서 predicate 지원
        - 인수를 3개를 받게 됨. 초기값, predicate, 람다
        - predicate가 true일때까지만 돈다.
        - predicate대신 .filter를 무한스트림에서 이용하면 같은 결과 나오지 않나? -> no
          - filter는 언제 연산을 중단해야 하는지를 알수가 없다. ( 생각해보면 당연.. filter는 모든 요소에 적용되는것)
        - .takeWhile(스트림 쇼트서킷 지원)을 대신 쓰는것은 괜춘
    - Stream.generate (193)
      - iteratre랑은 다르다. 각 값을 연속적으로 계산하는 형태가 아님. 그냥 매번 생성하는 것
      - 인수로 supplier를 받음
      - > 발행자는 상태가 없어야 하는데, 상태를 만드는 것도 가능. 이러면 병렬처리에는 문제가 발생 -> 7장에서 나옴
      - IntStream 류도 generate 지원. 이경우 IntSuppler를 써야함
      - > 책 예제에서는 supplier 대신 익명 클래스를 이용해서 상태를 만드는 것을 보여줌 ( 인스턴스 변수를 만들면되니까..)
      - > 이러면 mutable 상태의 객체가 되는것. iterate예시의 람다는 immutable 상태였음. 병렬처리를 하려면 immutable 객체여야 한다.
    - **limit 같은걸 같이 이용해 주지 않으면 최종연산에서는 아무런 값이 나오지 않는다.**
      - **무한 스트림의 요소는 정렬하거나 리듀스 할수 없다.** -> limit를 안쓸때 얘기 인듯
  - **stream은 autoCloseable이라서 try-finally가 필요없음**

## 6. 스트림으로 데이터 수집

> 일단 생략. 여기서는 collector 인터페이스 직접 구현 and 미리 구현된 Collector interface의 구현체 사용법을 다룸

- 기본적으로 중간연산의 작업을 collect에서도 진행할수 있는것으로 보임

- 용어
  - collect : 최종연산을 말함
  - 컬렉터(Collector) : collect 최종연산의 인수
    - 변환함수 : 컬렉터에 넘어가는 람다
    - > Collectors 는 미리 준비된 collector를 만들어 반환하는 method의 집합. 근데 뭐 다양한 method가 더 있기는 함

- Collectors 에서 제공하는 method의 기능은 크게 다음 3가지와 같다 ( static method. 미리 구현된 Collector interface의 구현체들인 Collector를 반환)
  - 스트림 요소를 하나의 값으로 리듀스하고 요약
  - 요소 그룹화
  - 요소 분할

- Collectors method 표 (223)
- reduce vs collect (206)

- 기타
  - <https://akageun.github.io/2019/08/06/java-stream-groupby.html>
  - group by의 thread safe 유무

- collectors.toMap의 경우 value에 null이 들어가면 오류남
  - https://stackoverflow.com/questions/24630963/nullpointerexception-in-collectors-tomap-with-null-entry-values

## 7. 병렬 데이터 처리와 성능

> 일단 생략
