# pycham 관련 사용법

## source root

폴더마다 content type이란게 있고, 특히 source root는 소스코드의 root를 의미  
파이참은 source root 부터 현재 프로젝트를 인식해서 import를 처리하는 것으로 보임  

- source root 지정안하니까 import에서 현재 디렉토리 모듈 import 하면 빨간줄 그어짐 ( intellisence 경고? ) 
- [링크][1] 참조

[1]: https://www.jetbrains.com/help/pycharm/configuring-folders-within-a-content-root.html

## Pycham editable install

Pip -e 옵션 install된 editable 모듈의 경우 pycharm에서 확인을 못한다.. 즉, 빨간줄 뜸. ( interpreter는 문제 없이 작동됨 )  

- 해결책 
  - Open the "Project Interpreters" dialog (Settings -> Project Interpreter -> Gear icon -> More... ->).  
  - Select the interpreter, and one of the buttons on the right is "Show paths for selected interpreter".  
  - You can add the new path here.

## Pycharm pip

Pip upgrade 하면 pycharm 내의 기능으로 모듈 설치 실패함[link][1]   
Pycharm 18.1.1 버전은 괜찮다는거 같음.. 현재 난 2017.8버전

## Pycharm six 

Six같은경우 pycharm-2018.1 helpers typeshed third_party에서 내용을 검색하기 때문에.. Intellegense가 제대로 동작하지 않는다..   
Run을 pycharm에서 할경우.. 오류날거 같기도 함..  
실제 설치된 package를 보지 않기 때문..[link][2] 

## 단축키

- `ctrl` + `alt` + `<-` or `->` : 앞 혹은 뒤에 보던 코드로 가는거 


[1]: https://intellij-support.jetbrains.com/hc/en-us/community/posts/360000168364-Pycharm-Virenv-AttributeError-module-pip-has-no-attribute-main-occured-
[2]: https://www.jetbrains.com/help/pycharm/type-hinting-in-product.html#typeshed


