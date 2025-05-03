# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dump = ListNode()
        dump.next = head
        cur = dump
        while cur.next and cur.next.next:
            tmp1 = cur.next
            tmp2 = cur.next.next.next
            cur.next = cur.next.next
            tmp1.next.next = tmp1
            tmp1.next = tmp2 

            cur = cur.next.next
        return dump.next