# record

## record 소개

### java 14

- 목적
  - java 14에서 preview로 소개됨.
  - java app개발에 immutable한 data를 만들고 사용하는게 일반적인데, 매번 만들떄 boilerplate fields and methods를 만들게됨.
    - > we write classes to simply hold data, such as database results, query results, or information from a service.
  - 이렇게 만들면, 실수하기도 쉽고, 의도 파악도 어려웠다함

- immutable한 object 만들기 위한 조건
  - 보통 data를 immutable하게 만들기 위해 아래와 같은 방법을 따름
  - 방법
    - private final로 field 정의
      - > 근데 setter없으면 final 안해도 될거 같은데.
    - getter생성
    - public constructor생성 ( argument 전부 포함)
    - equals,hashCode,toString method 오버라이드
      - > 이작업은 값이 같으면 같은 것으로 간주해 주기 위함.

- 기존 방식으로 immutable한 object class 만들기 (위 조건 적용)
  - 문제점
    - There's a lot of boilerplate code
    - 클래스의 목적이 모호함. 사람의 이름/주소를 나타내고 싶었는데, 뭐가 복잡함 ( 즉 extra method때문에 simpe data class라는것을 이해하기 어렵게한다)
      - > 근데 롬복 쓰면 쫌 낫지 않나?
    - 아래 코드는 IDE에서 만들수 잇는데, 혹시 field를 추가했다면 override함수 getter를 ide로 update해야함, 근데 실수로 누락할수 있음
      - > 역시 롬복 쓰면 쫌 나을듯

  ```java
  public class Person {

      private final String name;
      private final String address;

      public Person(String name, String address) {
          this.name = name;
          this.address = address;
      }

      @Override
      public int hashCode() {
          return Objects.hash(name, address);
      }

      @Override
      public boolean equals(Object obj) {
          if (this == obj) {
              return true;
          } else if (!(obj instanceof Person)) {
              return false;
          } else {
              Person other = (Person) obj;
              return Objects.equals(name, other.name)
                && Objects.equals(address, other.address);
          }
      }

      @Override
      public String toString() {
          return "Person [name=" + name + ", address=" + address + "]";
      }

      // standard getters
  }

  ```

- 참조
  - <https://www.baeldung.com/java-record-keyword>
  - <https://openjdk.org/jeps/359>

#### record 기초

- Records are immutable data classes that `require only the type and name of fields.`
- The equals, hashCode, and toString methods, as well as the private, final fields and public constructor, are generated
- `records are very useful for creating small immutable objects`

```java

// 기본 작성법
public record Person (String name, String address) {}

```

빌드후 bytecode를 보면 아래와 같음

```java
public final class com/example/redistest/javarecord/Person extends java/lang/Record {

  private final Ljava/lang/String; name
  private final Ljava/lang/String; address

  // 생성자 param 두개 받는. 생성자는 이거 하나 존재
  public <init>(Ljava/lang/String;Ljava/lang/String;)V

  // getter
  public name()Ljava/lang/String;
  public address()Ljava/lang/String;

  // toString, hashcode, equeal도 알아서 생성됨

}

```

- 생성자
  - record에서 자동으로 생성되는 생성자

  ```java
  public Person(String name, String address) {
      this.name = name;
      this.address = address;
  }

  ```

- Getters
  - 게터는 field 이름이랑 똑같이 만들어짐 ( getName. 이런식이 아니라)

    ```java
    @Test
    public void givenValidNameAndAddress_whenGetNameAndAddress_thenExpectedValuesReturned() {
        String name = "John Doe";
        String address = "100 Linda Ln.";

        Person person = new Person(name, address);

        assertEquals(name, person.name()); // getter
        assertEquals(address, person.address());
    }

    ```

#### 커스텀 생성자

public 생성자를 컴파일러가 기본적으로 제공해 주지만, validation check등의 기능을 넣은 생성자 만드는거 가능

```java
  // 널 체크 생성자 
  // compact constructor. 👍 를 이용함. 생성자에 널 체크 로직을 추가
  public record Person(String name, String address) {
      public Person {
          Objects.requireNonNull(name); // null check
          Objects.requireNonNull(address);
      }
  }

  // 빌드 결과
  public record Person(String name, String address) {
    public Person(String name, String address) {
        Objects.requireNonNull(name);
        Objects.requireNonNull(address);
        this.name = name;
        this.address = address;
    }

    public String name() {
        return this.name;
    }

    public String address() {
        return this.address;
    }
  }

```

```java

  public record Person(String name, String address) {
      // argument 하나자리 생성자
      public Person(String name) {
          this(name, "Unknown");
      }
  }

  // 이경우 빌드 결과는 아래와 같음. 즉 생성자 두개 (하나는 내가 만든것, 하난 컴파일러 작성)

  public record Person(String name, String address) {
    public Person(String name) {
        this(name, "Unknown");
    }

    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public String name() {
        return this.name;
    }

    public String address() {
        return this.address;
    }
  }


```

생성자에서 field는 this키워드로 접근 가능하고, field name은 record의 argument 이름으로 정해짐 ( 위 예시에서는 name, address)

- 주의 사항
  - 컴파일러가 생성해 주는 constructor랑 동일한 signature의 constructor만드는거 가능한데
  - 이경우 fiedl 초기화 코드 필요
    - > 없으면 ide에서 빨간줄 찍어줌

    ```java

    public record Person(String name, String address) {
        public Person(String name, String address) {
            Objects.requireNonNull(name); // null check
            Objects.requireNonNull(address);
            this.name = name; // 필수!
            this.address = address; // 필수!
        }
    }

    ```

  - 그리고 아래처럼 compact constructor랑 컴파일러가 만들어 주는 constructor sigauter가지는 (위예제) constructor만들어서 같이 쓰면 오류남

    ```java

      public record Person(String name, String address) {
          public Person {
              Objects.requireNonNull(name);
              Objects.requireNonNull(address);
          }
          
          public Person(String name, String address) {
              this.name = name;
              this.address = address;
          }
      }

    ```

- compact constructor
  - <https://mikemybytes.com/2022/02/16/java-records-and-compact-constructors/>
  - 생성자의 parameter를 다루기 위한 목적, record의 field에는 접근 못함.
    - > 당연한 얘기안데, 위 커스텀 생성자 빌드 결과 보면 알수 있음

    ```java

      record Mapping(String from, String to) {
          Mapping {
              System.out.println(
                  "Mapping from='" + this.from + "', to='" + this.to + "'" //이거 오류남 ( 필드 접근은 할수 없음)
              );
          }
      }

    ```

    ```java
        record ApiEndpoint(String name, HttpMethod method, String url) {
            ApiEndpoint {
                name = name.toUpperCase(); // 파라메터 값 변경가능 -> 이후 이값이 field에 들어감
                // no need to "re-declare" 'method' 
                // no need to "re-declare" 'url'
            }
         }
    
    ```

#### Static Variables & Methods

- we can also include static variables and methods in our records.
- 즉, static 변수, 메소드만드는것은 일반 class와 동일

```java
public record Person(String name, String address) {
    public static String UNKNOWN_ADDRESS = "Unknown";
}

```

```java
public record Person(String name, String address) {
    public static Person unnamed(String address) {
        return new Person("Unnamed", address);
    }
}

```

- 활용
  - DTO simple factory method 만들떄 쓸수 있겠음 👍

#### 일반 method

> 어짜피 jecord 상속한 class 라서, 그냥 일반 method 만드는것은 큰 문제 없을듯.

#### 롬복 vs record (중요) 👍

- 목적
  - 둘다 boilerplate code 줄이는데 목적이 잇는데,
  - 어떨때 뭘 쓰면 좋을지 이야기함.

- Small Immutable Objects
  - 아래 예시는 롬복 쓴거 record 쓴거 인데
  - record 쓰는게 자연스럽다. ( Color 오브젝트 context상..)

  ```java

    public record ColorRecord(int red, int green, int blue) {
    
        public String getHexString() {
            return String.format("#%02X%02X%02X", red, green, blue);
        }
    }

  ```

  ```java

    @Value
    public class ColorValueObject {
        int red;
        int green;
        int blue;

        public String getHexString() {
            return String.format("#%02X%02X%02X", red, green, blue);
        }
    }

  ```

- Transparent Data Carriers
  - 레코드를 사용하면 member field를 무조건 노출해야함. getter가 기본적으로 제공되기 때문에
  - 롬복은 아예 member field를 숨길수 있음 ( 즉 getter가 노출되지 않음/만들어지지 않음. )
  - 따라서
    - if we want to hide the member fields and only expose some operations performed using them, Lombok will be better suited.

  ```java

    @Value
    @Getter(AccessLevel.NONE)
    public class ColorValueObject {
        int red;
        int green;
        int blue;

        public String getHexString() {
            return String.format("#%02X%02X%02X", red, green, blue);
        }
    }


  ```

- Classes With Many Fields
  - field가 많으면 오히려 record는 별로임
    - > 원래 이상황에서 쓰라고 나온게 아닌거 같음
  - 롬복은 @Builder 제공해주기 때문에 유리
  - records are better for smaller objects. Though, for objects with many fields, the lack of creational patterns will make Lombok's @Builder a better option

  ```java

    public record StudentRecord(
      String firstName, 
      String lastName, 
      Long studentId, 
      String email, 
      String phoneNumber, 
      String address, 
      String country, 
      int age) {
    }

    // 생성
    //  hard to read and understand, especially if some of the fields aren't mandatory( 즉 null로 넣음)
    StudentRecord john = new StudentRecord( "John", "Doe", null, "john@doe.com", null, null, "England", 20);

  ```

  ```java
    @Getter
    @Builder
    public class StudentBuilder {
        private String firstName;
        private String lastName;
        private Long studentId;
        private String email;
        private String phoneNumber;
        private String address;
        private String country;
        private int age;
    }

    // 사용
    StudentBuilder john = StudentBuilder.builder()
      .firstName("John")
      .lastName("Doe")
      .email("john@doe.com")
      .country("England")
      .age(20)
      .build();
      
  ```

- Mutable Data
  - record로는 해결 안됨
  - Some framework는 object의 setter나 default constructor를 필요로 함.
    - 하이버네이트 @Entity 같은경우.
  - 이때는 롬복 써야함.

  ```java

    @Data
    @AllArgsConstructor
    public class ColorData {

        private int red;
        private int green;
        private int blue;

        public String getHexString() {
            return String.format("#%02X%02X%02X", red, green, blue);
        }

    }

  ```

- Inheritance
  - record는 상속을 지원하지 않음
  - they cannot be extended or inherit other classes.
  - Lombok's @Value objects can extend other classes, but they are final
  - @Data objects can both extend other classes and be extended.
  - 정리
    - 이 경우는 롬복 써라

  ```java

  @Value
  public class MonochromeColor extends ColorData {
      
      public MonochromeColor(int grayScale) {
          super(grayScale, grayScale, grayScale);
      }
  }

  ```

- 참조
  - <https://www.baeldung.com/java-record-vs-lombok>

### java 15

- 아직 preview상태
  - It has been enhanced with support for local records

위에서 소개 못한 기능은 아래와 같음 15에서 일단 소개되긴 함 (문서상)
  
- 아래 처럼 getter 커스텀 가능
  - 생성자가 그랬듯, context는 맞아야 함
  - 즉 return length필요
  - 나머지 method도 마찬 가지
    - if you implement your own versions of the equals, hashCode, and toString methods, then ensure that they have the same characteristics and behavior

  ```java

  record Rectangle(double length, double width) {
  
      // Public accessor method
      public double length() {
          System.out.println("Length is " + length);
          return length;
      }
  }

  ```

- You can declare static fields, static initializers, and static methods in a record class

  ```java

  record Rectangle(double length, double width) {
      
      // Static field
      static double goldenRatio;

      // Static initializer
      static {
          goldenRatio = (1 + Math.sqrt(5)) / 2;
      }

      // Static method
      public static Rectangle createGoldenRectangle(double width) {
          return new Rectangle(width, width * goldenRatio);
      }
  }

  ```

- You cannot declare instance variables (non-static fields) or instance initializers in a record class.
-`You can declare instance methods in a record class`, independent of whether you implement your own accessor methods.
- You can also declare nested classes and interfaces in a record class, including nested record classes (which are implicitly static).

```java
  record Rectangle(double length, double width) {

      // Nested record class
      record RotationAngle(double angle) {
          public RotationAngle {
              angle = Math.toRadians(angle);
          }
      }
      
      // Public instance method
      public Rectangle getRotatedRectangleBoundingBox(double angle) {
          RotationAngle ra = new RotationAngle(angle);
          double x = Math.abs(length * Math.cos(ra.angle())) +
                    Math.abs(width * Math.sin(ra.angle()));
          double y = Math.abs(length * Math.sin(ra.angle())) +
                    Math.abs(width * Math.cos(ra.angle()));
          return new Rectangle(x, y);
      }
  }

```

- You cannot declare native methods in a record class.
- 레코드는 final class. 그리고 extend record임. 이 특징 제외하고는 일반 class랑 같음 👍
  - `record Triangle<C extends Coordinate> (C top, C left, C right) { }` // 제네릭 사용
  - `record Customer(...) implements Billable { }`  // interface 구현

  ```java
  // 어노테이션 붙일수 잇음
  // 근데 이경우 해당 어노테이션이 자동 추가되는 요소에 모두 적용됨 👍
  // 1. canonical constructor (컴파일러가 만들어주는 표준 생성자)의 파라메터
  // 2. The record class's components // ? 아래랑 같은거 아닌가
  // 3. The private fields length and width
  // 4. The accessor methods length() and width() // 즉 getter
  record Rectangle(
      @GreaterThanZero double length,
      @GreaterThanZero double width) { }

  // 예제
  public record Person(@Valid String name, String address) {
  }

  // 빌드 결과
  public record Person(@Valid String name, String address) {
      public Person(@Valid String name, String address) {
          this.name = name;
          this.address = address;
      }

      public @Valid String name() {
          return this.name;
      }

      public String address() {
          return this.address;
      }
  }


  ```

  - 어노테이션이 자동 생성되는 코드에 모두 붙는게 싫으면, 아래처럼 어노테이션을 구현해서 써야한다.

    ```java
    import java.lang.annotation.*;
    @Retention(RetentionPolicy.RUNTIME)
    @Target(ElementType.FIELD) // 필드에만 붙음
    public @interface GreaterThanZero { }

    ```

- Local Record Classes
  - > local class와 같은것
  - > <https://docs.oracle.com/javase/tutorial/java/javaOO/localclasses.html>
  - > local class개념 첨봄.

- Record Serialization
  - 직렬화, 역직렬화 가능
  - 근데 writeObject, readObject, readObjectNoData, writeExternal, or readExternal 오버라이드 불가
  - The components of a record class govern serialization
  - the canonical constructor of a record class governs deserialization
- APIs Related to Record Classes
  - > Record라는 class 만들어서 쓰면 java Record랑 중복되서 오류나고,, 뭐 그런가봄. 이거 해결법

- > + 몇몇 api 소개

- 참조
  - <https://docs.oracle.com/en/java/javase/15/language/records.html>
  - <https://www.baeldung.com/java-15-new>

### java 16

- record가 공식적으로 추가됨

- 추가된 문법
  - 이제 innerclass의 멤버변수로 record 사용 가능
  - Static Members of Inner Classes

  ```java

  public record Book(String title, String author, String isbn) {
  }

  class OuterClass {
      class InnerClass {
        // we can now define records as class members of inner classes
        // implicitly static 임.
          Book book = new Book("Title", "author", "isbn");
      }
  }

  ```

- 참조
  - <https://docs.oracle.com/en/java/javase/16/language/records.html>
  - <https://www.baeldung.com/java-16-new-features>

## jackson 사용 (작성중)

- <https://blogs.oracle.com/javamagazine/post/java-json-serialization-jackson>
- <https://dev.to/brunooliveira/practical-java-16-using-jackson-to-serialize-records-4og4>
- <https://carloschac.in/2021/03/04/jacksonrecords/>

- DTO로 record를 사용하게 되면 deserialize 및 serialize가 문제 없이 되는지 확인 필요
  - > 문제 없다고 본거 같은데. .
