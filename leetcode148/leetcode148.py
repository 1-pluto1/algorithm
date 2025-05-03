# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.merge_sort(head)
    

    """
    对给定的链表进行归并排序
    """
    def merge_sort(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 如果链表为空或只有一个节点，无需排序直接返回
        if not head or not head.next:
            return head    
        # 获取链表的中间节点，分别对左右子链表进行排序
        mid = self.get_mid(head)
        right_sorted = self.merge_sort(mid.next)   # 排序右子链表
        mid.next = None                     # 断开两段子链表
        left_sorted = self.merge_sort(head)         # 排序左子链表
        return self.merget_two_lists(left_sorted, right_sorted)  # 两个子链表必然有序，合并两个有序的链表

    """
    获取以head为头节点的链表中间节点
    如果链表长度为奇数，返回最中间的那个节点
    如果链表长度为偶数，返回中间靠左的那个节点
    """
    def get_mid(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return head   
        
        slow, fast = head, head.next          # 快慢指针，慢指针初始为
        while fast and fast.next:     
            fast = fast.next.next    # 快指针每次移动两个节点
            slow = slow.next         # 慢指针每次移动一个节点
     
        return slow    # 快指针到达链表尾部时，慢指针即指向中间节点
    
    """
    合并两个有序链表list1和list2
    """
    def merget_two_lists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()   # 伪头节点，用于定位合并链表的头节点
        node = dummy         # 新链表当前的最后一个节点，初始为伪头节点

        # 直到两个链表都遍历完了，合并结束
        while list1 or list2:
            val1 = 50001 if not list1 else list1.val   # 如果链表1已经遍历完，val1取最大值，保证链表2的节点被选择到       
            val2 = 50001 if not list2 else list2.val   # 如果链表2已经遍历完，val2取最大值，保证链表1的节点被选择到 
            if val1 < val2:
                # 链表1的节点值更小，加入到合并链表，并更新链表1指向的节点
                node.next = list1
                list1 = list1.next
            else:
                # 链表2的节点值更小，加入到合并链表，并更新链表2指向的节点
                node.next = list2
                list2 = list2.next
            node = node.next    # 更新合并链表当前的最后一个节点指向

        return dummy.next       # 伪头节点的下一个节点即为合并链表的头节点

