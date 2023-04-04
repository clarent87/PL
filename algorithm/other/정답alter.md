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