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