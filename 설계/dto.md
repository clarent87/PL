# DTO

- DTO 목적
  - > 일단 entity들? 을 계층에 직접 넘기는것은 효율적이지 못함.
  - > 즉, 다음 계층에 필요한 정보만 가공?해서 넘겨 줘야함.
  - > 대강 이런 느낌인데, 자세한것은 EAA 책 확인 필요

일단 사용 예시는 다음과 같음

```java
    // controller
    @PostMapping("/dive-logs")
    public ResponseEntity<?> register(HttpServletRequest servletRequest,
            @RequestBody @Validated DiveLogRegisterRequest registerREquest, BindingResult bindingResult) {

        if (bindingResult.hasErrors()) {
            Map<String, String> errorMaps = bindingResult.getFieldErrors().stream()
                    .collect(Collectors.toMap(FieldError::getField, FieldError::getDefaultMessage));
            return ResponseEntity.badRequest().body(errorMaps);
        }

        DiveLogDto result = diveLogEditor.save(registerREquest.convertToRegisterCommand());

        String location = ServletUriComponentsBuilder.fromContextPath(servletRequest).path("/dive-logs/{id}")
                .buildAndExpand(result.getId()).toString();

        return ResponseEntity.status(HttpStatus.CREATED).header(HttpHeaders.LOCATION, location).body(result);
    }

    //service
    @Override
    @Transactional
    public DiveLogDto save(DiveLogRegisterCommand registerCommand) {
        // divePointRepository 는 jpa interface 그거임. 
        DivePoint divePoint = divePointRepository.findById(registerCommand.getDivePointId())
                .orElseThrow(() -> new DivePointNotFoundException(registerCommand.getDivePointId()));

        return DiveLogDto.ofEntity(diveLogRepository.save(registerCommand.convertToEntity(divePoint)));
        // public static DiveLogDto ofEntity(DiveLog entity) {
    }


```

DTO은 각 계층간 data를 전송하기 위한 객체, 최종적으로는 Entity로 전환된다.  
> Entity는 보통 DB의 컬럼에 맞추어 구현됨. ( jpa 사용시 다른진 모르겠음)

위 코드를 보면  
  
- 프레젠테이션 레이어
  - contoller에서는  `DiveLogRegisterRequest` 라는 객체를 받는데
  - 이걸 비지니스 레이어로 넘기기 위해 아래와 같은 코드로 DTO를 만든다
    - `registerREquest.convertToRegisterCommand()`
    - 반환되는 DTO는 DiveLogRegisterCommand 이다.
    - > CQRS의 개념에 따라 명령에 관련된것을 명시적으로 Command 라고 표현한듯..
    - > convertToRegisterCommand method는 DiveLogRegisterRequest 에 있는것!
- 비지니스 레이어
  - 코드를 보면 DTO를 가지고 DAO에 data를 질의해서 DivePoint 엔티티를 받아와서, Entity 업데이트
    - > 여기는 이후 다시 설명, 여기서는 중요하지 않음
  - 이후 다시 프레젠테이션 레이어로 data를 전달하기 위해 DivePoint엔티티를 DiveLogDto DTO로 만들어서 반환
  - `public static DiveLogDto ofEntity(DiveLog entity)`

- 즉 정리 하면 다음과 같음
  - Controller -> service : DiveLogRegisterCommand DTO 전달
  - service -> DAO : Entity ( 조회는 id)
  - service -> Contoller : DiveLogDto DTO 전달

- DTO 변환/두는 곳은?
  - > 여기서는 헥사고널에 맞추어, 의존이 모두 domian으로 향하게 되어 있음
  - application
    - dto
      - DiveLogRegisterCommand
        - 컨트롤러에서 DiveLogRegisterRequest data를 이 DTO로 변환해서 전송
        - convertToRegisterCommand() 메소드를 활용하는데 이 method는  DiveLogRegisterRequest에 있음
        - > 즉 controller -> application
      - DiveLogDto
        - 서비스에서 컨트롤러로 data 전송에 사용
        - DiveLog 엔티티를 이걸로 변환
        - 생성 함수는 ` public static DiveLogDto ofEntity(DiveLog entity) ` 로 DiveLogDto에 존재
          - > 생성 함수는, 변환이랑 다름. 그냥 해당 레이어안에서만 사용..
        - 의존 관계
          - > contoller -> application
    - 서비스
      - 의존
        - > service -> domain(dao..)
      - DiveLogRegisterCommand의 convertToEntity 사용
        - > service -> domain 의존
      - DiveLogDto의 ofEntity사용
        - > service -> domain 의존
  - domain
    - entity
    - 아무곳도 의존 안함.
  - infra
  - > 참고로 controller는 web 쪽 package가 따로 있고 거기에 있음

- ofEntity, convertToEntity
  - 그냥 엔티티로 DTO 생성에 사용
  - 이건 같은 레이어에서만 사용하니까, 특별히 의존관계는 없음
  - > 굳이 따지면 Domain 과 의존

- 헥사고날?
  - DB2 강좌 예제는 레이어드임
    - 즉 서비스 패키지에서 리포지토리 패키지의 interface에 의존
  - 근데 Dive-log예제는 헥사고날이라서 아래와 같음
    - application
      - 서비스 존재
      - dao 구현 주입 받음
      - > 즉 domain에 의존
    - domain
      - 엔티티 존재
      - dao interface존재
    - infra
      - dao interface구현
      - > 즉 domain에 의존

- Entity -> DTO를 통해서 data가 어떻게 변하는지?
  - > todo 단순 Entity -> DTO면 그냥 Entity 넘겨도 되지 않나?

- DTO는 immutable? 👍
  - 일단 예제들의 DTO는 immutable임
  - 즉 getter만 존재 final은 아니지만. 객체 생성후 값 바꿀 방법이 없긴함.
  - 상황에 따라 mutable.. 하게 사용할수도 있나봄
    - > 근데 data 전송과정에서 변하면, 안될꺼 같음. 이내용 어딘가에서 있었던거 같음
    - > 근데 참고로 DB2 강좌에서는 @Data 붙여서 DTO만듬. 일단 값 비교 되는것은 맞음.
    - > VO가 불변이라고 하는데, VO == DTO라고 하긴 했음
    - > <https://tecoble.techcourse.co.kr/post/2021-05-16-dto-vs-vo-vs-entity/>

- DTO immutable하게 작성하는 법. 👍

  ```java
    // @Data는 setter만들어지니까 아래 처럼씀
    @Getter
    @RequriredArgsConstructor // final 필드가 없어 추가할 필요 없음
    @ToString
    @EqualsAndHashCode
    public class UserDto {
      ...
    }

  ```

    ```java
    // @Data는 setter만들어지니까 Getter만 만들어서 immutable하게 사용
    @Getter
    public class UserDto {
      ...
      @JsonProperty ~
    }

  ```

  ```java
    @Data
    @Setter(AccessLevel.NONE) // 세터 사용 못하게..
    public class UserDto {
        ...
    }
        
  ```

  ```java
  // 이게 best같음. 어짜피 fianl은 세터 안만들어짐. 

  @Data
  public class UserDto {

      private final String email;

      private final String name;

      private Integer age;

      private final LocalDateTime registeredAt;

  }


  ```

  ```java

    // 또는 아예 immutable 만들려면 @Value사용
    // 이거 final class fianl 
    @Value
    public class UserDto {

        private String email;

        private String name;

        @With(AccessLevel.PACKAGE)
        @NonFinal // 두가 같이 써서 package레벨에서 값 접근 해서 세팅하려는듯
        private Integer age;

        private LocalDateTime registeredAt;

    }
  
  ```

- Controller의 param 매핑도 DTO?
  - 어느 글에서 읽었는데, 이것도 일단 DTO라고 보여짐
  - DTO사용안하면 Map에 key,value로 data를 받음.
    - > 이거 폰에 link 있으니 확인하고 정리 요망
    - > 원래 DTO는 마틴 파울러의 EAA 책에서 처음 소개됨

- 정리
  - 즉 DTO도 의존 방향에 맞추어 구성하면된다.
  - DTO 위치도 db2 강좌에 있듯, 의존 방향에 맞는 곳에 두면된다.
    - DTO를 마지막에 쓰는애들이 있는 위치에 두면 된다!
      - > 위 예시도 딱 맞음
    - 애매 할땐 별도 package에 둔다!
