class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> q = new PriorityQueue<ListNode>((a,b) -> a.val - b.val);
        // only head pointer of all lists are added
        for(ListNode l : lists){
            if(l!=null){
                q.add(l);
            }        
        }
        ListNode head = new ListNode(-1);
        ListNode point = head;
        while(!q.isEmpty()){ 
            point.next = q.poll();
            point = point.next; 
            if(point.next!=null){
                q.add(point.next); // add next of current smallest
            }
        }
        return head.next;
    }
}
