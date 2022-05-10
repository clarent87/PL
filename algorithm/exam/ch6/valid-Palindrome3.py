import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # 정규식으로 불필요한 문자 필터링
        s = re.sub('[^a-z0-9]', '', s)

        return s == s[::-1]  # 슬라이싱 -> 내부적으로 C로 구현되어 있어서 빠름


key = lambda x: (x.split()[1:], x.split()[0])
