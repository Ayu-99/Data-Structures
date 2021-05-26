void replaceHelper(char str[], int start){
    if(str[start] == '\0'){
        return;
    } //base case
    replaceHelper(str, start+1); //recursive call
    
    //'small work'
    if(str[start] == 'p' && str[start+1] == 'i'){
        for(int i=strlen(str); i>=start+2;i--){
            str[i+2]=str[i];
        }
        str[start] = '3'; 
        str[start + 1] = '.'; 
        str[start + 2] = '1'; 
        str[start + 3] = '4';
    }
}

void replace(char input[]) {
    replaceHelper(input, 0);
}

