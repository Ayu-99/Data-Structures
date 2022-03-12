"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
          current = head

        
          while (current != None) :
            next = current.next;

            copy= Node(current.val);
            current.next = copy;
            copy.next = next;

            current = next;
          
          current = head;
          while (current != None) :
            if (current.random != None) :
              current.next.random = current.random.next;
            
            current = current.next.next;
          

          
          current = head;
          dummy =Node(0);
          copyTail = dummy;

          while (current != None) :
            next = current.next.next;

           
            copy = current.next;
            copyTail.next = copy;
            copyTail = copy;

            
            current.next = next;

            current = next;
          

          return dummy.next;
