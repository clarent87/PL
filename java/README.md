# Readme

## 간단한 것

- volatile keyword
  - 가시성 관련 키워드라고함.
  - 변수의 값을 write하였을때 memory에서 cache로 변수값을 가져와서 수정하고 cache에 반영하나봄
  - 근데 다른 쓰레드에서 해당 변수를 읽으면 변경된 값을 읽지 못하는데, 이때 해당 변수에 volatile을 쓰면
  - 항상 memory에 변수의 변경사항을 반영해 주나봄

