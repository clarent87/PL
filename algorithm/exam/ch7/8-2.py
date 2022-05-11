from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:

        stack = []  # 리스트를 스택으로 쓸수 있었음. 스택에는 index를 넣음( 값이 아닌..)
        volume = 0

        for i in range(len(height)):

            # 변곡점을 만나는 경우
            while stack and height[i] > height[stack[-1]]:  # stack이 비어 있으면 while stack은 false
                                                            # 스택에 나보다 낮은 애들을 전부 꺼냄. 즉 스택에는 나보다 높은 애들만 들어가 있음

                # 스택에서 꺼낸다
                top = stack.pop()

                if not len(stack): # 이경우는 남은 한개를 스택에서 뺀경우
                    break

                # 이전과의 차이만큼 물 높이 처리
                distance = i - stack[-1] - 1
                waters = min(height[i], height[stack[-1]]) - height[top]

                volume += distance * waters

            stack.append(i)

        return volume

height = [0,1,0,2,1,0,1,3,2,1,2,1]
Solution().trap(height)
