# 리팩토링

- 우테크 세미나. 시작으로 매우 좋음 (아래 내용에서도 적음)
  - https://www.youtube.com/watch?v=bIeqAlmNRrA

## 어떻게 시작할까?

- 명확한 기준이 있어야함
  - indent를 줄이겠다
    - ex: if문 중첩이면 indet는 2.. 따라서 하나의 if를 function으로 빼던지.. 등. 
  - class에 인스턴스 변수는 3개 이상 쓰지 않는다. 
  - 1급 콜렉션
    - > 별건 없고 인스턴스 변수 1개에 collection을 두고 그걸 객체로 만든것, 이런 내용은 clean_code에서도 나온거 같다. 

## Compose Method 패턴