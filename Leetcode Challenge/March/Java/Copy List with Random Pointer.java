/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node current = head, next;

          //  make copy of each node,
          // and link them together side-by-side in a single list.
          while (current != null) {
            next = current.next;

            Node copy=new Node(current.val);
            current.next = copy;
            copy.next = next;

            current = next;
          }

          
          current = head;
          while (current != null) {
            if (current.random != null) {
              current.next.random = current.random.next;
            }
            current = current.next.next;
          }

          // Third round: restore the original list, and extract the copy list.
          current = head;
          Node dummy = new Node(0);
          Node copy, copyTail = dummy;

          while (current != null) {
            next = current.next.next;

            // extract the copy
            copy = current.next;
            copyTail.next = copy;
            copyTail = copy;

            // restore the original list
            current.next = next;

            current = next;
          }

          return dummy.next;
    }
}
