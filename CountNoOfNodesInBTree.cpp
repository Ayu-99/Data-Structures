
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(root==NULL){
        return false;
    }
    
    if(root->data==x){
        return true;
    }
    
    bool ans1=isNodePresent(root->left, x);
    bool ans2=isNodePresent(root->right, x);
    
    if(ans1 ==true || ans2==true){
        return true;
    }else{
        return false;
    }

}
