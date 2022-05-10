# 125번 문제. 팰린드룸
# 첫번째 풀이 법
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 조건 처리
        strs = []
        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        # 풀이
        while len(strs) > 1:
            if strs.pop() != strs.pop(0):
                return False

        return True




