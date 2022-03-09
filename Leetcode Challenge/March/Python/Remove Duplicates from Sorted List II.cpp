# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        temp=head
        dummy=ListNode(0)
        dummy.next=head
        prev=dummy
        if head==None:
            return None
        while temp!=None and temp.next!=None:

            if temp.val==temp.next.val:
                
                while temp and temp.next and temp.val==temp.next.val:
                    
                    temp=temp.next
                temp=temp.next
                prev.next=temp
                

            else:	
                prev=temp
                temp=temp.next

        return dummy.next
