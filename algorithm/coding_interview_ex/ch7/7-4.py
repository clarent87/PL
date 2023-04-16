from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}

        # 하나의 `for`문으로 통합
        # 이게 가능한 이유
        # 두수 A,B가 배열에 순서대로 있고 A+B 가 target인경우
        # 7-3은 A를 기준으로 B를 해시에서 찾는거인데
        # 여기꺼는 B를 기준으로 A를 해시에서 찾는것.
        # 즉 i가 A일때는 아직 해시 테이블에 B가 없어서 정답을 못찾지만
        # i가 B일때는 A가 해시에 있어서 정답이 찾아짐
        for i, num in enumerate(nums):
            if target - num in nums_map:
                return [nums_map[target - num], i]
            nums_map[num] = i