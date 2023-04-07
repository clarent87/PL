# 리트코드

## 주의사항

- 종료 조건 매번 오래걸리네..
  - 종료 조건은 차근차근 검토 해야할듯. 

## 추가 알고리즘

### union find

pass

## tip

### 200번 섬의 갯수 문제 👍

- 가지치기의 중요성
- 이거 DFS 지만 사실 backtracking에 가까움
- 이문제도 사실 아이디어가 중요

### 17번 문제 👍 👍

- 일단 잘 기억해야 하는 문제라 적음
- 백트래킹
  - 이걸 잘 풀려면, 백트래킹을 하면서 가지치기를 통해 최적화를 하는 형태로 풀이
- 근데 이거 구현에 대한 생각을 잘했어야함.. 

- 기본적으로 DFS에는 loop가 필요하지 않는듯?
  - 그.. 연결된 vertex 순회를 위한 loop빼고
  - 즉, 아래와 같이 돌리는게 아니란것. 기본적으로는

    ```python

    while expr:
        dfs()

    ```

- 그리고 코테에서 중첩함수 사용하는거 적극 권장.
  - outter 변수 바로 접근 가능해서. 

### 최대값

- 항상 max 연산을 우선 고려
  - deque도 max에 넣을수 있음

### 슬라이딩 윈도우

- slicing 방법도 하나의 옵션
- 슬라이딩과 투포인터 차이는
  - 투포인터는 보통 정렬된 곳에 사용
- 슬라이딩 윈도우는 left, right 포인터를 두고 이동시키는 형태를 사용했음. (보통 문제 풀이에서)

### 그래프 표현법

> dict 이용하는거...

### 방향이 있는 그래프 표현법

그냥은 dict로 만들면 되겠지만, 방향이 있는 그래프인데 반대 방향 쪽으로도 가야 한다면..
> 이거는 그냥  문제 확인

```python

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        self.res = 0 # 답
        roads = set()
        graph = collections.defaultdict(list)
        for u, v in connections:
            roads.add((u, v)) # 노드에서 노드로의 방향은 따로 관리
            graph[v].append(u) 
            graph[u].append(v) # 해당 노드로, 들어오고 나가는 노드 추가

        def dfs(u, parent):

            self.res += (parent, u) in roads # parent -> 현재 city 길이 있으면 count + 1

            for v in graph[u]: # 현재에서 나가는게 있으면
                if v == parent: # 다시 올라가는 거면 생략.
                    continue
                dfs(v, u)

        dfs(0, -1)
        return self.res


```

### 트리 표현법

>pass

### 값 비교

일단 == 과 != 는 값 자체를 비교하고,
is 와 is not은 객체를 비교한다.

### Dict[int, Dict[int, int]] 만들기

```python
    from collections import defaultdict, deque

    # 아래처럼  dict안에 dict를 한번에 만들수 있고
    # bi directional graph도 한큐에 만듬. w는 a,b 사이의 거리
    graph = defaultdict(dict)
    for u, v, w in roads:
        graph[u][v] = graph[v][u] = w

    # dict의 items를 쓰면 dict의 value가 list로 나옴. 
    # 그냥 graph[node] 면 value가 dict니까 dict로 나옴
    for adj, score in graph[node].items(): 
        if adj not in visited:
            queue.append(adj)
            visited.add(adj)

```

### 큐 순회

```python

x = [1,2,3,4]

while x:
    x.pop()

y = deque(z)
while y:
    y.popleft()

```

### not null check

```python

x = None

if x is not None:
    print("not")

```

### list 역방향 순회

```python

letters = ['A', 'B', 'C', 'D', 'E']

# 내장 함수 이용. 강추!
# list면 a.reverse() 도 있고, 이거 O(n)
for letter in reversed(letters): 
    print(letter)

for idx in range(len(letters) - 1, -1, -1):
    print(letters[idx])

# 슬라이싱 이용
for letter in letters[::-1]: # 슬라이싱 s.reverse() 보다 슬라이싱이 훨씬 빠름
    print(letter)

```

```python
# reversed 소개
# reversed(letters) 는 iterator를 반환
reversed_letters = reversed(letters)
print(reversed_letters)
next(reversed_letters) # 한개 출력됨

```

- reversed vs reverse 
  - 두개 차이가 있음.
  - reverse 
    - list의 method, 해당 list를 역순으로 배치
  - resersed
    - 모든 시퀀스형 가능
    - return은 iterator

  ```python
  #https://geekpython.in/reverse-vs-reversed-in-python
  lst = list('malayalam')

  # Creating a copy of the original list
  new_lst = lst.copy()
  # Reversing
  new_lst.reverse()

  # Comparing the lists
  if lst == new_lst:
      print("It's a Palindrome.")
  else:
      print("Not a Palindrome.")

  ```

### 나누기 2 및 바이너리 서치 및 값할당

- 문제 278

```python
# 기본 template 대로 진행한게 핵심. 
class Solution:
    def firstBadVersion(self, n: int) -> int:
        l , r , ans = 1, n, -1 # todo 이런식의 할당시 주의점 있지 않았나?

        while l <= r:
            mid = (l + r) >> 1
            if isBadVersion(mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans

```

### 연산자

> bit연산자좀 잘알아 둘 필요 있을듯

`^` Bitwise 연산자 중 xor임
`**` 제곱 연산자
`//` python3의 나눗셈 몫얻는 연산자
`%` 나머지 찾는 연산

### 트릭 👍

- 189. Rotate Array 문제의 해답중 일부 내용
- > 아래 처럼 하면 additional memory 안쓰나? 이거 비슷한 내용 책에 있었는데 확인 필요 👍
- > 아닌듯.. 

```python

nums = [1,2,3,4,5,6]
nums[:] = [10,9]
print(nums) # 이러면 nums가 [10,9] 가 됨.

```

