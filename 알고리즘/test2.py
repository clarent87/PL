# %%
a = 4300
atest = 100
def foo_test():
    print("a is " + str(a))

# %%
def simple_coroutine():
    print("-> start")
    x = yield 
    print("-> end")

my_co = simple_coroutine()
my_co
next(my_co)
my_co.send(42)
# %%
