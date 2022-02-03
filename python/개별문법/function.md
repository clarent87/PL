# function 관련

## bare asterisk

fucntion 정의시 arg 중간에 *를 인자로 하나 넣을수 있음. 이경우 fucntion 사용시 keyword arg는 키워드 써서 호출해 줘야 함.

```python
In python 3 you can specify * barely to force parameters after that as keyword only arguments:

>>>def fn(arg1, arg2, *, kwarg1, kwarg2):
...     print(arg1, arg2, kwarg1, kwarg2)
... 
>>> fn(1, 2, 3, 4)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: fn() takes 2 positional arguments but 4 were given
>>> fn(1, 2, kwarg1=3, kwarg2=4)
1 2 3 4
>>> 

```

https://stackoverflow.com/questions/36467057/what-is-the-use-of-in-python-function-definition
https://docs.python.org/3/reference/compound_stmts.html#function-definitions