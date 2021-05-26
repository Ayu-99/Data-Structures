void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return;
    }
    removeX(input+1);
    if(input[0]=='x'){
        for(int i=1;i<=strlen(input);i++){
            input[i-1]=input[i];
            
        }
    }
    
}
