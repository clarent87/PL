graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}

def recursive_dfs(v, discovered=[]):  # 이거 사실 default value로 [] 쓰지 말라고 했엇는데..
    discovered.append(v)  # v는 방문.
    for w in graph[v]:
        if w not in discovered:
            recursive_dfs(w, discovered)  # discovered 에 재할당 된다 생각할수 있는데.
    return discovered

print(f'recursive dfs: {recursive_dfs(1)}')

def iterative_dfs(start_v):
    discovered = []
    stack = [start_v] # 스택에 넣음

    # 아래가 재귀랑 동일한 부분
    while stack: # vertex 갯수 만큼
        v = stack.pop()
        if v not in discovered:
            discovered.append(v)
            for w in graph[v]: # for 문은 전체 횟수가 edge의 갯수와 같음
                stack.append(w)
    return discovered

print(f'iterative_dfs dfs: {iterative_dfs(1)}')
