# 문법 관련 tip

## throws

```java
interface TestInterface
{
    public void print() throws Exception;
}
  
class Test implements TestInterface
{
    public void print()
    {
        System.out.println("In print");
    }
}
```

특정 method에서 **throw** 가 있다면 **thows** 키워드를 선언에 써준다.  
그리고 위와같이 method 구현에서는 굳이 throws가 있다고 해서 exception을 throw한는 코드가 있을 필요는 없다.

## 람다 vs 익명클래스

ref. <https://skasha.tistory.com/34>

람다의 경우 익명클래스 위치를 대체할수 있는데, 이때
해당 익명클래스 위치의 인터페이스는 method가 하나여야하나봄. 이를 위해 FunctionalInterface 어노테이션이 존재하나 보다.

## for/in

자바5 부터 나온것, generic이랑 써야한다.

```java
for(Object obj: collection){ // 형태는 이러한고, 컬렉션 및 배열에 대해 동작.
}
```

## super vs child

기본적으로 java는 cpp와는 다르게 부모 변수로 자식 객체를 가리킬수 있고, 부모 변수로 method 호출시 자식 method 가 호출됨 (즉 실제 객체의 method 호출)  
cpp는 위와 같은 기능을 쓰려면 virtaul 키워드 써야함.
  
아래 코드는 toString에 대한 것이다.  
기본적으로 java의 최상위 부모는 Object이고 여기에 toString이 있어서, 아래와 같이 toString이 호출된것.

```java
class Scratch {

  public static void main(String[] args) {

    A t = new B();
    System.out.println("this is " + t);
  }


  interface A {

    public void print();
  }
  static class B implements A{

    @Override
    public void print() {
      System.out.println("this is A");
    }

    @Override // 보면 Override 표시가 뜸. 즉 어딘가에서 상속되긴 한 method.
    public String toString() {
      return "this..";
    }
  }
}
```

## java thread

cpp thread의 경우 stack이 따로 할당되고, code, data, heap은 공유.  
TLS는 thread만의 정적 변수.  
자바는 프로세스 개념은 없다 thread만 있고, object를 대상으로 lock을 건다. ( 즉, 각각 thread가 같은 object를 사용할때는 동기화 이슈가 있음)

## 자바 문자열

ref. <https://ecsimsw.tistory.com/entry/%EC%9E%90%EB%B0%94-%EC%9E%90%EB%B0%94%EB%8A%94-%EB%AC%B8%EC%9E%90%EC%97%B4%EC%9D%98-%EB%81%9D%EC%9D%84-%ED%91%9C%EC%8B%9C%ED%95%98%EC%A7%80-%EC%95%8A%EB%8A%94%EB%8B%A4>

자바 문자열은 cpp처럼 /0으로 끝을 표현하는게 아니라, 내부적으로 길이를 관리

## enum

아래와 같이 쓸수도 있음. 약간 interface로 익명 class사용하는 것과 비슷

 ```java
  public enum DateInterval{
    OPEN{
      public boolean isIn(int d, int left, int right){
        return d > left && d < right;
      }
    },
    CLOSED{
      public boolean isIn(int d, int left, int right){
        return d >= left && d <= right;
      }
    };
    public abstract boolean isIn(int d, int left, int right);
  }

  public boolean isInRange(DayDate t1, DayDate t2, DateInterval interval){
    return interval.isIn(getOrdianlDay(), left, right);
  }
  
  ```

## 함수내 class정의 가능

<https://docs.oracle.com/javase/tutorial/java/javaOO/anonymousclasses.html>

## 배열 초기화

ref. <https://stackoverflow.com/questions/9114047/curly-braces-when-define-array>

```java
int[] arr = {1,2,3,4,5}; 
int[] arr = new int[] {1,3,5,2,4}; 
int[] odds = {1,3,5,7,9};


Object[] ar = new Object[] {"abc"};
// 이건 아래와 같다. 
// Object[] ar = new Object[1];
// ar[0] = "abc"; // String도 Object의 sub class 이므로.. 

```

## 익명 클래스의 constructor

ref. <https://www.dummies.com/programming/java/how-to-use-an-anonymous-class-in-java/>
ref. <https://www.baeldung.com/java-anonymous-classes>

- TDD 책에서 아래와 같은 코드가 나옴
- 위 ref에서 익명 class는 constructor가 없기 때문에 param을 넘길수 없다고 하는데.. 아마이는 interface를 impl했을때 얘기인거 같음
- java File은 class이고 constructor중에 param받는게 있어서 아래처럼 가능한거 같음.. (ref두번째에서 그런 설명이 있음)

```java

File f = new File("foo"){
  public boolean createNewFile(){
    ...
  }
}

```
