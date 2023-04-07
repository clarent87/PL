# 정답 맞췄지만 더 올바른 해답 

## 19. Remove Nth Node From End of List

나는 length를 구해서 풀었는데.. 그게 아니라 정답은
n 만큼 fast pointer를 먼저 보내고

이후에 같이 slow, fast를 보내면, fast.next가 None인 순간 slow에서 node를 빼주면됨

```python
def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

    fast, slow = head, head
    for _ in range(n): # 안쓰는 변수는 이렇게..
        fast = fast.next
    if not fast:
        return head.next

    while fast.next:
        fast, slow = fast.next, slow.next

    slow.next = slow.next.next
    return head


```

## 3. Longest Substring Without Repeating Characters

이거 나름 알려진 문제 같음. 
나는 424. 가장 긴 반복 문자 대체 방식과 유사하게 풀었는데, 
이건 이런 접근 말고 아래와 같은 접근으로 했어야 훨씬 빠름

- 참조
  - https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/347818/Python3%3A-sliding-window-O(N)-with-explanation

## 567. Permutation in String

- 답은 맞췄는데 30분 걸림
- 답도 구렸음.
- 제대로 된건 아래와 같음

    ```python
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cntr, w = Counter(s1), len(s1)   

        for i in range(len(s2)):
            if s2[i] in cntr: 
                cntr[s2[i]] -= 1
            if i >= w and s2[i-w] in cntr: 
                cntr[s2[i-w]] += 1

            # counter에 있는 모든것들이 0인지 check
            # 난아래 처럼 했음
            # if s1_count.most_common(1)[0][1] == 0:
            #    return True

            if all([cntr[i] == 0 for i in cntr]): # see optimized code below
                return True

        return False

    ```