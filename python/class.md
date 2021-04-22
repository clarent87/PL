# class

```python
class A(object):
    pass

# 이런식으로 python3에서는 object를 상속해도 되고, 안해도 자동 상속

# 파이썬 2에서는 아래와 같은 두가지 스타일이 존재
# 따라서 호환성?을 생각해 본다면 new 스타일로 python3,2 모두 통일해서 작성하는게 좋을듯. 

1. old style
>>> class ClassicSpam:      # no base class
...     pass
>>> ClassicSpam.__bases__
()
2. new style
>>> class NewSpam(object):           # directly inherit from object
...    pass
>>> NewSpam.__bases__
(<type 'object'>,)
>>> class IntSpam(int):              # indirectly inherit from object...
...    pass
>>> IntSpam.__bases__
(<type 'int'>,) 
>>> IntSpam.__bases__[0].__bases__   # ... because int inherits from object  
(<type 'object'>,)
```

- constructor는 명시하지 않으면 기본적인게 자동으로 들어감
- 만약 constructor를 명시 하였다면 기본적인건 자동으로 추가되지 않음.. 당연.
  - python class에서 `__init__`함수는 단하나만 존재해야 함 ( 두개 이상 선언도 되긴 하는데, 결국 하나만 인식함.)
  - 상속시 base class에서 대해서는 `__init__` 의 기본형이 제공됨 항상
- class의 메소드나 속성(static 변수느낌의 것) 을 메소드 안에서 참조시 class이름까지 붙여 줘야 함. ( 또는 self.로..)

- class에 constructor가 많이 필요한 경우 아래와 같이 해결
  - classmethod/staticmethod 데코레이터로 constructor 만들어서 사용
  - init의 arg를 `*,**`의 pack을 이용해서 받음. 

```python
class TEST:
    TT = "속성임"
    def test():
        print(TT) # 이거 오류.. 왜냐면 메소드에서 class속성이나 메소드 접근하려면 class이름까지 완전하게 추가해줘야함. (이게 c++, java와 다른점)

# 클래스 속성의 경우 class 객체 생성시 판단 되는듯. 즉 TT = Path() 라고 했다면 TT에는 현재 path값이 들어감

```

https://stackoverflow.com/questions/4015417/why-do-python-classes-inherit-object

## class attribute

- 아마 class 접근시 attribute의 assignment가 호출되는거 같음 ( 다른 언어가 그렇듯.. )
- 이거 **메타 클래스 봐야 할듯**
  - class attribute 에서 해당 class의 attribute를 접근하는거는 error임 => class가 define되지 않았다고 뜸
    - 상식적으로 봐도 이게 되면 무한루프? 일듯.
  - 단, object method에서는 원활하게 접근됨..


## private method

- 이름에 `__`붙이면된다. 
  - 혹시 접근하고 싶다면 외부에서는 `_A__MEHTOD` 처럼 앞에 `_CLASSNAME`을 써준다.

> 모듈 단위헤서 export하기 싫은 변수는 앞에 언더스코어 하나 붙여주면됨
