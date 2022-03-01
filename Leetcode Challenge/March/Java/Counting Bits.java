class Solution {
    public int[] countBits(int n) {
        int [] l = new int[n+1];
        l[0]=0;
        
        for(int i = 1; i< n+1; i++){
            if (i%2 != 0){
                
                l[i] = (l[i/2]+1);
            
            } else{
                l[i] = (l[i/2]);
            }    
        }
        return l; 
    }
}
