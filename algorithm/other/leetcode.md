# 리트코드

## union find

## tip

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