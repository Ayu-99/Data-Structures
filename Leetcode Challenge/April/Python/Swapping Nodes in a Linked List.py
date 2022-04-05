# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        ptr1 = head
        ptr2 = head
        kth = None
        k-=1
        while (k):
            ptr1 = ptr1.next
            k-=1
            
        kth = ptr1
        ptr1 = ptr1.next;
        
        while (ptr1) :
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        
        ptr2.val, kth.val = kth.val, ptr2.val
        return head
