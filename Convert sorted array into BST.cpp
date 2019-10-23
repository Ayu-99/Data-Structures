/*
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root.
Input format :
Line 1 : Integer n (Size of array)
Line 2 : Array elements (separated by space)
Output Format :
BST elements (in pre order traversal, separated by space)
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7 
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

BinaryTreeNode<int>* helper(int *input, int si, int ei){
    
    if(si>ei){
        return NULL;
    }
    
    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    
    BinaryTreeNode<int>* leftChild=helper(input, si, mid-1);
    BinaryTreeNode<int>* rightChild=helper(input, mid+1, ei);
    
    root->left=leftChild;
    root->right=rightChild;
    
    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */BinaryTreeNode<int>* root=helper(input, 0, n-1);
    return root;

}

