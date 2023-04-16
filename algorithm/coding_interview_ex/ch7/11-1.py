from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = []
        p = 1

        # 왼쪽 곱셈
        # 처음 값은 1을 넣어주고, 순차적으로 곱해 나가면 된다.
        for i in range(0, len(nums)):
            out.append(p) # 현재 단계 값
            p = p * nums[i] # 다음 단계 값

        p = 1
        # 왼쪽 곱셈 결과에 오른쪽 값을 차례대로 곱셈
        for i in range(len(nums) - 1, 0 - 1, -1): # range를 통해 index를 오른쪽 부터 뽑음.
            out[i] = out[i] * p # 역시 첫 시작은 1을 곱하는것으로 진행하면 된다.
            p = p * nums[i]
        return out


input = [1,2,3,4]
Solution().productExceptSelf(input)

