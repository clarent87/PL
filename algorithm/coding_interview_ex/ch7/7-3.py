from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}

        # 인덱스와 값을 바꿔서 딕셔너리로 저장
        # 즉, 키:값, value:인덱스 -> 추후에 return은 index로 해야 하기 때문
        for i, num in enumerate(nums):
            nums_map[num] = i

        # 타겟에서 첫 번째 수를 뺀 결과를 키로 조회
        for i, num in enumerate(nums):
            # i != nums_map[target - num] 는 현재 index의 수면 안되기 때문 -> 문제 조건이 같은 수를 이용할수 없음
            if target - num in nums_map and i != nums_map[target - num]:
                return [i, nums_map[target - num]]