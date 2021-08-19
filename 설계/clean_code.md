# 좋은 코딩

## if문 else문

- if / else 같은 경우 else를 없게 줄이는 게 좋다. 
  ```java
    // 안좋은 형태
    if (a > 0) {
        if (b == 0){
            doA();
        }
    } else {
        doB();
    }
    // 좋은 형태
    if (a <= 0){
        doB();
        return;
    }
    if (b == 0) {
        doA();
    }
  ```
- 클린 코드 책에서는 다형성으로 if/else를 없애라고 했음
- 우테크 참여 블로그에서는 다형성 대신 enum 이나 함수형으로 제거를 진행 함
  - 특히 simple factory를 함수형으로 if를 날리는게 신선함

## 같은 추상화 레벨?

이부분은 내 사견을 적어두면.

- 1단계 추상화 레벨
  - 해당 기능을 raw api들로 만든것 
  - raw api는 내가 쓴 표현이고 그냥 1차원적인 java util 또는 library api쓴것

- n단계 추상화 레벨
  - n-1단계 추상화 레벨의 api를 이용해서 만든것

위와 같은 생각은 리팩토링 문서의 우테크 세미나를 보고 얻게 되었다.  
clean-code에서 추상화 레벨이 같아야 한다는것은 정량적으로는 위와 같은 뜻일듯.
  
## link 

- 코드 리뷰 중복 제거
  - https://plas.tistory.com/15?category=663337
- 클린 코드 (카카오 헤어샵)
  - if else 줄이는 법나옴
  - https://brunch.co.kr/@cg4jins/2  

- java 구글 스타일
  - > 우테크 과제는 스타일 가이드 및 clean code여야 한다함
  - https://velog.io/@new_wisdom/JAVA-Google-Java-Style-Guide-%EB%B2%88%EC%97%AD

- 멤머 함수 보다는, 비멤버 비프렌드 함수와 더가까워지자
  - > 이거 음.. 혼란스러움.. cpp에서만 해당할 수도 있고.. 
  - > 예시를 보면, class에 변수가 아닌, 메소드 호출만으로 구성할수 있는 함수의 경우는 
  - > 그냥 밖으로 빼는게 좋은가봄. ( 캡슐화 관점에서.. 이건 두번재 link에 나옴)
  - https://xxzzang.gitbooks.io/ecpp/content/item-23-ba64-bc84-d568-c218-bcf4-b2e4-b294-be44-ba64-bc84-be44-d504-b80c-b4dc-d568-c218-c640-b354-ac00-ae4c-c6cc-c9c0-c790.html
  - https://sexycoder.tistory.com/51