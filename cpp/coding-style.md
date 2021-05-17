# 코딩 스타일

- [구글 코딩 스타일 원문][1] : 최신
- [번역][2] : 조금 옛날 내용

## 최신 구글 코딩 스타일 번역

### Header Files

- Self-contained Headers
  - 헤더 파일은 **Self-contained Headers** 이어야한다. (헤더가드 필수)  
  - 템플릿과 인라인 함수는 정의와 선언을 같이하는게 좋다.
  > Self-contained Headers란, 헤더 파일안에 해당 해더파일이 의존하고 있는 모든 헤더 파일을 include한 헤더 파일  
  > 즉, 이것만 include하면 다른 dependency를 include하지 않아도 된다.

- Forward Declarations
  - 가능한 전방선언은 피하라 (대신 헤더파일을 include해라 )

- inline functions
  - 10line이나 그 이하 함수만 inline으로 써라
  
- Names and Order of Includes
  - 헤더파일 include 순서는 다음과 같다.
  - Related header, C system headers, C++ standard library headers, other libraries' headers, your project's headers.

### Scoping

### Classes

### Functions

### Google-Specific Magic

### Other C++ Features

### Inclusive Language

### Naming

### Comments

### Formatting

### Excpetions to the Rules

### Parting Words

[1]: https://google.github.io/styleguide/cppguide.html
[2]: http://jongwook.kim/google-styleguide/trunk/cppguide.xml
