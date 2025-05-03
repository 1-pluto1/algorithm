# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA = 0
        lenB = 0
        curA, curB = headA, headB
        while curA != None:
            curA = curA.next
            lenA += 1
        while curB != None:
            curB = curB.next
            lenB += 1
        curA, curB = headA, headB
        if lenB > lenA:
            lenA, lenB = lenB, lenA
            curA, curB = curB, curA
        gap = lenA - lenB
        while gap != 0:
            curA = curA.next
            gap -= 1
        
        while curA != None:
            if curA == curB:
                return curA
            curA = curA.next
            curB = curB.next
        return None
