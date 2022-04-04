class Solution 
{
    public ListNode swapNodes(ListNode head, int k) 
    {
        ListNode curr = head;
        ListNode pointer1 = head;
        ListNode pointer2= head;
        int count = 1;
        
        while( curr != null )
        {
            if( count < k )
            {
                pointer1 = pointer1.next;
            }
            if( count > k )
            {
                pointer2 = pointer2.next;
            }
            curr = curr.next;
            count++;
        }
        
        int temp = pointer1.val;
        pointer1.val = pointer2.val;
        pointer2.val = temp;
        
        return head;
    }
}
