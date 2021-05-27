int length(char input[]){
	int l=0;
	for(int i=0;input[i]!='\0';i++){
		l++;
	}
	return l;
}

void pairStar(char input[], int start){
	if(input[start]=='\0'){
		return;
	}//base case
	pairStar(input, start+1); //recursive calls
	if(input[start]==input[start+1]){ //small work
		int l=length(input);
		input[l+1]='\0';
		int i;
		for(i=l-1;i>start;i--){
			input[i+1]=input[i];
		}
		input[start+1]='*';
	}
}

void pairStar(char input[]) {
    // Write your code here
    pairStar(input, 0);

}
