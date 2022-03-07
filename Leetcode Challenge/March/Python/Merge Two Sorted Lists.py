# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        t1 = l1
        t2 = l2
        head = None
        tail = None
        
        if t1==None:
            return t2
        if t2==None:
            return t1

        while t1 != None and t2 != None:

            if t1.val < t2.val:
                if head == None:
                    head = t1
                    tail = t1
                    t1 = t1.next
                else:
                    tail.next = t1
                    tail = tail.next
                    t1=t1.next

            else:

                if head == None:
                    head = t2
                    tail = t2
                    t2 = t2.next
                else:
                    tail.next = t2
                    tail = tail.next
                    t2=t2.next

        if t1 != None:
            tail.next = t1
            tail = tail.next
            t1 = t1.next

        if t2 != None:
            tail.next = t2
            tail = tail.next
            t2 = t2.next

        return head

