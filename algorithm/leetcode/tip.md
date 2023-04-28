# 리트코드

## 확인할것

str typing 안됨
<https://leetcode.com/problems/candy/> -> 이거 옛날에 삼성 문제 였다던.. 그리디네?
-> 답 <https://chat.openai.com/c/0b617d6a-f0b6-4b1e-b158-eafd90b147ae>

## 주의사항

- 종료 조건 매번 오래걸리네..
  - 종료 조건은 차근차근 검토 해야할듯.

- 역시 경계 조건을 잘 찾아야함.

## 추가 알고리즘

### 진수 변환

- https://m.blog.naver.com/icbanq/221727893563
  - > 시뮬레이션에서 필요하나봄

### LCA

https://www.crocus.co.kr/660

### dx, dy 테크닉

https://velog.io/@lio8625/dx-dy-%ED%85%8C%ED%81%AC%EB%8B%89

```python

  loop = [(0, 1), (0, -1), (1, 0), (-1, 0)] # 이방식 좋음, 인라인 가능
  while q:
      i, j = q.popleft()
      for r, c in loop:
          ir, jc = i + r, j + c
          if ir < 0 or ir >= len(mat) or jc < 0 or jc >= len(mat[0]) or mat[ir][jc] != -1:
              continue
          mat[ir][jc] = mat[i][j] + 1
          q.append((ir,jc))
  return mat

```

### 오일러 서킷

- 332. 일정 재구성 문제의 알고리즘이 오일러 서킷과 동일한것으로 보임

### Topology Sort

- 특징
  - 위상 정렬이 가능한지 판단 가능
  - 위상 정렬이 가능하다면 결과는 무엇인지 판단 가능

- 연관문제
  - 207. 코스 스케줄
  - 위상 정렬로 푼 정답은 다음과 같다

  ```python
      def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
          graph = defaultdict(list)
          indegree = {}

          # initialising dictionary
          # 1. 위상 정렬의 그 차수 table
          for i in range(numCourses):
              indegree[i] = 0

          # filling graph and indegree dictionaries
          # 2. graph는 input을 인접리스트로 구현
          # 3. 차수 table에 차수 추가
          for child, parent in prerequisites:
              graph[parent].append(child)
              indegree[child] += 1

          # 4. 위상 정렬에서 차수 0인 애들 저장하는 큐
          queue = deque()
          for key, value in indegree.items():
              if value == 0:
                  queue.append(key)

          # 5. 위상 정렬 저장 순서
          courseSequence = []
          while queue:
              course = queue.popleft()
              courseSequence.append(course)
              for neighbour in graph[course]:
                  indegree[neighbour] -= 1
                  if indegree[neighbour] == 0:
                      queue.append(neighbour)

          # 6. n개 모두 방문전에 queue가 비게 되면 courseSequence에는 vertex의 일부만 들어가 있음
          return len(courseSequence) == numCourses
  ```

- 참고
  - <https://m.blog.naver.com/ndb796/221236874984>
  - > 여기 추가 알고리즘들 좋네

### union find

pass. 위 link에 있음. 

- table을 만들어서 푸는것

### Kadane's algorithm

- 53. 최대 서브 배열 문제
  - <https://sustainable-dev.tistory.com/23>
  - > 이문제에 특화된 알고리즘으로 보임

### 플로이드 와샬

## tip

### deep copy

- `mat: List[List[int]]` 인 경우
- `dfs(i, j, 0, mat[:])` 로 dfs함수에 mat을 copy해서 넘겼다 하더라도
- 안의 list는 deepcopy가 되지 않음.


### 그리디

- 대부분 우선순위큐로 푼다
  - python에서는 PriorityQueue 보다는 heapq를 사용함

### DP 접근 법

- dp같은경우 일단 dp문제라고 판단되면, 차근차근 표를 그리는게 좋을듯.
- 이게 max-profit-with-k-transactions 문제를 보면 알지만, 표를 통해서 max_diff 수식의 insight를 얻어야함.
- 그리고 dp 문제 풀이시 table 만드는경우 행렬을 1부터 시작하는게 일반적? 인듯, 즉 0번 행렬은 비워둔다.
  - > 즉 표에 0번행렬은 있지만, 보통 계산값은. 0.. 인듯.

- 그리고 가능하면 접화식을 생각하는게 나름 도움이 된다.

### 투포인터

- 기본적으로 정렬된 곳에 쓰는것이 좋다.
- 풀어본 문제
  - slow, fast 투포인터
  - 앞 뒤 투포인터
  - 중간 찍고, 양옆으로 퍼지는 투포인터

### 슬라이딩

- 투포인터 vs 슬라이딩 윈도우 569p
  - 투포인터
    - 정렬된 배열을 대상으로 함 👍
    - 배열 앞,끝에 포인터가 위치
      - 이후 범위를 좁혀가면서 문제를 해결
      - > 물론 이방식 외에 여러가지 방식이 있을수 있음. 투 포인터 전략이 명확히 정의된 전략이 아님.
      - > 아마 런너 기법도 투 포인터 전략 부류 일듯.
    - > 자세한 내용은 189에 있음
  - 슬라이딩 윈도우
    - 고정 사이즈의 윈도우를 활용
    - 정렬 여부 관계없이 사용
    - 이동은 좌 또는 우 단방향

### 그리디 문제

이건 그냥 규칙을 잘 찾는게 중요한듯
그리디 문제 푼것들은, 그냥 각단계의 최적의 값을 구하면 되는거 였음
이거랑 heap이 잘어울림 -> 그래서 만이 쓴다함

다익스트라가 전형적인 그리디, 그리고 다익스트라는 bfs 형태로 구현해서 품.
bfs는 재귀 안됨

### 힙 이용시 주의 사항

- list 요소가 튜플이면 튜플의 첫 요소를 기준으로 힙이 구성된다는것! 👍

### 최단경로 문제

- 이거 13 장 항상 다시 참조 필요 할듯..
- 생각보다 종료 조건이나 이런거.. 문제별로 약간 차이 있는데 헷갈림
- 주의
  - dist 꼭 사용하는게 좋음 heap이랑 같이 쓴다면 👍
  - heap사용하면 뒤에 이미 도달한 vertex가 남는데, 이거 만나면 바로 return 해야함
  - 문제에 따라서는 dist없으면 이거 다시 처리 하게됨.. 특히 787문제 그랬음

### 다익스트라 구현

- 힙이용
  - <https://data-scientist-han.tistory.com/103>
  - 힙이용했을때 같은 노드가 힙에 여러번 들어갈수 있지만
  - 이경우 문제 없음
  - > 기억 안나변 확인 필요

### dfs 문제 들

- 정형화된 템플릿 외우는 것보단 기본 컨셉만 가지고 해야 할듯
  - > 근데 템플릿은 알아야 할듯
  - 가지치키
    - discover vertex list 같은..
    - 문제에 따라 discover vertex list 같은건 필요 없을수 있따
  - 그리고 백트래킹은 재귀

```python
    def combine(self, n: int, k: int) -> List[List[int]]:
        discover = []

        def dfs(element: list, start: int, k: int):
            if not k:
                discover.append(element[:])
                return

            # 아래처럼 dfs전 append, pop 형태 -> 템플릿1
            for x in range(start, n + 1):
                element.append(start) 
                dfs(element, x+1, k - 1)
                element.pop()

        dfs([], 1, k)
        return discover

```

- 섬문제의 경우 온곳을 표기해주는 전략 필요

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
