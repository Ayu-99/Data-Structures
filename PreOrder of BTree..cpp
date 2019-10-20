
void preOrder(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    if(root==NULL){
        return; 
    }
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
