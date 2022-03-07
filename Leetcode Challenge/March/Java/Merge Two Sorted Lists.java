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
    public ListNode mergeTwoLists(ListNode head1, ListNode head2) {
        ListNode fh=null, ft=null;
        
        if(head1 == null) return head2;
        if(head2 == null) return head1;
        while(head1!=null && head2!=null){

            if(fh== null && ft==null){
                if(head1.val>head2.val){
                    fh=head2;
                    ft=head2;
                    head2=head2.next;
                }else{
                    fh=head1;
                    ft=head1;
                    head1=head1.next;
                }
            }
            else {
                
            if(head1.val<head2.val){
                ft.next=head1;
                ft=ft.next;
                head1=head1.next;

            }else{
                ft.next=head2;
                ft=ft.next;
                head2=head2.next;
            }
            }

        }

        if(head1!=null){
            ft.next=head1;
        }
        if(head2!=null){
            ft.next=head2;
        }

        return fh;
    }
}
