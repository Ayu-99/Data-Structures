class Solution {
    public boolean isValid(String s) {
	char[] cs = s.toCharArray();
	if (cs.length % 2 != 0)
		return false;
	Stack<Character> stack = new Stack<Character>();
    for(int i=0;i<cs.length;i++){
    	if(cs[i]=='[' || cs[i] == '(' || cs[i] == '{'){
    		stack.push(cs[i]);
    	}else{
    		if(stack.isEmpty()) return false;
    		switch (stack.pop()){
    		case '(':
    			if(cs[i]!=')') return false;
    			break;
    		case '[':
    			if(cs[i]!=']') return false;
    			break;
    		case '{':
    			if(cs[i]!='}') return false;
    			break;
    		}
    	}
    }
    if(!stack.isEmpty()) return false;
	return true;
}
}
