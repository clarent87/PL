# final

class 나 method에 붙일수 있고, 붙이면 상속, override 불가능 인듯.  
해당 키워드는 cpp에도 있었다. (class,method에 붙일수 있음)
  
안드로이드에서 변수에 final을 붙이면 상수풀에 들어가고(stack대신) 이러면 익명class나 람다에서도 해당 변수에 접근 가능.  
상수풀은 원래 사이즈가 제한적이었는데, jvm버전이 올라가면서 충분히 커진듯.(근데 gc가 돌지는 안는게 아닌가 싶다.)

  
객체 변수에 final이 붙으면 해당 변수의 참조는 처음 init된걸로 고정됨 <https://coding-factory.tistory.com/525>