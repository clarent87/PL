# tip

## python 

- map이랑 zip 을 적극 이용하면 좋을듯.. 
  - > 아.. 프로그래머스 다시 좀 봐야할듯

- PriorityQueue는 이용하지 않는게 좋다. 
  - 직접 heapq로 풀어야한다. 
  - PriorityQueue는 threadsafe하기 때문에 실제로 속도가 느려서 시간초과 오류가 남..
    - > 차라리 java를 이용하는게 나은가..

- 0이 아닌 숫자는 True이긴한데 아래와 같은 비교는 당연히 안됨. 
  - 단 x가 1이면 true로 간주되므로 정상동작. 
  - 만약 x가 0이면 false와 비교시 성공
  ```python
  x = 100
  if x == True: # x는 숫자 100, true는 bool
    print("True")
  ```
- list는 stack처럼 쓸수 있다
  - append, pop, list[-1] 사용


## 실패 케이스

- 코너 케이스에서 걸리는 경우가 많았음. 
  - 조건들을 잘 따져야 할듯
- `>` 대신 `>=`를 써야 하는데, 실수함