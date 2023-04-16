import collections
from typing import List


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        # 그래프 순서대로 구성
        for a, b in sorted(tickets):
            graph[a].append(b)

        route = []

        def dfs(a):

            # 첫 번째 값을 읽어 어휘순 방문
            while graph[a]:
                dfs(graph[a].pop(0))
            route.append(a)


        dfs('JFK')
        # 다시 뒤집어 어휘순 결과로
        return route[::-1]


tickets=[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
tickets2=[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
tickets3=[["JFK","KUL"],["JFK","NRT"], ["NRT", "LLL"]]
print(Solution().findItinerary(tickets3))
# ['JFK', 'MUC', 'LHR', 'SFO', 'SJC']
# ['JFK', 'MUC', 'LHR', 'SFO', 'SJC']