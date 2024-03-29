
import bisect
from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        result = 0
        for i in s:
            # 이진 검색으로 더 큰 인덱스 탐색
            index = bisect.bisect_right(g, i)
            if index > result:
                result += 1
        return result

g = [1,2,3,4,5]
s = [3,4]

children = Solution().findContentChildren(g, s)
print(children)


a = [1,2][0]

print(a)