
#%%
from abc import ABCMeta, abstractmethod

class Foo(metaclass= ABCMeta):
    @abstractmethod
    def spam(self, value):
        pass

class Test(object):
    pass
# Foo.register(Test)

a = Test()
if isinstance(a, Foo):
    print("isinstance")
if issubclass(Test, Foo):
    print("issubclass")

# %%
from test2 import a, foo_test
foo_test()
print(a)

# %%
