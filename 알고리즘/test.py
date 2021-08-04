#%%
def foo(x, items=[]): # 함수 정의후 실행하면 items는 list 객체가 할당됨
    items.append(x)
    return items
# foo(1)  
# foo(2)  
print(foo(3))  
# %%
