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

