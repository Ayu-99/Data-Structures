/*
Code: Print Elements in Range
Send Feedback
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two Integers k1 and k2
Output Format :
Required elements (separated by space)
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output :
6 7 8 10
*/

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    if(root==NULL){
        return;
    }
  
    if(k1<root->data || k2<root->data){
        elementsInRangeK1K2(root->left, k1, k2);
    }
    
      
    if(k1<=root->data && root->data<=k2){
        cout<<root->data<<" ";
    }
    
    
    if(k2>root->data || k1>root->data){
        elementsInRangeK1K2(root->right, k1, k2);
    }

}
