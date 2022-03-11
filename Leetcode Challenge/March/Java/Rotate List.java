/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) {
            return head;
        }
        
        int len=1; 
        ListNode newH, tail;
        newH=tail=head;
        
        while(tail.next != null)  
        {
            tail = tail.next;
            len++;
        }
        tail.next = head;

        k = k % len;
        
        for(int i=0; i<len-k; i++) tail = tail.next; 
        newH = tail.next; 
        tail.next = null;
        return newH;
    }
}
