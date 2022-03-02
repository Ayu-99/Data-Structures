class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.isEmpty()){
            return true;
        }
        if(t.isEmpty()){
            return false;
        }    

        if(s.length() == 1 && t.length() == 1){
            return s.charAt(0) == t.charAt(0);
        }    

        int a = 0;
        for(int i=0; i<t.length();i++){
            if(a >= s.length()) return true;
            if(s.charAt(a) == t.charAt(i)){
                a += 1;
            }
        }     
        
        
        if(a == s.length()){
            return true;
        }    
        else{
            return false;
        }    
    }
}
