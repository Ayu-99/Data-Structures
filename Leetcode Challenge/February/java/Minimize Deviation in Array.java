class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a); 
        
        int min=Integer.MAX_VALUE; 
        for(int i:nums){ 
            if(i%2==1) i*=2;
            min=Math.min(min,i); 
            pq.add(i);
        }
        
        int diff=Integer.MAX_VALUE; 
        while(pq.peek()%2==0){ 
            int max=pq.remove();
            diff=Math.min(diff,max-min);
            min=Math.min(max/2,min);
            pq.add(max/2); 
        }
        
        return Math.min(diff,pq.peek()-min);
    }
}
