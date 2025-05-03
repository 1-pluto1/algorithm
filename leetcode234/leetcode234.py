# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp = None
        cur = head
        prev = None

        while cur != None:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        
        return prev
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        pre = head
        while fast and fast.next:
            fast = fast.next.next
            pre = slow
            slow = slow.next
        
        pre.next = None

        cur1 = head
        cur2 = self.reverseList(slow)

        while cur1 and cur2:
            if cur1.val != cur2.val:
                return False
            cur1 = cur1.next
            cur2 = cur2.next
        return True
