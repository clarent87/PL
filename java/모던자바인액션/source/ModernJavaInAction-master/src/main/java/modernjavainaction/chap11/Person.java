package modernjavainaction.chap11;

import java.util.Optional;

public class Person {

  private Optional<Car> car; // 이거 null 아닌가.. 값 할당을 해야 할텐데.. -> null임.
  private int age;

  public Optional<Car> getCar() {
    return car;
  }

  public int getAge() {
    return age;
  }

}
