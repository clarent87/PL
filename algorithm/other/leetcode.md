# 리트코드

## union find

pass

## tip

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
for letter in reversed(letters):
    print(letter)

for idx in range(len(letters) - 1, -1, -1):
    print(letters[idx])

# 슬라이싱 이용
for letter in letters[::-1]:
    print(letter)

```

```python
# reversed 소개
# reversed(letters) 는 iterator를 반환
reversed_letters = reversed(letters)
print(reversed_letters)
next(reversed_letters) # 한개 출력됨

```