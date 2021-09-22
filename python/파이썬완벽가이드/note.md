# note

읽으면서 기억나는 것들 적거나, 키워드만 작성해둔다.

- [note](#note)
  - [1장](#1장)
  - [2장](#2장)
  - [3장 타입과 객체](#3장-타입과-객체)
  - [4장 연산자와 표현식](#4장-연산자와-표현식)
  - [5장 프로그램 구조와 제어 흐름](#5장-프로그램-구조와-제어-흐름)
  - [6장 함수와 함수형 프로그래밍](#6장-함수와-함수형-프로그래밍)
  - [7장 클래스와 객체 지향 프로그래밍](#7장-클래스와-객체-지향-프로그래밍)
  - [8장 모듈,패키지와,배포](#8장-모듈패키지와배포)
  - [9장 입력과 출력](#9장-입력과-출력)
  - [10장 실행 환경](#10장-실행-환경)
  - [11장 테스트 디버깅 프로파일링과 튜닝](#11장-테스트-디버깅-프로파일링과-튜닝)
  - [12장 내장함수와 예외](#12장-내장함수와-예외)
  - [부록 py3](#부록-py3)

## 1장

- 코루틴, 제너레이터는 호출시 객체 반환.
- dir() : 객체가 제공하는 method 나열 또는 모듈의 내용 나열 27p
- 이름이 밑줄로 시작하는 경우 31p
- 모듈 namespace
  ```python
  import string
  dir(string)
  # TODO: 근데 string 모듈 안에 있는 import문의 내용들도 string namespace에 들어 올까? 
  ```

## 2장

- 🤩 py3 문자열 인코딩
  - <https://dojang.io/mod/page/view.php?id=2462>

## 3장 타입과 객체

- 참조,복사 43p
- 객체 신원과 타입 40p
  - id, type 내장 함수 
- 1급객체 -> 함수형 프로그래밍 개념.
  - 45p 예시 신기
- 🌟 is, isinstance, ==,id ->40p
- 참조횟수 41p
- 🌟얕은 복사, 깊은 복사. immutable, mutable p42
- None
- min, max
- 문자열 p49
  - py3에는 encode는 문자열에만, decode는 바이트 데이터에만 존재
- format string.. 
  - > 이거 {변수이름} 쓰면 문자열에서 자동으로 해당 변수 넣어주는 것도 있었음
- 사전 53p
  - copy 함수, `list(m) # m은 사전`
- set은 순서가 없다. 
  - 즉, index및 분할 연산 안됨
  - 변경 가능 집합, 불가능 집합 있다.
  - 내장 합수 set, frozenset으로 만듬
- callable type p57
  - 사용자 정의 함수
    - 여러 attribute 존재. `__dic__, __code__` 등
    - > 여기서 global, clouser attribute 중요! p120 참조
  - 매서드 p59
    - class method, instance method, static method 존재
      - > 근데 class method, static method개념이 cpp,java에도 있었나?
    - bound method, unbound method
    - 🌟 python에서 method 호출 원리 나옴.
  - 호출 가능한 class와 instance , 60p
    - class 객체의 경우 `()`로 호출하면 `__init__()`에 의해 생성된 객체의 초기화 진행
      - > 객체 생성은 `__new__`에 의해 진행되고 `__init__`이 초기화담당
    - instance의 경우 `__call__()`을 정의하면 함수객체(functor)로 쓸수 있음 (함수 객체는 내가 적은 표현.. 아마 맞는 개념일듯) 
  - 클래스, 타입, 인스턴스
    - 일반적인 class의 type은 type으로 나옴 60p -> class FOO에 대한 `type(FOO)` 이 type이 나온다는 것
    - 각각의 attribute 61p
      - > 이거 알아두면 좋으니 항상 확인해 볼것
    - `__slot__` 을 클래스에서 쓰면 더 효율적 `__dict__` 가 안쓰이므로.. 
      - > class객체에도 dict가 있는데 slot을 쓰면 인스턴스 객체의 dict가 안쓰인다는 것일듯
- 매핑 타입 집합 타임, 53p
- 모듈 61p  
- 내장 객체
  - 제너레이터도 따로 객체 type이네,   
  - 마찬가지로 slice함수나 리스트의`[::stride]` 같은 확장 분할로 리스트 slicing하면 분할 객체가 반환됨 (근데 이부분은 잘 이해 안감)
  - ellipsis 객체 -> `[]`안에서 ... 쓸때 생성
- 객체 작동 방식 및 특수 메서드 65p
  - 왜 문자열 리스트 튜플이 같이 묶이는지?
  - +,- 연산은 어떻게 구현되는지?
- 객체 생성 및 파괴
  - `__new__` 로 생성 `__init__`으로 초기화 `__del__`은 객체 파괴될때 호출됨 
  - `del x` 하는 경우 x 객체의 참조횟수를 줄이는거지 반드시 `__del__`호출하는 것은 아님
  - `__new__`는 보통 immutable type을 상속받은 사용자 정의 객체나, 메타클래스에서만 사용
  - `__del__`은 락 해제, 연결을 끊는등 중요 자원 관리 문제를 다루는 상황에서 씀
- 객체의 문자열 표현 , 67p
  - repr, str의 대한 정확한 내용 소개
  - > 🌟 repr 는 eval으로 객체 생성이 다시 가능하게 문자열을 출력한다.  
  - > 그냥 int나 list를 str로 변경하려면 `str()` 쓰면됨
  - > 내부적으로는 정의한 `__str__()`,`__repr__()`가 호출되는듯
- 객체 비교 및 순서 매기기 , 68p
  - `__bool__`, `__hash__`
- 타입 검사
  - 추상 기반 클래스 , 인터페이스 정의에 주로 사용
  - `__instancecheck__`,`__subclasscheck__`
- 속성 접근 69p
  - `__getattr__` 등등등
- 속성 감싸기 및 기술자(descriptor) ,70p
  - `__get__`,`__set__` 같은게 정의되었을떄의 내용인데, 설명만 봐서는 모르겠네.. 7장에 자세히 나온다함
- 🤩 순서열 및 매핑 메서드 70p
  - `__getitem__`등 순서열이나 매핑객체(내장 매핑객체는 dict 밖에 없음)을 흉내내는 객체 만들때 씀
  - > 이부분 신기한 내용이다. 
- 🌟 반복 , 72p
  - `for x in s`의 원리 나옴
    - 객체가 foreach 지원하려면 반복자 객체를 반환하는`__iter__()`메서드를 제공해야함. 
- 수학연산, 72p
  - `__add__`, `__radd__`  차이 나옴 매우 신기
  - 🌟`__int__()` 같은 변환 메서드를 객체에 오버라이드 할수 있음. 이게 객체에 정의되었다고 해서 인터프리터가 자동 형변환을 해주진 않음
- 호출 가능 인터페이스 ,75p
  - `__call__` 정의 하는거 말함
  - functor나 proxy 생성에 쓰임
- 컨텍스트 관리 프로토콜
  - with문 말함
    - `__exit__` 의 경우 with문 블럭에서 나가거나 예외 발생시 모두 호출되네.
    - `__enter__` 의 경우 with문 진입시 호출되고 반환값은 as 지정자에 들어감
    - 즉 컨텍스트 관리 객체(with 문이랑 같이 쓰는..)는 위 두개가 정의 되어 있어야함
- dir, 76p
  - `dir()`은 객체 검사에 쓰이는데, 객체에  `__dir__` 를 재정의 해서 원하는 값만 노출가능
  - 이 경우에도 `__dict__` 속성을 검사하면 숨겨진 내용 모두 확인 가능

## 4장 연산자와 표현식

- 숫자에 대한 연산
  - 🤩 `5/2` py2에서는 버림 하지만, py3는 float 값으로 나옴
  - `5//2` 이건 2.5인데 여기서 소수점 밑을 버리는 연산임
- 🌟 반올림 78p
  - py3 에서는 굉장히 특이.. 알고있는 상식과 다르다.
- 순서열에 대한 연산, 80p
  - all, any, len, max, min, sum 등이 있음 
  - 🌟 +, * 연산은 의미가 다르니 주의
  - `c = x * 4`의경우 순서열 x의 내용을 4번 복사해서 list c를 만드는것 (x가 리스트인경우. 튜플이면 튜플 생김)
  - in, not in은 문자열에도 적용가능
  - min, max 는 `<` 연산자에 의해 순서가 결정되는 경우만 유효
  - sum은 모든 원소의 합인데, 항목이 숫자일 경우만 유효
  - 분할연산, 81p
    - >난해함
  - 순서열은 `<,>,==`등 로 비교가 가능. 즉, 각각 첫번쨰 요소 부터 n번쨰 까지 비교, 이떄 값이 서로 다르면 멈춤 ,38p
    - > 순서열의 값들이 같은지 비교 혹은, sub set인지 알아 볼때 쓰는듯.
    - 문자열일땐 사전 순서로 비교됨
      - py2는 바이트 문자열, 유니코드 문자열 두종류라서 여기에다 연산을 적용하면 예상과는 다를수 있음 
        - > =, + 등등 연산을 다른 type의 문자열에 쓰지 마라는것
        - > 물론 py2는 암묵적으로 형변환 하는데, py3는  typeerror를 발생시킨다.

- 고급문자열 포맷 지정 p88
  - > 이부분 꽤 기능이 많네.. format 쓰는법 인데 일단 무시
- 사전/집합/확장대입 에 대한 연산 
  - > 뻔한거
- 속성(.) 연산자
  - >  뻔한거
- 함수 호출() 연산자 92p
  - >  from functools import partial로  함수의 파라메터 일부를 고정해서 쓰는거 신기
- 변환 함수 92p
  - int, float 이런거... (문자열을 숫자 변환에도 사용)
  - `eval()`은 신기하네
  - > 앞서 나왔듯, 숫자 상수 연산은 자동 타입캐스팅이 되긴하는데, 객체에  `__int__` 오버라이드 했다고 객체를 자동 타입캐스팅 해주지 않음
  - > cpp에서는 유사한 형태면 casting 해줬음.. 이걸 뭐라 불렀는데.. 변환?
- 불리언 표시 및 진리값
  - 🌟 0이 아닌수, 비어 있지 않은 문자열, 리스트, 튜플, 사전 은 true로 간주 (false는 반대)
    - > 그렇다고 ==으로 True와 비교하면 같지 않으니까 False인데.   
    - > 만약 숫자 1인 경우는 True와 비교하면 True가 나오긴 함
- 객체 동등 및 신원
  - 🌟 `x == y` 에 대한 것. 일반적으로 값이 같은지를 확인
  - 🌟 `x is y` 메모리 상 동일 객체인지.. 
- 평가 순서
  - 즉, 우선 순위 95p
- 🌟 conditional expression (조건 표현식)
  - 복잡해서 안쓰는게 좋긴 한데, 리스트 내포에 쓰면 좋음
  ```python
  if a <= b:
    minvalue = a
  else:
    minvalue = b
  # 위 표현 대신 아래와 같이 쓸수 있다. 
  minvalue = a if a <= b else b
    
  ```

## 5장 프로그램 구조와 제어 흐름

- if문으로 함수의 두가지 버전 정의, 97p
- 🌟 for 문 
  - `for x in s` 이렇게 쓰고 s에는 리스트, 튜플, 문자열 또는
  - iterator를 정의한 객체 가능
  - 98p 참조. for문을 while로 구현한거 있음 (iterator이용)
  - for문의 x의 경우 이미 정의된게 있었다면 덮어 씌워지고, x값은 for문 밖에서도 유효
  - enumerate와 같이 써서 index를 받아서 쓸수도 있다.
- 🌟while문
  - 2개 이상의 순서열에 대해 반복을 돌때 zip을 사용한다. 100p
    - zip(s,t)의 경우 순서열 s 와 순서열 t를 합친 튜플 리스트를 만드는데
    - s와 t의 len이 다른경우는 둘중 작은거에 맞춰짐
    - 그리고 py2에서는 zip하면 큰 튜플 리스트가 하나 만들어지는데.. py3는 값을 한번에 하나씩 생성함
      - > 제너레이터?
- python은 goto문은 없다. 
- for-else
  - for가 break에 의해 중단되는 case외에는 else문이 돔
  - 언제 쓰냐?
    - 루프가 이른 시점에 종료되었을떄 flag나 조건을 설정하는 경우.. 
    - > 이런 경우 많이 있었음.. 보통은 반복문 안 if문에서 flag 세팅...  
    - > else쓰면 그럴 필요가 없다. 
- 예외
  - raise문 단독 사용시 최종적으로 생성한 예외 다시 발생 
  - > 즉 ,예외 forwarding인듯
  - 예외가 try, except에 의해 잡히지 않은경우 상위 block으로 넘어감, 거기에 try, except가 있을수 있으니.. 
    - 끝까지 잡히지 않는 `예외는 sys.excepthook()`으로 전달됨 13장에 나옴
  - 🌟103p 예외 타입 나옴
    - 그냥 `except:` 만쓰면 키보드 인터럽트등 까지 다 잡힘.
  - try - else
    - try 블록에서 예외가 안났을때 else 수행
  - finally
    - 에러 발생 유무와 상관없이 반드시 실행됨
    - 🌟 예외 발생시 제어 흐름은 except가 아닌 finally로 먼저 오고, 이후 except로 가는듯..
      - > 책 내용은 이런거 같음.. 제대로 이해한건지 확실치 않음

- 내장예외 테이블 , 105p
  - 계층형.

- 사용자 예외 정의 , 106p
  - Exception을 상속하면 됨 
  - `raise NetworkError("test")` 에서 test 문자열, 즉 parameter는 정의한 예외 class의 생성자의 param으로 전달됨
    - 이떄 사용자 예외 class의 생성자는 param을 여러개 쓸수 있음. 그 raise에서 사용할 때도 param을 여러개 넘겨야 함
  - 🌟 `__init__` 정의시 `self.args`세팅 매우 중요

- with 108p
  - with문에서 예외 발생시 `__exit__` param으로 정보가 넘어감.
    - 🤩발생된 예외가 처리 되었는지, 아닌지에 따라 `__exit__()` 의 반환이 False, True가 된다는데.. 
      - > 이부분 이해 안감 108p  
      - > 음.. 아래 코드를 통해 이해해 보면, `__exit__()`는 사용자가 정의 할수 있고, 이떄 넘어온 예외를 처리 했으면
      - > `__exit__()`함수의 return을 true로 코딩, 아니면 false로 코딩. 이렇게 false를 반환하면, with문 밖으로 error가 forwading됨.  
      - > 근데 보통의 경우 error는 None이라 return False여도 별 문제 없는듯. (None예외는 forwading될수 없어서?)
  - 컨텍스트 관리자
    - `__exit__()` 랑 `__enter__()` 구현한 class의 객체
    - `from contextlib import contextmanager` 를 이용하면 제너레이터를 컨텍스트 관리자로 만들수 있음
      - 예외 관련 부분이 중요 109p

- assert, `__debug__`
  - `if __debug__` 문을 쓸수 있는데, 이거 android if 매크로 NDEBUG랑 유사  
  - 즉 debug모드에는 위 코드가 추가 되는데, 최적 모드일땐 if문 이 아예 빠짐

## 6장 함수와 함수형 프로그래밍

이장에서 나오는것은 아래와 같다. 

- 함수형 프로그래밍
  - 함수, 유효범위 규칙, 클로저, 장식자, 생성기, 코루틴 , 기타 함수형 특징 
- 선언형 스타일 프로그래밍, 데이터 처리에 유용한것
  - 리스트 내포, 생성기 표현식 

  
- 함수
  - default param 쓸때 주의 필요
    - 아래처럼 객체가 할당되는 개념을 주의해야한다.(정의시 한번 할당됨, 사용때 할당되는게 아님) p112
    - 이걸 피할려면? default 값을 None을 주고 body에서 None일때 list를 할당받는걸로 해야함
    ```python
    def foo(x, items=[]): # 함수 정의후 실행하면 items는 list 객체가 할당됨
      items.append(x)
      return items
    foo(1)  
    foo(2)  
    foo(3)   # [1,2,3] 이 return 됨
    ```
  - 마지막 매개변수 이름 앞에 별표(*) 추가하면 함수는 여러 개의 매개변수를 받을수 있다. p112
    - > 인수가 튜플로서 전달됨. 이거 *arg 그거임, 파라메터 풀어쓰는거 그거
  - keyword argument , 113p
  - position argument, 113p
    - 위치, 키워드 인수 동시 쓸때는 무조건 위치인수를 모두 채우고 써야한다. 
    - 그리고 생략가능한 인수? 의 값들도 지정을 해줘야한다함.. 그리고 키워드 인수를 쓸수 있나봄 ( 정의말고 사용시.)
  - 아래 같은것도 있다. , 113p
  ```python
  def make_table(data,**parms) # 정의하지 않았던 키워드 인수가 모두 param dic으로 들어감
  ```
  - *args, **kwargs는 다른 함수에 대한 래퍼나 proxy를 작성하는데 주로 씀
  - 값전달 은 immutable일떄, 참조전달은 mutable 인수가 전달 될때 , 114p
    - > 값전달 처럼 보인다.. .라는 표현으로 나와있어서 책에.. 진짜 값전달인지는 모르겠음( 어짜피 immutable이라 값인지 참조인지 모르는거 아닌가..)
    - 이거때문에 sideeffect 발생하니 주의 한다. (특히 스레드 프로그래밍에서는 주의해야함)
  - return이 없으면 None객체 반환

- 유효범위 규칙
  - 함수가 실행될때 local namespace가 생성
    - 여기에는 매개변수 이름, 함수 몸체안에서 할당된 변수의 이름이 담김
  - 🌟local namespace에서 변수를 찾지 못했다면?
    - 전역 namespace -> 내장 namespace 순으로 찾고 그래도 없으면 NameError 발생
      - 함수의 전역 namespace란 `모듈`을 말한다. 
        - > 모듈은 그 이름으로 namespace가 생성되고 거긴 모듈 파일에 정의된 모든게 있다
  - global keyword
    - 함수안에서 전역 변수 접근시 사용 ( 전역변수 값 읽고 쓰기 가능)
  - python은 중첩함수 가능
    - 중첩함수는 함수안에 함수 정의 있는것
      - > 클로저에서도 쓰고, javascript에서도 있었음
    - 🌟 py2에서는 바깥쪽 함수의 변수를 안쪽 함수에서 재할당 할수 없다 , 116p
      - 즉 이경우 읽기만 가능
      - 안쪽 함수는 안쪽함수 scope랑 전역 변수만 값 재할당이 가능.
      - py3는 nonlocal keyword를 이용하면 바깥쪽 함수의 변수 재할당도 가능
    - 지역변수에 값 할당전 사용하면 UnboundError발생 , 117p
      - > 이거 나도 몇번 실수 했다.
    - > javascript에서는 중첩함수 안에서 바깥 함수 변수 접근이 되긴했는데, 만약 바깥 함수에 `{}`을 사용한 부분이 있다면 해당 부분에서 정의된 변수는 접근 불가

- 🌟객체와 클로저로서 함수 , 118p
  - 클로저 : 함수를 구성하는 문장과 실행 환경을 함께 묶은것
    - > 사실상 `__closure__` 속성이 있는 함수객체를 클로저라고 보면될듯  
    - > 즉 중첩함수를 반환하면 그게 클로저, 그냥 일반 함수 객체에 실행환경이 묶인 형태(아래)는 클로저라고 말하진 않을거 같음.. 일반적으로는.. 
  - 함수를 객체로 전달할때는 함수안에 `__globals__` 속성이 있다. (중첩함수 말고..)
    - 여기는 전역 namespace의 내용이 담김 ( 본인이 쓰는 전역 변수들..등등)
  - 중첩함수를 사용할때 클로저는 내부 함수 실행을 위한 전쳬 환경을 담는다. 119p
    - > 이말은 내부함수에서 외부 함수의 local namespace 정보를 일부 가져온다는 의미 같음 (위의 globlas처럼..) -> `__closure__` 속성에 나옴
  - 클로저와 중첩함수는 lazy evaluation에 사용
  - 🌟클로저 예시 및 `__closure__` 119p
  - 일반 class 함수랑 closure로 countdown 구현한 예제 120p
    - 실제 클로저가 성능히 50%더 좋음. 
  - 클로저는 언제 사용?
    - 기존 함수에 추가 기능을 넣을때 씀 -> 데코레이터
      - > 클로저의 내부 환경 기록 특징 때문에 가능하나봄  
      - > 약간 람다의 캡처 개념이라고  봐야 하나..

- 데코레이터 , 121p
  - 데코레이터는 기본적으로 중첩함수를 반환하는 형태로 구현 
    - 🌟 물론 class에 대핸 데코레이터 일때는 class 객체를 반환하게 해야함
  - 데코레이터는 여러개 사용가능, 각각 한줄씩 써야함
    - 이경우 적용 순서는 맨처음 줄의 데코레이터 부터 순차적으로 적용
    ```python
    @foo
    @bar
    @spam
    def grok(x):
      pass
    #는 다음과 같다. 
    grok = foo(bar(spam(grok)))
    ```
  - 데코레이터는 인수 받는거 가능 -> 이부분 중요 
    - 🌟구현상 데코레이터 함수의 인수 받는 부분이 기본 데코레이터랑은 차이가 있다 ( func를 받느냐, param을 받느냐 )
    ```python
    @eventhandler('Button')
    def handle_button(msg):
      pass
    # 위는 아래와 같다. 
    temp = eventhandler('Button')
    handle_button = temp(handle_button) # 인수 없는 버전은  handle_button = eventhandler(handle_button) 만 존재. 
                                        # (즉 인수 버전은 데코레이터 만들시중첩함수가 한단계 더 필요)
    ```
  - > 데코레이터 관련 해서는 옛날에 정리 했던거 있었는데,, 나중에 가져올 필요 있음  
  - > 그리고 데코레이터를 왜 사용해야하는지는 따로 다시 확인 필요 
  - > 원래 데코레이터가 원본 함수에 뭔가 기능을 추가하려는 건데, 이 개념으로 보면 인수가 있는 데코레이터는 중첩이 한단계 더 필요함.
  - 데코레이터는 재귀, 문서화 문자열, 함수 속성 등 함수와 관련된 다른 부분과 서로 기묘하게 작용 ( 이 장의 나중에 설명)

- generator and yield
  -  yield 키워드를 함수에서 사용하면 그게 generator
  -  🌟 generator는 반복에서 사용할 값들을 생성하는 함수
  -  py3에서는 `next()` 대신 `__next()__` 사용
  -  보통 generator 의 next를 직접 쓰는 일은 없다. 
     -  for, `sum()` 등 기타 연산에서 씀
  -  generator는 종료시 None을 반환하거나 StopIneration 예외를 발생시켜야 한다. 
     -  이렇게 되면 반복은 멈춤. 종료 순간에 None 말고 다른 값 반환하면 안됨
  - 만약 generator 객체를 쓰다가 (next 호출) 더 이상 generator 객체를 쓰지 않는 경우
    - 이떄는 close 함수를 호출해 주면 된다. 
      - close 이후 next 호출시 StopIneration 예외 발생
      - close 함수 호출 시점에 generator 객체에서는 GeneratorExit 예외가 나오므로 이것을 잡아서 추가적인 정리 작업 가능
        - 단, 이떄 예외처리에서 다시 yield를 잡아서는 안됨
  - 현재 genreator에서 반복을 수행하고 있는데,, 다른 스레드나 signal handler에서 해당 generator 객체에 close를 날리면 안됨.
    - > 즉 동시성에서 generator관리는 주의해야 한다는 거

- 코루틴과 yield 표현식
  - generator 와 코루틴은 yield 표현식 사용방법이 좀 다름
    ```python
    # generator
    def countdown(n):
      while n > 0:
        yield n # next 로 호출되면 n값이 반환됨. 그리고 여기까지만 실행됨
        n -=1
      return
    # 코루틴
    def receiver():
      while True:
        n = (yield)
        print("Got %s" % n)
    ```
  - 코루틴에서는 첫번째로 next를 호출해줘야 yield문 까지 감(여기까지 실행됨), 이후 send를 통해 값을 yield로 전달하면 된다. 
  - send를 받으면 코루틴은 다음 yield문까지 진행.
  - 여기서 next를 사용하는 것을 있어먹을수 있으므로, `@coroutine` 데코레이터랑 같이 쓰는게 일반적
    - 이거 쓰면 next 안써도 됨
  - close 나 exception은 generator와 동일
  - 단, throw를 전달할수 있는 부분은 차이가 있다. 
    - ex: 코루틴 r이 있는경우 `r.throw(RuntimeError,"test")` 로 코루틴 r에 예외 전달 가능. 
    - 이 예외는 코루틴 안에서 `except`문으로 잡아서 처리 가능
    - 그리고 이건 비동기적으로 다른 쓰레드에서 호출하거나 그러면 문제 생길수 있으니 주의
  - 🌟yield 표현식에 값을 줄수도 있다. ,127p
    - 동작을 잘이해해야한다. 
    ```python
    def line_splitter(delimiter=None):
      result = None
      while True:
        line = (yield result)
        result = line.split(delimiter)
    ```
    - 1. 일단 next 호출하면, yield문까지 실행하는데 이때 result값인 None을 출력
    - 2. send로 "A,B,C"를 전달하면 yield에서 받아서 line에 저장, 그 후line split 실행되고 다시 yield문에서 result 반환
    - 즉, `line = (yield result)`에서 result 반환 후 `line = (yield)`가 수행되는것
    - 코루틴이 이처럼 값을 반환하는 경우에는 throw 동작도 조금 다름.. 이부분은 127p 참조
  - > 활용처에 대해서는 129,130p에 나오는데 일단 생략  
  - > 병행 프로그램 작성에 사용가능하다는데.. 20장에 나온다함

- 리스트 comprehension , 130p
  - 리스트의 각아이템에 어떤 함수를 적용해서, 새로운 list를 만들때 씀.
    - > 🌟 map 함수도 비슷한 개념이었던거 같은데..  
    - > 이부분 이슈인거 같다. 
  - 리스트 comprehension에 for in if 를 반복해서 적을수 있음. 이부분의 해석은 아래와 같음
  ```python
  for x in a:
    if c:
      for y in b
        if d:
          s.append(표현식)
  ```
  - 🌟주의
    - py2에서는 `[x for x in a]`란 구문이 있을때, 만약 x가 밖에 있는 변수 였다면 그 x를 덮어 씀.
    - 이부분은 py3에서는 해당하지 않음 ,py3는 리스트 내포안의 변수는 내부(private)변수로만 씀

- 🌟 generator expression, 132p
  - 리스트 comprehension이랑 사용법은 똑같음. 단 `[]` 대신 `()`를 씀
  - 차이는 리스트 내포는 한번에 값을 생성해서 리스트로 들고 있다는것이고, 생성기 표현식은 next 호출시마다 값을 그때그떄 만들어 준다는것!!
  - 따라서 메모리 사용률에 이점이 있음
  - > 튜플을 만드는 comprehension은 없다!
  - generator expression은 `반복`을 통해 필요할 때 값을 생성하는 생성기 객체를 반환한다. 
    - `next()`를 호출해서 값을 하나씩 받을수도 있고 for문에 사용도 가능
    - > generator도 next를 직접쓰는 일은 없고 for문이나, sum 같은 함수에서 쓴다고 했는데, 이것도 마찬가지 인듯
  - 🌟 주의
    - 생성기 표현식은 순서열 처럼 작동하는 객체를 생성하는 것이 아님
      - 순서열 객체는 list, 문자열 이런거.. 
      - 따라서 append나 index같은거 안먹힘.. 
      - 필요하면 `list()`를 이용해서 list를 만들어서 써야 한다. 

- 🌟 선언형 프로그래밍, 133p
  - 리스트 내포와 생성기 표현식은 선언형 프로그래밍에서 볼 수 있는 연산과 깊은 관련이 있음
  - > https://boxfoxs.tistory.com/430
  - > 이거 엄청 중요하네!! 쥬식 만들때 매우 중요 할듯 ( 생성기 표현식!)
  - DB 접근에 관련된 모듈을 사용할때, DB 질의와 리스트 내포를 같이 쓰는 경우가 종종 있다. (17장 참조)

- lambda 연산자, 135p
  - 보통 간단한 콜백 함수 작성에 씀
  - 함수와 동일한 유효범위 규칙을 가짐
  - lambda의 body는 반드시 유효한 표현식 이어야 함
    - 즉, 여러 문장 안됨
    - for문 while문 같은 표현식이 아닌 문장은 쓸수 없음 

- 재귀
  - python 재귀에는 함수 호출 깊이 제한이 있다. 
    - `sys.getrecursionlimit()` 으로 깊이 확인 가능. 
    - `sys.setrecursionlimit()` 으로 값 변경 가능 (기본 값은 1000)
      - 이 값은 운영체제에서 설정된 스택 크기 제한을 넘을수는 없다. 
  - python 재귀는 꼬리 재귀 최적화 해주지 않는다. 
  - 재귀는 생성기 함수나 코루틴에서 제대로 동작하지 않는다. ,135p
    - > 당연한건데.. 왜냐면 생성기/코루틴은 yield 만나면 객체를 반환. 즉 그 뒤로 control flow 진행이 안됨
    - > 따라서 책 예제에서는 for 문을 이용해서 generator 함수 재귀의 정상 동작을 만들어냄 136p
  - 데코레이터랑 같이 쓰면 재귀 함수 호출시 모든 재귀에서 데코레이팅 된 함수가 호출됨
    - 따라서 lock 이나 동기화를 위해 데코레이터를 썻다면 재귀는 가급적 쓰지 않는것이 좋음

- 문서화 문자열
  - 함수의 첫번째 문장은 주로 함수의 사용법을 설명하는 문서화 문자열인 경우가 많다. 
  ```python
  def factorial(n):
    """Computes n factorial ~~ 이게 문서화 문자열.
    """
    if~~
  ```
  - 문서화 문자열은 함수의 `__doc__` 속성에 저장됨
  - 🌟 데코레이터를 사용한 경우 데코레이터 때문에 해당 함수의 `__doc__`가 제대로 동작 안함, 137p
    - `help(func)`를 하면 `__doc__`의 내용이 출력되는데 데코레이터로 func를 감쌋다면 정상적으로 나오지 않음
    - 이경우 데코레이터에서 반환하는 중첩함수의 `__doc__` 및 `__name__`을 원본함수의 값으로 할당해줘야 한다. 
    - 이게 빈번하게 필요해서 functools에 wraps 데코레이터로 제공됨

- 함수 속성
  ```python
  def foo():
    pass
  foo.secure = 1 # 함수 객체에 임의의 속성 secure를 만들어서 값을 할당
  foo.private = 1
  ```
  - 위와 같은 함수 속성은 `__dict__` 사전에 담긴다.
  - 함수 속성은 함수 객체에 추가 정보를 붙이려는 응용 프로임 워크 같은 특수한 곳에 사용됨
  - 앞선 문서화 문자열 처럼 데코레이터랑 사용하면 문제가 있으므로.. functools의 wraps 데코레이터랑 같이 쓰던지 (데코레이터 만들때 써야함)
    - 아니면 `call.__dict__.update(func.__dict__)` 를 쓴다. 자세한건 138p 참조

- eval, exec, compile
  - eval 함수는 표현식을 담은 문자열을 실행하고 그 결과를 반환
  - exec 함수는 임의의 파이썬 코드를 담은 문자열을 실행
    - py2에서는 exec 함수 사용시 괄호가 없어도 됨. py3는 괄호 필요
  - 네임스페이스는 caller의 네임스페이스 사용. but 함수에 네임스페이스 넘겨 줄수 있음 p139
    - > 모듈이 네임스페이스 랬지.. 이게 global, 그리고 함수안에 정의 되는게 local 근데 `__local__` 같은 속성은 함수에 없음. 아마 local은 인터프리터에서 관리?
  - 중첩함수 안에서 위함수 쓸땐 suyntaxerror 날수도 있음
  - compile은 생략.. 그냥 책봐라

## 7장 클래스와 객체 지향 프로그래밍

- 클래스 변수 p142
  - > cpp의 class static 변수라고 보면 될듯
- 클래스 객체가 네임스페이스 역할을 함.
  - 따라서 클래스 변수, 클래스의 메소드는 클래스 객체에 `.`연산으로 접근가능 p142
  ```python
  a = Account("Guido.",1000) # Account.__init__("Guido.",1000)
  a.deposit(100.0) # Account.deposit(a,100.0)
                    # . 연산에 의해 참조한 deposit method는 Account class의 namespace를 참조해서 얻음 (왜냐면 객체 a의 namespace엔 없어서)

  ```
- 객체에 `.` 연산을 쓰면 객체의 namespace를 뒤지고 그다음 자동으로 class의 namespace를 참조함. 143p 145p
  - 그래도 없으면 base class에서 찾음
  - > 이런 유효범위 규칙은 위에서도 나왓었음.

- 유효범위 규칙 p143
  ```python
  class Foo(object):
    def bar(self):
      pass
    def spam(self):
      bar(self) # 틀림
      self.bar() # 맞음
      Foo.bar(self) # 맞음

  #내가 추가함
  class test(object):
    fee = 100
    def test_method(self):
        print(self.fee) # 여기서 class namespae의 fee가 참조됨. 왜냐면 객체 namespae에 fee 속성이 없어서..

  a = test()
  a.test_method()
  ```
  
- 상속
  - base class가 없으면 object를 상속하면됨. `__str__()` 같은 몇몇 공통 메서드의 기본 구현제공
  - 🌟 아래 내용 중요
  - subclass에서 `__init__`을 재정의 해서 인스턴스에 새로운 속성 추가가능
    - > 여기 예에서는 속성 추가는 변수 추가를 진행하였다. ( 아마 다른것들도 가능은 할듯.. 예를 들면 method?)
    - > 🤩 근데, 책에서 속성이라고 표현하는 대부분의 예는 클래스/인스턴스의 변수에 대한 것7
  ```python
  class EvilAccount(Account):
    def __init__(self,name,balance, evilfactor):
      Account.__init__(self, name, balance) # base class의 init이 자동 호출되지 않기때문에, 명시적 호출 필요
      self.evilfactor = evilfactor
  ```
  - base class에 init을 정의 하지 않았다면, 위 예시의  `Account.__init__`는 없어도 됨
  - base class에 `__init__`이 정의 되었는지 모르겠다면 그냥 인수 없는 `__init__()`을 호출해도 된다. 
    - 항상 아무 일도 하지 않는 기본 구현이 제공되기 때문
  - 🌟override된 메소드의 원래 method 호출하고 싶다면?
    ```python
    class MoreEvilAccount(EvilAccount):
      def deposit(self, amount):
        EvilAccount.deposit(self, amount) # base class의 deposit method 호출 -> 근데 이건 deposit이 EvilAccount에 정의된건지 그 위의 base class에 정의된건지
                                          # 헷갈림. 실제로 이 예제에서도 deposit은 EvilAccount가 아닌 Account에 정의됨. 따라서 그냥 super를 쓰는게
                                          # 읽는 사람으로 하여금 혼란스럽지 않게 한다. 
        super(MoreEvilAccount, self).deposit(amount) # py2에서 super를 이용한 방식 (위와 의미 같음)
        super().deposit(amount) # 🌟py3의 방식
    ```

- 다중상속
  - 속성 검색(`.`연산)이 매우 복잡해짐.
  - 속성 이름이 같을때, 어떤 속성이 먼저 참조될지는 class의 `__mro__`(method resolution order)를 출력해보면 된다. 147p
    - > 기본적으론 subclass -> base class 순으로 탐색하고, 다중상속에서 먼저 상속된 것을 먼저 참조 한다.   
    - 이거 원리가 단순 dfs, dfs같은게 아니라 c3 선형화 알고리즘에 의해서 참조 순서를 정한다함. 
      - 따라서 상속 관계가 어떻냐에 따라, typeerror가 나는 상속 관계가 있을수 있음
      - 근데 보통 이런경우, 프로그램 설계에 심각한 문제가 있다는 것을 의미. 실전에선 거의 발생하지 않는문제 148p
      ```python
      class X(object): pass
      class Y(X): pass
      class Z(X,Y): pass # 이거 typeerror남, 일관된 메서드 분석 순석를 정하지 못하기 때문
      ```
    - 상속 class에 이름이 같은 속성이 있다면, self대신 직접 class의 이름을 명시 해주면 된다. 
      - > 🌟 근데 책의 p146예를 잘봐야 하는데, 책의 예에서는 base class의 method안의 self.fee가 문제를 일으켰음. subclass꼐 아니라..
  - 왜 다중상속을 쓰는지?
    - > 음.. 뭔가 상속을 위해 제공되는 class들이 있나봄. 이런 class는 직접 객체를 많들어 쓰지 않고, 상속해서씀.. 
    - > 이걸 책에서는 "혼합 클래스"라고 부르는것 같고, 혼합 클래스 여러개를 상속해서 기능을 구현하기도 하니까 다중상속을 쓴다는듯.  
    - > 즉, 혼합 클래스는 추가 기능을 제공하기 위한 목적으로 단른 클래스에 혼합될 메서드를 정의한다.. 라고 함

- 다형성 동적 바인딩과 dock type
  - > 별얘기 아니고 dock type에 대한 말. 즉 `objc.attr()`란 코드가 있다면 objc는 어떤 객체가 와도 상관없음  
  - > 단. attr method 만 있으면됨. 즉, 속성 검색에서 attr란 메소드가 검색되기만 하면된다.   
  - > 이런 형태는 의존성을 줄이는데 도움될듯.

- 정적 메서드, 클래스 메서드
  - 기본적으로 class에 정의 되는 메서드는 인스턴스 메서드로 간주된다.
    - > 그래서 첫 인자는 self인것.
  - static method
    ```python
    class Foo(object):
      @staticmethod
      def add(x,y):
        pass
    x = Foo.add(3.4) # static method  호출은 이렇게.. 아마 return은 None객체가 되려나?
    ```
    - class namespace에 정의됨 p150
      - > 뭐.. 일반 인스턴스 함수도 마찬가지..
    - 🌟 보통 다양한 방식으로 인스턴스를 생성하는 클래스를 위해 사용함
      - > 그.. class에서 생성자는 하나 두고, static method로 여러 객체 생성 method두던 그방식.  
      - > TODO: 왜 이래야 한다고 했었지?
      - 🌟 파이썬에서 클래스는 단 하나의 `__init__` 메소드만 존재 가능. 
        - 그래서 위와 같이 static method를 이용해서 여러 param으로 객체 생성시 사용
        - > static method 니까 객체 생성은 그냥 객체 생성해서 return 해주는 방식으로... 작성
  - class method
    - > 코드 작성법은 뻔함. 
    - 왜 필요한가? static method와의 차이는?
      - 호출시 썻던 class 객체(인스턴스 객체 말고..)를 받을수 있음
      - 내부에서 `cls()` 로 객체 생성 가능
      - > 예제를 보면 static method로 객체 생성시, 코딩한 특정 객체만 생성할수 있는데,   
      - > class method를 쓰면 호출시 사용한 class 객체를 알기 때문에 해당 class로 객체를 생성하거나.. 등등의 작업이 가능
  - 위 함수들은 당연히 class namespace에 있는거라서,, 인스턴스 객체로 호출이 가능하긴 함 p151 참조
    - 이 부분은 스몰톡이나 루비 같은 언어와 다른점. 보통 다른 객체지향 언어는 클래스 메서드와 인스턴스 메서드가 엄격히 분리됨

- 프로퍼티
  - 접근되는 순간 값이 계산되는 특수한 속성
  - 균일 접근 원칙(uniform access principle)
    - 기본적으로 class의 인터페이스는 균일할수록 좋다.
    - property가 없다면, 어떤 속성은 c.radius처럼 접근하고 어떤 속성은 `c.area()` 처럼 메서드로 접근해야함.
    - 즉 균일하지 못해서 언제 추가로 `()`를 붙여주어야 할지 번거롭게 기억해야함. 
  - 메서드도 프로퍼티의 한종류
    - 즉, `()`없이 class의 method를 사용하면 bound method객체가 반환됨 (self에 묶임, 즉 bound mathod는 self명시 없이 호출가능 )
      - 이 bound method를 생성하는 작업이 배후에서 실행되는 프로퍼티 함수를 통해 되는거라고 함.
      - > class.method(객체, arg) 형태로 인스턴스 method 직접 호출도 가능. 59p
    - `@staticmethod @classmethod`로 메서드를 정의하는 것은, 이들 메서드에 대한 접근을 처리하는 프로퍼티 함수를 정의하는 것
      - 예를 들면 `@staticmethod`의 경우 메서드 함수를 특별히 다른 것으로 감싸거나 추가로 처리 하지 않고 그대로 반환
    - > 이말이.. 즉 def로 method를 정의하면, `.`으로 메소드 호출시 기본-프로퍼티 함수? 가 먼저 호출되서 self에 bound한 객체를 반환하는거고
    - > `@staticmethod @classmethod` 로 데코레이트 하면 기본-프로퍼티 함수? 가 사용되지 않는거? 뭐 그런 느낌 인가봄.
  - setter, deleter 사용하는 법
  ```python
  class Foo(object):
    def __init__(self, name):
      self.__name = name
    @property # getter
    def name(self): 
      return self.__name
    @name.setter # setter 
    def name(self, value): # setter에서 method name은 getter method와 같아야 함 
      self.__name = value
    @name.deleter # deleter
    def name(self): # setter에서 method name은 getter method와 같아야 함 
      raise TypeError("cant~")
  ```
  - > 이거 일반적인 getter, setter라고 생각하면 안됨. 일반적인 get,setter는 변수 캡슐화 목적이지만.  
  - > property는 접근시 연산이 되는것

- 기술자 (descriptor) 154p
  - property같은 속성접근 제어의 일반화할수 있는 방법
  - 특수 메서드인 `__get__() ,__set__(), __delete__()` 메서드를 구현해서, 속성 접근 메커니즘을 가로채 관련 연산들을 제어할수 잇음
    - > 🌟 이건 154p 예시를 꼭 봐야함. 
  - > 🌟 기본적으로 class 변수에만 기술자를 활용할 수 있는것으로 보임
  ```python
  class Foo(object):
    name = TypedProperty("name",str) # TypedProperty class에서 위 특수 메서드를 구현함
  
  f = Foo()
  a = f.name # 암묵적으로 Foo.name.__get__(f,Foo) 가 호출됨 
             # name은 class 변수임. 인스턴스로 접근했지만 해당 scope에 없어서 class scope로 올라감
  f.name = "test" # Foo.name.__set__(f,"test") 호출됨
  del f.name
  ```
  - > 프로퍼티에서 method도 프로퍼티 함수가 호출된다고 한게 위와 같은 형태가 아닐까 싶음..
    ```python
    class Test():
      def method(self):
        pass
    f = Test()
    f.method # Test.method.__get__(~) 이 호출되는거 아닐까?
    ```
  - 🌟 주의사항이 155에 나온다. 이건 getattr, setattr 함수를 기술자에 사용하면서 나타나는 문제를 해결하기 위함 같음

- 데이터 캡슐화와 private 속성
  - > python class에선 private 속성이 없음
  - class 변수나 method 이름 앞에 `__`를 붙여주면 name mangling이 자동으로 됨
    - 이를테면 A class의 `__method`는 `_A__method`로 변환됨
    - 이걸 이용하면 private인거 처럼 쓸수 있음. 물론 mangling된 이름으로 외부에서 접근도 되긴함.
      - `__dir__()` method 를 재정의해서 `dir()`로 객체검사후 반환되는 mangling된 이름을 수정해서 전달하면, 아예 외부 접근을 억지로 막을순 있음
        - > 이러면 사용자가 class의 method 실제 이름을 알지 못하게 하니까
  - 🌟 프로퍼티 사용시 이걸이용하면 좋다. 
    - 즉 내부 변수는 `__`을 사용하고 getter, setter는 언더바 없이 이름 짓고
  - base class에서 method를 위와 같이 쓴경우, 하위 class에서 override될일이 없다. 
    - > override하려면 `_A__method` 처럼 base class이름 붙여서 method name을 만들어야 하니까, 고의적으로 만들지 않는이상 실수로 override될 일은 없음
  - 🌟 모듈에서 private이랑 혼돈하는 경우가 많다. 
    - `from module import*` 로 method 나 모듈 변수가 import되는 거 방지할땐 이름 앞에 `_` 를 붙인다. 
    - class에서는 속성에 `_` 하나 붙인다고 달라지는게 없음

- 객체 메모리 관리
  - > link.md의 약한 참조 확인
  - 객체 생성을 풀어 쓰면 다음과 같다.  (new 로 생성후 init으로 초기화) 157p
  ```python
  c = Circle.__new__(Circle, 4.0) # args,kwargs는 init의 값과 동일
  if isinstance(c, Circle):
    Circle.__init__(c,4.0) # class로 함수 직접 호출할땐 bound method가 아니니, self 값 줘야함
  ```
  - 일반적으로 `__new__()`를 재정의하는 경우는 없는데, 아래와 같은 두가지 예외가 있다. 157p
    - 변경 불가능한 기반 클래스로부터 상속받는경우
      - 정수, 문자열, 튜플 같은것은 값의 변경이 불가능한 내장 타입
      - 이걸 상속받아서 subclass를 만드는 경우 init에서는 전달받은 초기화 값을 수정해 줄수 없음. 
      - 따라서 new를 override해서 값을 수정해야함
    - 메타클래스 정의
  - 인스턴스는 생성되면 reference counting으로 관리
    - 즉, ref가 0이 되면 인스턴스는 메모리에서 내려감
  - 🌟 `__del__()`
    - ref가0일때 인터프리터가 호출해줌
    - 이걸 직접 정의할 필요가 있는 경우는 드물다
      - 파일을 닫거나, 네트워크 연결을 끈거나... 할땐 씀
      - 🌟 근데 인터프리터가 종료시 이걸 호출해 줄거라는 보장이 없기 때문에, 이걸로 자원을 닫는것은 위험
      - 그냥 close같은 함수를 따로 만들어서 호출하게 하는게 좋음
      - > 인터프리터 종료라고 표현했는데, 혹시 사용자가 객체 ref가 0이라고 생각해서 del이 호출되는것으로 착각하는것을 의미?  
      - > 이를 테면 del a를 했어도 순환참조 때문에 a의 ref가 0이 안되어서 `__del__()`이 영영 호출되지 않을수 있다. 
    - `del a` 했다고 a의 `__del__()`이 호출되는것은 아님, ref가 0이 되어야 호출됨
  - 🌟 관찰자 패턴
    - > 이거 책의 예시인데, weakref를 써서 구현하지 않으면 순환참조 되어서 `__del__()`이 영영 호출되지 않음. ref가 0이 되지 않기때문..

- 객체 표현과 속성 바인딩
  - 인스턴스 안의 data는 `__dict__` 속성으로 접근 가능
  ```python
  a = Account()
  a.__dict__ # 인터프리터 모드에서 실행하면 a의 내용 출력됨
  a.test = 1 # 이거 가능 🌟, test 변수는 없었지만 이렇게 하면 test 변수가 a에 추가됨. 단 a.test만 한경우는 에러남
  ```
  - 인스턴스의 `__class__` 속성으로 자신의 클래스를 확인가능
  - 클래스도 `__dict__` 속성으로 클래스의 메소드,변수 등 확인 가능
  - 클래스는 `__bases__` 속성으로 상속한 클래스들 확인 가능
  - 특수메서드
    - `obj.name = value` 시 `obj.__setattr__("name", value)` 호출됨
    - `del obj.name` 시 `obj.__delattr__("name")` 호출됨
    - 위 두개는 `__dict__`에 값을 수정하거나 제거하는 기본 동작을 제공
      - 🌟단, target 변수가 프로퍼티나 기술자 였다면, set,del연산은 연결된 프로퍼티나 기술자의 것으로 수행됨
    - `obj.name` 시 `obj.__getattribute__("name")`이 호출됨
      - search 순서
        - 프로퍼티
        - 내부 `__dict__` 속성
        - class `__dict__` 속성
        - base(상속 class)의 내용을 찾는다. 
        - > 앞쪽에서 속성 찾을떄 내부 namespace에서 class namespace를 찾는 순서의 상세 버전 같음
      - 위 모든게 실패하면 AttributeError 발생
    - 특수 메서드를 override할때 원하는 case가 아닌 경우는 기본구현을 호출하게 하는것이 좋음 161p
      - 기본 구현에서 기술자나 프로퍼티 같은 고급 기능을 알아서 처리해 주므로..
    - 일반적으로 속성 접근 특수 메서드를 override하는 경우는 드물다.
      - 기존 객체에 대한 범용 래퍼나,proxy 구현할때는 쓴다. 

- `__slots__`
  ```python
  class Account(object):
    __slot__ = ('name','balance')
  ```
  - 사용은 위 예시와 같이 쓰고, slot이 class에 정의 되면
    - `__dict__`는 이용되지 않는다. 
    - 따라서 slot에 정의된 속성 외의 속성(변수)은 "인스턴스에서" 지정이 불가
    - 기존 인스턴스에 새로운 속성이 지정되는 것을 방지
      - > 근데 이 목적으로 쓰는 경우는 별로 없다고 함
    - 메모리와 실행속도 성능 최적화에 쓰임 (`__dict__` 안써서 생기는 이점인듯)
  - slot을 사용하는 base class를 상속했다면, subclass도 slot을 사용해야함.( 새로운 속성을 추가 하지 않더라도..) 162p
    - 안그러면 subclass는 dict를 쓰는것보다도 느리게 작동함. 그리고 메모리도 더소비
  - target class의 `__dict__`를  들여다보는 유틸리티, 라이브러리를 쓰게되면 문제 발생할수 있음
    - 당연하게도.. slot을 쓰면 dict가 없어서.. 
  - slot이 있다고 하더라도, `__getattribute__, __getattr__, __setattr__`같은 특수 메서드는 영향을 받지 않음
    - 이것들은 slot을 고려해서 만들어짐
  - 🌟 메서드나 프로퍼티는 class에 저장되는 것이므로 이들 이름은 slot에 추가할 필요 없음
    - > 즉 slot은 인스턴스 변수를 위함

- 연산자 오버로딩 164p
  - > 특별할게 없어서 넘어감
  - `__int__(), __float__()` 등을 class에서 override가능. 이거 있다고 객체를 자동으로 type casting해주지 않음
    - 이건 명시적 타입 변환에 쓰는것들.
  - > 근데 기본 값들 int, float등의 연산은 앞에서 암시적 casting해준다고 했음

- 타입과 클래스 멤버 검사 
  - `isinstance(), issubclass()` 를 이용한다. 165.
    - issubclass 는 인자로 둘다 클래스를 넘김
    - isinstance 는 인자로 객체, 클래스를 넘김 
      - > 객체게 인자로 전달한 클래스의 객체인지 그리고 그 클래스의 파생 클래스 객체인지 검사하는것. 이경우는 true
  - duck type은 당연히 위 함수로 check 불가.
    - 이떄는 `__instancecheck__, __subclasscheck__` 를 override해서 check 가능하게 할수도 있음. 168p 예제 참조
    - > 근데 이걸이용하는 것보다 java 처럼 abstact/interface를 이용해서 프로그래밍을 하는게 좋은듯.. 이건 `추상 기반 클래스`에 나옴  
    - > 즉, duck type class를 여러개 두고, 그걸 check 하기 위해 예제처럼 구현하는 것보다, 추상 class를 상속하는게 나은방법 이라는것

- 추상 기반 클래스
  - abc 모듈을 이용해야 추상 클래스 정의 가능
  ```python
  from abc import ABCMeta, abstractmethod, abstractproperty
  class Foo:
    __metaclass__ = ABCMeta # py2 방식. py3에서는 class Foo(metaclass=ABCMeta) 라고 씀
    @abstractmethod
    def spam(self, a,b ): # subclass에서 반드시 정의해야한다. 안그러면 객체 생성이 안됨
      pass
    @absctractproperty # subclass에서 반드시 name 이라는 property를 정의해야함 안그러면 객체 생성이 안됨
    def name(self):
      pass
  ```
  - > property는 기본적으로 getter를 의미. ( 음.. getter호출시 값이 연산된다는 점은 실제 getter랑 다르긴하지..)
  - 🌟abstractmethod, absctractproperty는 sublcass에서 같은 이름의 method만 있으면 되고, 인자나 return은 차이가 있어도 된다.
    - > 즉, 인자나 return에 대한 검사 안함
    - 마찬가지로 property의 경우 get, set, del을 subclass에서 지원하는지도 확인안함
  - abstract class는 기존 클래스를 등록하는 기능 제공 168p
    ```python
    class Grok(object):
      pass
    Foo.register(Grok) # Foo는 위 예제의 Foo임
  
    ```
    - > duck type때문에 지원하는 것으로 보이며, issubclass로 Grok이 Foo인지 check하면 true 나옴. isinstance로 Foo인지 확인해도 true

- 🌟 메타 클래스
  - 클래스도 객체이다 
    ```python
    class Foo(object): pass
    isinstance(Foo, object) # true가 반환됨
    type(Foo) # <type 'type'> 즉 Foo class의 타입은 type임.. 이건 base class인 object의 type이기도 함 
              # 여기서 나온 type이 meta class임
    ```
  - 클래스 객체 생성하는 일은 메타클래스가 제어한다. 
  - class가 정의되면 실행되는 일은 다음과 같다.  (위 예시의 Foo가 정의되면 아래의 일이 일어남)
    - 이름중 앞에 `__`가 붙은것을이 네임 맹글링 되는것 제외하면 아래의 예시와 같은 일이 일어남
    ```python
    class_name = "Foo" #클래스 이름
    class_parents = (object,) # 기반 클래스들
    class_body = """ 
    def __init__(self,x): # Foo class에 정의된 body
      self.x = x
    def blah(self):
      print("hello world")
    """
    class_dict = {}  # 앞서 설명이 되었던 class dict임

    # class_dict 안에다가 class_body를 실행
    # 이렇게 하면 class_dict에 class_body에 있던 method들이 정의됨
    exec(class_body, globals(), class_dict) # exec는 p138참조
    
    # 클래스 객체 Foo를 생성
    Foo = type(class_name, class_parents, class_dict) # 메타 클래스 type이 호출된것. 즉 이부분의 메타클래스를 다른것으로 정의하면 여길 제어할수 있음
    ```
  - 메타 클래스 정의 방법
    ```python
    class Foo:
      __metaclass__ = type # py2 버전
                           # py3에서는 class Foo(metaclass=type) 으로 쓴다. 
    ```
  - 메타 클래스를 지정하지 않으면
    - base class들중 첫번째 항목을 보고, 첫번째 기반 class의 타입을 메타클래스로 사용한다. 
    - base class가 없다면?
      - `__metaclass__` 이름의 전역 변수가 있는지 살펴본다. 이게 있으면 이걸 사용
      ```python
      __metaclass__ = type 
      class Foo: # meta class로 위의 type이 사용됨
        pass
      ```
    - 위 해당하는 것조차 없다면?
      - 이경우 파이썬은 기본 메타클래스를 사용
      - py2의 경우 old-style class라고 불리는 types.ClassType이 쓰임, python2.2부터는 사용이 권장되지 않음
      - py3의 경우 위 예시 처럼 `type()`이 기본 메타클래스로 사용됨
  - 보통 커스텀 메타 클래스 정의 할때는?
    - `type()` 메타 클래스를 상속하고, `__init__`이나 `__new__`같은 메서드를 다시 구현
    ```python
    # 모든 메서드에 문서화 문자열이 존재하는지 검사하는 메타 클래스
    class DocMeta(type):
      def __init__(self, name, bases, attrs): # 위쪽 type() 예시와 param은 같다. 클래스 이름, base class들, 그리고 class_dict
        for key, value in attrs.items():
          # 특수 메서드와 개인 메서드는 건너뜀. ( 아마 맹글링은 나중에 진행되나봄?? )
          if key.startswit("__") : continue
          # 호출 가능하지 않는 것은 제외
          if not hasattr(value, "__call__") : countinue # method object의 경우 이 attr가 있음. ( TODO: 이거 쫌 이상함.. method에 이거 없을텐데..)
          # 문서화 문자열 검사
          if not getattr(value, "__doc__"): # hasattr해도 되는거 아닌가?
            raise TypeError("~~")
        type.__init__(self, name, bases, attrs)

    # 보통 custom meta class 사용할땐, 다이렉트로 class에 적용하지 않고,
    # base class를 따로 만들어서 거기에 적용.
    # 이후 이걸 상속한다. ( 위에서 설명했듯 subclass는 첫번째 bass class의 type을 metaclass로 사용함)
    class Documented:
      __metacalss__ = DocMeta # py2 버전,
                              # py3는 class Documented(metaclass=DocMeta)

    class Foo(Documented):
      def spam(self, a, b):
        "this is doc string" # 이거 있어야 __doc__ 속성이 method에 생기고, metaclass에서 raise error가 발생하지 않음
        pass
    ```
  - 보통 위와 같이 클래스의 정의를 들여다보고 필요한 정보를 수집하는데 메타클래스를 사용 
    - 즉, 생성되는 클래스의 변경은 하지 않고 단지 추가적인 검사만 진행
  - 메타 클래스를 좀 더 전문적으로 사용하는 경우에는 클래스의 정의를 살펴보는 동시에 변경도 진행
    - 이경우 클래스 객체가 생성되기 전에 실행되는 `__new__()` 메서드를 재정의 해야 한다. 
    - 이 메서드에서는 클래스에서 사용될 이름을 변경할 수 있기 때문에, 보통 속성을 기술자나 프로퍼티로 감쌀 때 흔히 사용됨
    - 예시는 다음과 같다. p154의 "기술자" 절에 나왔던 TypeProperty의 사용을 meta class를 이용해서 재 작성한 버전 p172
    ```python
    # TypeProperty class도 조금 다른데, 이건 책을 봐라 

    class TypedMeta(type):
      def __new__(cls, name, bases, dict) : # 🌟 new의 첫 param은 원래 cls이고, 나머지 부분은 원래 init method의 param과 같아야함
        slots = []
        for key, value in dict.items():
          if isinstance(value, TypedProperty): # 즉 attr가 만들었던 기술자 인경우
            value.name = "_" + key  # TypedProperty 객체에 name 속성이 있고 이걸 _key값(문자열)으로 교체
            slot.append(value.name)
        dict['__slots__'] = slots # slot을 만들어서 넣어줌
        return type.__new__(cls,name,bases,dict)
    
    # 위에서 설명했듯, metaclass를 세팅한 base class를 만듬
    class Typed:
      __metaclass__= TypeMeta

    class Foo(Typed):
      name = TypeProperty(str)
    ```

- class decorator (클래스 장식자)
  - 단순히 클래스가 정의되고 난 후 클래스를 registry나 db에 등록하는 것과 같은 몇가지 추가 작업만 수행하고 싶은경우..
    - meta class대신 class decorater를 이용하는 것이 좋다.
  - class decorator는 입력으로 클래스를 받고 출력으로 클래스를 반환하는 함수임.
  ```python
  registry = {}
  def register(cls):
    registry[cls.__clsid__] = cls
    return cls
  # 여기서 register 함수는 클래스에 __clsid__ 속성이 있는지 보고 있다면 registry 사전에 등록하는 함수
  # ? 근데 없는 경우는 error나나?

  @register
  class Foo(object):
    __clsid__ = "123-456"
    def bar(self):
      pass
  
  ```
  - 장식자는 원한다면 안쓸수도 있어서 편리


## 8장 모듈,패키지와,배포

- 모듈 == .py파일
- import 문 동작
  - 1. 네임스페이스 생성
  - 2. 이 네임스페이스 안에서 모듈의 코드들을 실행
  - 3. 모듈을 호출한곳 (import 문 쓴곳)에 이 네임스페이스를 가르키는 이름 생성

- 🌟 모듈안에서 정의된 함수와 메서드는 해당 모듈의 네임스페이스만 이용한다. 
  ```python
  # foo.py
  a = 40
  def f():
    print(a)
  
  # bar.py
  import foo
  a = 400
  foo.f() # 당연히 40이 나옴. 
  # 🌟 foo의 a를 수정해 주고 싶다면, foo.a = 400이런식으로 해야함. 자세한건 p179참조
  ```
  > 모듈안 함수에서 global 을 쓰면 해당 모듈의 네임스페이스를 이용함 ( import 문 사용한 곳의 네임스페이스가 아니라..)
    > 즉, 함수의 전역 네임스페이스는 항상 그 함수가 정의된 모듈

- 모듈도 1급 객첸
  - 모듈에 `__dict__` 속성 있음
- from문 as는 아는거라 생략
  - `from spam import (foo, bar, spam)` 처럼 괄호를 쓰면 장점이 여러줄로 나누어 쓸수 있음 p177
  - 위 코드는 foo,bar,spam을 현재 네임스페이스에 가져오는 것
- 모듈은 여러번 import해도 로드는 한번만 된다. 
  - `sys.modules` 에 import된 모듈을 담은 사전이 있음 ( 모듈이름과 모듈 객체 매핑)
- 모듈 import시 `*` 와일드 카드를 쓸수 있는데, 이땐  `_` 언더바 한개 붙은 애들은 네임스페이스에 안들어옴
  - 즉 `from bar import *` 문을 말함
  - 🌟 주의점 위 문장은 모듈의 가장 상위 수준에서만 사용가능 p178
    - 상위수준이라는건.. 모듈 함수나 클래스 안이 아닌 맨 바깥쪽을 의미 하는듯
    - 함수안에서 사용하면 함수 유효범위 규칙에 위배됨 p178
      - 함수가 내부 바이트코드로 컴파일 될때 함수 안에 있는 모든 기호는 확실하게 식별할수 있어야 한다. 
- `__all__`을 모듈에 정의하면 `from bar import *`시 노출되는 이름들을 제어 할수 있다.

- 각 모듈에는 모듈 이름이 있는 `__name__`속성이 있음
  - python으로 실행시 `__name__` 엔 `__main__` 이라는 이름이 들어감
  - 라이브러리 작성시 이걸 이용해서 기능 검사 코드를 같이 넣어 주는 경우가 많다함 p180

- 🌟 모듈 검색 경로
  - 모듈 로드를 위해 인터프리터는 `sys.path`에 있는 디렉토리 목록을 검색
    - 보통 `sys.path` 의 첫 항목은 빈문자열 임. 즉 현재 디렉토리
    - `sys.path`에는 디렉터리 이름, zip, egg 파일 등이 추가될수 잇음
    - `sys.path`에 항목이 나열된 순서가 모듈이 로드되는 순서를 결정
      - > 모듈을 찾을떄 path를 검색하는 순? 이를테면 A 폴더 B 폴더 순으로 있었따면 A에서 모듈 foo찾고, 그다음 B에서 찾고..
    - 검색경로에 새로운 항목 추가시 `sys.path`에 간단히 추가하면됨
    - 경로 지정시 보통 디렉터리 이름을 써주지만, 파이썬 모듈을 담은 zip 이름을 써줘도 됨 (모듈 묶기 편함)
      ```python
      import sys
      sys.path.append("test.zip")
      # sys.path.append("/tmp/test.zip/lib/test") 이렇게 구체적 경로 줄수도 있음

      import foo, bar
      ```
      - egg 파일 추가도 가능. egg는 setuptools 라이브러리에 의해 만들어 지는 패키지
        - 그냥 메타데이터가 쫌 추가된 zip임
    - 🌟 zip 파일 import 주의점
      - zip 파일에서 import할수 있는 파일 형식은 py, pyc, pyc, pyo뿐
      - 보통 import하면 .pyc, .pyo가 생성되는데, zip 파일에 있는 py는 import시 해당파일을 인터프리터가 생성해 주지 않음
      - 따라서 pyc,pyo를 zip에 미리 만들어서 두고 제공하는게 좋음
- 모듈의 종류
  - 앞서 모듈은 py파일이라고 했는데 실제로는 다음 네가지이다. 
    - py
    - dll, so 로 컴파일된 c 나 c++ 확장 기능
    - 패키지
    - c로 작성되어 파이썬 인터프리터에 연결된 내장 모듈
- 모듈을 찾을떄 인터프리터는 sys.path에 있는 각 디렉터리 에서 아래 순서대로 파일을 찾음
  - 패키지를 정의하는 foo 디렉터리
  - foo.pyd, foo.so, foomodules.so 또는 foomodule.dll (컴파일된 확장 기능)
  - foo.pyo (인터프리터를 -O나 -OO 옵션으로 실행시 사용)
  - foo.pyc
  - foo.py (윈도에선 .pyw 파일도 검사)
  - > sys.path에 있는 디렉터리에 위 모듈 파일들중 어느 것도 없으면 내장 모듈에서 검색. 그래도 없으면 importerror
- 모듈이 처음 import될때 .py는 바이트코드로 컴파일되어 .pyc로 다시 쓰여짐
  - 이후 import에선 이걸 쓰는데 .py 수정날짜가 최신이면 이걸 다시 씀
- .pyo는 디버깅 정보같은게 날아간 파일. 인터프리터가 좀더 빠르게 실행되는 효과있음
- 🌟 import 문장을 사용할때 만 py가 .pyc, .pyo로 자동 컴파일 됨
  - .py파일을 담은 디렉터리가 쓰기 불가능인 경우는 생성 안됨
  - 위 두파일이 있으면 .py는 없어도 실행에 지장없음
  - .pyc는 파이썬 버전에 종속적. 즉 파이썬 버전에 따라 실행안될수 있음
- import문은 대소문자 구분함
  - `import foo` 는 foo.py 를 로드하지 FOO.PY를 로드하지 않음

- 모듈 재로딩은 불가능
  - 왜냐면 import에서 한번 로딩한 모듈은 여러곳에서 참조하고 있을텐데.. 
  - 특히 모듈안의 class로 인스턴스를 만들었다면 인스턴스는 class를 참조하고 그 class객체는 모듈을 참조
  - sys.modules에서 모듈 제거하고 import로 다시 로드해도, 이전 참조들이 갱신되지 않는다.
  - > 그냥 인터프리터를 다시 시작해야 한다. 
  - > 즉, 모듈 로드후 모듈 구현 변경후 재로딩 불가. --> 이거 파이썬 interactive 모드에서 작업시 많이 발생하는듯

- 패키지
  - 디렉토리에 소스넣고 `__init__.py`만 넣으면됨
    - 패키지에 하위 패키지 두는것도 가능한데, 당연 하위 패키지도 위 구조여야함
  - 패키지 일부가 처음 시작될때 경로에 있는 `__init__.py`가 모두 실행됨
  - `__init__.py`엔 패키지 초기화 코드를 넣을수 있다. 
    - 보통 `__all__`을 정의해서 `from 패키지 import *` 에서 import되는 모듈들을 나열해 주는듯
    - > 이건 모듈을 현재 네임스페이스로 가져오는 코드.
  - 🌟 주의점
    - `from Graphics.Primitive import *` 
      - 위 코드는 Graphics패키지의 하위 패키지인 Primitive 패키지 않의 모든 모듈을 현재 네임스페이스로 가져오려고 쓰는데...
      - 시스템마다 파일 이름과 관련된 규칙이 달라서. 그냥 이렇게 쓰면 안됨
      - `__init__.py`에 `__all__`을 제공해야함 p184
    - 🤩 한 하위 모듈에서 동일한 패키지의 다른 하위 모듈을 임포트 하려는 경우... 
      - `from  Graphics.Primitive import lines` 처럼 full 경로 쓰던가
      - `from . import lines` 처럼 상대 경로를 써야함
      - `import lines` 는 안됨!!
        - 옛날 파이썬에서는 위와 같이 쓰면 현재 경로에서 탐색해 주었는데
        - py3는 import문은 무조건 절대경로라고 가정하고 표준 라이브러리에서 로드하려고 시도함 p185
          - > 이 제약은 패키지 하위 모듈의  import문에 대한것인듯하다.. 
          - > 단순 python파일 만들어서 실행시 import로 같은 디렉토리의 다른 py파일 잘 로드됨..
  - 상대 경로 사용법
    - 무조건 `from module import symbol` 형태에서 from에만 상대경로 사용가능
    - `from ..Primitives import lines` => 위 폴더로 가서 Primitive폴더에 들어간뒤 lines.py 로딩
    - 이떄 import뒤에는 유효한 식별자 여야한다. 즉 xxx.yy 같은 dot 사용 불가
  - 패키지 이름을 임포트 한다고 하위 모듈까지 자동 로드 되지 않음
    - 원한다면 아래와 같이 해야함 `__init__.py` 에서 import문에 넣어 줘야함
    ```python
    #Graphics/__init__.py
    from . import Primitive, Graph2d
    #Graphics/Primitive/__init__.py
    from . import lines, fill
    ```
  - `__path__`
    - 하위 모듈을 검색하는데 사용되는 디렉터리 목록을 담는 특수한 변수
    - sys.path의 패키지 버전
    - 패키지 import시 생성됨
    - `__init__.py` 파일 안에서 접근 가능 p186

- 배포
  - disutils 모듈 사용
  - > 대충 보니까 폴더에 위 모듈을 이용해서 setup.py를 만들면 됨   
  - > 이후 `python setup.py sdist` 치면 dist 디렉토리에 tar나 zip이 생김 이걸 배포함  
  - > 받은 측에서는 압축 풀고 `python setup.py install` 하면 설치됨
  - > 🌟 여기서 용어가 나오는데  
    - > python 모듈, 패키지 -> 말 그대로..
    - > script -> 이건 콘솔에서 `python` 명령어로 실행될 파일
  - 설치
    - 위처럼 해서 설치되는 위치는 "지역 파이썬 배포 장소" -> ?
    - 모듈과 패키지는 보통 파이썬 라이브러리 안에 있는 "site-packages"디렉터리에 설치
      - 정확한 위치는 sys.path를 보면됨
    - 스크립트는 보통 유닉스 기반 시스템에선 파이썬 인터프리터와 동일 위치에 설치됨
    - 윈도에선 Scripts 디렉터리에 설치됨
  - `python setup.py bdist` p189참조
  - 파이썬 런타임이랑 함께 배포 하고 싶다면 ? py2exe나 py2app을 사용
  - setuptools로 만들었다면 (disutils대신.. )
    - egg파일이 생성됨. (disutils는 tar나 zip)

- 써드 파티 라이브러리 설치
  - > pip 
  - 설치 경로는 파이썬 표준 라이브러리의 site-package 디렉터리
  - 접근 권한 없을경우 명령어에 옵션줘서, 사용자별 라이브러리에 설치 가능 p190참조 


## 9장 입력과 출력

- optpars를 소개하는데, 난 argparse를 썻었다. 
  - 프로그램의 args는 `import sys`에서 받는다. 

- 환경 변수
  - `import os`에 있다. 이건 나도 써먹음.
  - `os.environ` 인데, 수정시 현재 실행 중인 프로그램과 파이썬에 의해 생성된 하위 프로세스가 영향 받음.

- 파일 입출력
  - open으로 하는건데, 주의점은 줄바꿈 문자. 
    - > 이거 줄바꿈 인코딩이 os마다 다르고 애매하네.
    - 이거 p193~194에 나옴

- 표준 입출력
  ```python
  import sys
  sys.stdout.write("enter your name :")
  name = sys.stdin.readline()
  # name = raw_input("enter your name:" ) 위 내용대신 내장함수 raw_input이용 가능 py3에선 input()
  
  ```

- `print()`
  - p199
  - py3에서 변경된 동작을 나타냄.

- 문자열에서 변수 치환
  ```python
  
  form = """\ 
  Dear %(name)s,
  please send back my %(item)
  """
  print form % { 'name' = 'mr.bush',
                  'item' = 'pen'}
  # 또는
  print form.format(name='mr.bush', item='pen')

  # 또는
  import string
  #해서 string.Template 이용하는 방안.. p200
  ```
  - 근데 보통 웹 프레임워크에선 자신만의 템플릿 문자열 엔진을 쓴다함.. (즉 프레임웤에서 다른거 제공해준다는 거 같음.)


- generator를 이용해서 연속된 소량의 data를 출력 스트림에 전달 가능
  - p201참조
  - > 그냥 제너레이터 만들어서 `f.writelines(count)` 처럼 넘기거나  
  - > for-in문에 넣어서 사용 할수 있다는거.. 
  - 몇몇 웹프로그램에서 WSGI와 상호작용하는 프로그램 작성할때 종종 쓰임.

- 유니코드 문자열 처리 p202
  - `s.decode()`에서 s는 byte 문자열로 가정
    - 즉, py2에서 s는 표준 문자열
    - py3에선 특수한 bytes 타입.
  - > 정리하면 decode는 바이트 문자열을 유니코드/아스키 등 문자열로 변환
  - > encode는 유니코드문자열 등을 바이트 문자열로 변환
  - py3에선 문자열은 encode method만 있고, bytes타입은 decode 메소드만 있다. 
  - p204 골치 아픈 일을 겪지 않으려면 인코딩된 바이트 문자열과 인코딩되지 않은 문자열을 절대 같이 쓰면 안된다.  (+로 연결해서 쓴다던가.. 등등)
    - py3는 괜찬. .어짜피 이렇게 할 수 없게 되어 있음.

- 유니코드는 파일에 저장하기 까다롭네.. 2바이트라 엔디안 문제 있음.. 책에선 미가공 유니코드 데이터는 파일에 직접 쓸수 없다함.
  - > p204 부터 내용 나오는데 skip함. 

- 👍 객체 영속화(Persistence)와 pickle 모듈
  - > Persistence는 spring 입문 강좌에서도 잠깐 용어만 언급됨.
  - 객체의 내용을 파일에 저장하거나 복원할때 씀
  - pickle 
    - 객체를 파일에 썻다가 나중에 복원 할수 있도록 객체를 바이트 스트림으로 직렬화. p210
    - `dump()`,`load()` 두 method 제공
    - pickle에서 사용하는 데이터 포맷은 파이썬에 특화되어 있는데, 파이썬 버전에 따라 다름 (dump의 매개변수로 프로토콜 변경 가능.)
  - shelve
    - pickle과 유사하지만 객체들을 사전 같은 데이터베이스에 저장. 
    - 조건 및 단점이 있음. - p210
  - 객체에 정의가능한 특수 메소드 있음. -p211
  - 그리고 보안 문제가 있어서 신뢰하지 않는 소스에 쓰면 안됨
    - > 역시 보안 내용도 언급 되었군.. 어떤 이슈인진 p212 참조.

## 10장 실행 환경

- 프로그램 실행 도중에는 순환참조를 파이썬의 가비지 컬렉터가 회수 하기는 한다. 
  - 프로그램 종료시에는 가비지 컬렉터가 호출되지 않는다. 
  - 이 차이는 `__del__`이 호출되냐 안되냐의 문제를 가져옴
  - steixt 모듈로 종료시 호출될 함수 등록 하거나, 이걸로 가비지 컬렉터를 종료전 호출 할수 있음 p221

- 종료시 어떤 객체의 `__del__` 에서 다른 모듈에 정의된 전역 데이터나 메서드에 접근시 문제가 발생할수 있음
  - 접근하려는 객체가 이미 파괴되었을수 있기 때문 `Nameerror` 발생
  - 이경우 그냥 `os._exit(상태)`를 이용해서 아무런 청소 작업없이 프로그램을 종료시키는게 나을수 있음
  - 또는. `__del__` 에 default param을 넣는다.. p222

## 11장 테스트 디버깅 프로파일링과 튜닝

- 내장 타입들을 이용해라
- 표준 라이브러리에 있는 타입들도 살펴 봐라
  - ex: collection.deque의 경우 앞뒤 새로운 항목 추가시 list보다 훨씬 빠름

- 클래스와 인스턴스는 dict를 기반으로 만들어 진것
  - 단지 데이터를 저장하기 위한 간단한 자료 구조를 원하는 거라면 그냥 dict를 쓰는게 빠르다.

- `__slots__`를 사용해라 
  - class에서 인스턴스 변수에 제약을 줌
  - > dict대신 list 쓰는듯.
  - 보안 기능이기도 하지만, 성능의 이점이 큼
  - 단, `__dict__`에 의존하는 코드들은 동작하지 않는 단점 잇음 -242

-  `.` 연산의 사용을 피해라
  -  단 성능이 중시되는곳만.. 
  -  모든곳에 쓰면 피곤해짐

- 함수형 프로그래밍과 반복을 채택해라
  - 리스트 내포, 생성기 표현식, 생성기, 코루틴, 클로저 적극활용

## 12장 내장함수와 예외

> 되게 다양한 function들이 있네.. 나중에 필요할때 찾아 보는게 좋을듯


## 부록 py3

- 집합 상수
  - `days = { 'Mon', 'Tue','Wed'}` 이게 가능해짐 이건 아래와 같음
  - `days = set(['Mon', 'Tue','Wed'])`
  
- 집합과 dict comprehension 770p
  - > 위에서는 리스트 내포, 생성기 표현식이 나왔었음
  
- `a, *rest = items`
  - 확장된 반복 가능한 풀어헤치기임 771p

- nonlocal keyword
  - py2에서 중첩함수에서 outter class의 변수를 읽을순 있엇는데 수정할순 없었음
  - 이제 수정도 가능

- 함수 주석
  ```python
  def foo(x:1, y:2) ->3:
    pass
  ```

- 키워드 전용 인수
  ```python
  def foo(x, *arg, strict=False):
    pass
  ```
- 표현식 Ellipsis
  - > 이건 Ellipsis 자체를 잘 모르겠음

- 연쇄 예외 e
  - `raise SyntaxError("") from e`

- 메타클래스에 `__prepare__` 추가됨 
- text vs bytes
- 반복자와 뷰
  - dict의 `d.keys()`, `d.values()`,`d.items()` 가 이제 view 객체를 반환
  - view는 dict에 바인딩 되어 잇어서 dict의 값이 변하면 view에서 받는 값도 변함