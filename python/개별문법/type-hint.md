# 타입 힌트
https://docs.python.org/3/library/typing.html

제네릭이란것도 있네.. 

```python
def __init__(self, app_name: str,  secure_off: bool, auto_invoke: bool, package: str=None, passphrase: str=None):

#  타입 힌트와 함께 default 값을 주는 방식은 위와 같다. 
#  주의 할점은 default 값이 있는 변수는 그렇지 않은 변수보다 뒤에 와야 함. 
```

## Covariance and contra-variance

상당히 난해한 개념 같다. 근데 간단히만 보면 다음과 같다. 

1. Base and Derived 클래스가 있다.
2. List<Base> 라고 쓰인 곳을 List<Derived>로 치환해서 쓸수 있음? => yes면 covariance=True
3. List<Derived> 라고 쓰인 곳에 List<Base> 쓸수 있음? => yes면 contra-variance

https://stackoverflow.com/questions/61568462/python-typing-what-does-typevara-b-covariant-true-mean

## upper bound

http://egloos.zum.com/ryukato/v/1182733
https://www.pythonsheets.com/notes/python-typing.html

## 전방 선언

- 타입힌트에서 전방선언은 ""로 한다. (즉, 문자열로 해당 타입을 감싼다.)