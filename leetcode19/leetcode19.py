# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dumpHead = ListNode()
        dumpHead.next = head
        cnt = 0
        tail = dumpHead
        cur = dumpHead
        while tail.next != None:
            tail = tail.next
            cnt += 1
        cnt -= n
        for _ in range(cnt):
            cur = cur.next
        cur.next = cur.next.next
        return dumpHead.next