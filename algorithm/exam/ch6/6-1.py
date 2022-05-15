class Solution:
    def longestPalindrome(self, s: str) -> str:

        # 팰린드롬 판별 및 투 포인터 확장
        def expand(left: int, right: int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]  # left는 + 1하는게 맞는거 같은데, right는 왜 -1을 하지 않지??
                                      # 아.. 책에도 나와 있음 slice는 n-1까지만 뽑힘.

        # 해당 사항이 없을때 빠르게 리턴
        if len(s) < 2 or s == s[::-1]:
            return s

        result = ''

        # 슬라이딩 윈도우 우측으로 이동
        for i in range(len(s) - 1):
            result = max(result,
                         expand(i, i + 1),
                         expand(i, i + 2),
                         key=len)
        return result


numbers = (1, 2, 3)
letters = ("A", "B")
a = list(zip(numbers, letters))
print(a)