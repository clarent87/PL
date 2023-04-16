# 125번 문제. 팰린드룸
# 두번쨰 풀이 법
import collections
from typing import Deque


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 조건 처리
        strs: Deque = collections.deque()
        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        # 풀이
        while len(strs) > 1:
            if strs.pop() != strs.popleft():
                return False

        return True




