# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
            cur = dummy = ListNode()
            carry = 0
            while l1 or l2 or carry:
                 s = carry + (l1.val if l1 else 0) + (l2.val if l2 else 0)
                 cur.next = ListNode(s % 10)
                 carry = s // 10
                 cur = cur.next
                 if l1: l1 = l1.next
                 if l2: l2 = l2.nextt
            return dummy.next