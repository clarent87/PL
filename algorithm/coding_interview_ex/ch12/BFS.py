graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}

def iterative_bfs(start_v):
    discovered = [start_v]
    queue = [start_v] # list를 큐처럼 쓸수는 있음. pop(0) 가 큐연산인데, 이거 많이 쓰면 deque를 쓰는게 나음.
    while queue:
        v = queue.pop(0)
        for w in graph[v]:
            if w not in discovered:
                discovered.append(w)
                queue.append(w)
    return discovered


print(f'iterative_dfs dfs: {iterative_bfs(1)}')