# class 생성시 object 상속

new-style 클래스와 old-style클래스의 차이입니다. 클래스 스타일은 파이썬 버전에 따라서 다음과 같이 나뉩니다. 

```python
# python 2
class MyClass: # >>>>OLD-STYLE 클래스<<<<
class MyClass(object): # new-style 클래스

# python 3
class MyClass(object): # new-style 클래스
class MyClass: # new-style 클래스 (명시하지 않아도 자동으로 object 상속)
```

old-style과 new-style은 python2.2부터 구분하기 시작했습니다.

그 전까지 쓰이던 old-style은 이름 그대로 이제 너무 오래되어서 3.x 부터는 존재하지 않기 때문에 python3.x 에서 base클래스를 정의할 때는 object를 굳이 표기하지 않아도 괜찮습니다.

문제는 이 3.x코드를 2.x코드에 쓸 때 발생합니다. 2.x에서 obeject를 표시하지 않으면 이 클래스는 old-style로 간주됩니다.

old-style클래스와 new-style클래스는 아주 다르고 이는 프로그램에 생각지도 못한 문제를 야기할 수 있기 때문에 귀찮더라도 호환성을 위해서 꼭 (object)를 표기해주세요