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
    public ListNode swapPairs(ListNode head) {
        ListNode curr=head;
        ListNode nex=null;
        ListNode prev=null;

        int count=0;
        while(curr!=null && count<2){
            nex=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nex;
            count++;
        }

        if(nex!=null){
            head.next=swapPairs(nex);
        }
        return prev;
    }
}
