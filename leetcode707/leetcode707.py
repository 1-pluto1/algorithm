class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = Node(0)
        self.size = 0

    def get(self, index: int) -> int:
        if index >= 0 and index < self.size:
            node = self.head
            for _ in range(index + 1):
                node = node.next
            return node.val
        else:
             return -1

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.size, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0:
            index = 0
        elif index > self.size:
            return
        temp = Node(val)
        cur = self.head
        while index != 0:
            cur = cur.next
            index -= 1
        temp.next = cur.next
        cur.next = temp
        self.size += 1
    
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index > self.size - 1:
            return
        cur = self.head
        while index != 0:
            cur = cur.next
            index -= 1
        cur.next = cur.next.next
        self.size -= 1    


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)