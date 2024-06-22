class Solution {
     public int numberOfSubarrays(int[] nums, int k) {
   
     int s=0,e=nums.length;
   
    for(int i=0;i<e;i++){
        if(nums[i]%2!=0){
            nums[i]=1;
        }else{
            nums[i]=0;
        }
    }
      
       Map<Integer,Integer> p = new HashMap();
        
     p.put(0,1);   
int ans=0,sum=0;
        
     for(int i=0;i<nums.length;i++){
         sum+=nums[i];
        if(p.containsKey(sum-k)){
            ans+=p.get(sum-k);
        } 
         p.put(sum,p.getOrDefault(sum,0)+1);
     }   
       return ans; 
        
    }
}
