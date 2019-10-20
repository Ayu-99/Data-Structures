
int max(int a, int b){
    return (a>b)?a:b;
}


int height1(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    if(root==NULL){
        return 0;
    }
    
    int h1=height1(root->left);
    int h2=height1(root->right);
    int h=1+max(h1, h2);
    return h;
    

}


int height(BinaryTreeNode<int>* root){
    int h=height1(root);
    return h;
}
