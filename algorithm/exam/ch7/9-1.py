from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()

        # 브루트 포스 n^3 반복
        for i in range(len(nums) - 2):

            # 중복된 값 건너뛰기
            if i > 0 and nums[i] == nums[i - 1]: # 앞전 값이랑 같으면 건너뛰어야함. 문제 조건을 보면 뛰어야하는걸 알수 있음
                continue
            for j in range(i + 1, len(nums) - 1):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                for k in range(j + 1, len(nums)):
                    if k > j + 1 and nums[k] == nums[k - 1]:
                        continue
                    if nums[i] + nums[j] + nums[k] == 0:
                        results.append([nums[i], nums[j], nums[k]])

        return results



for x in range(0,5):
    print(x)
