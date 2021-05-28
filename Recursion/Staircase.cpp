int staircase(int n){
    
    if (n == 1 || n == 0)  //base case
        return 1; 
    else if (n == 2)  
        return 2; 
      
    else
        return staircase(n - 3) +  
            staircase(n - 2) + 
            staircase(n - 1);
    
}
