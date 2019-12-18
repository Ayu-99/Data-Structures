/*
Given a generic tree, print the input tree in level wise order. ####For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
wherer, N is data of any node present in the binary tree. x1, x2, x3, ...., xn are the children of node N
There is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Level wise print
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output :
10:20,30,40
20:40,50
30:
40:
40:
50:
*/

// Following is the given TreeNode structure.
/**************

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};
***************/

#include<queue>
void printLevelWise(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    
    //Edge Case
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    while(nodes.size()!=0){
        TreeNode<int>* frontNode=nodes.front();
        cout<<frontNode->data<<":";
        nodes.pop();
        for(int i=0;i<frontNode->children.size();i++){
            if(i==(frontNode->children.size()-1)){
                cout<<frontNode->children[i]->data;
            }else{
                 cout<<frontNode->children[i]->data<<",";
            }
            nodes.push(frontNode->children[i]);
        }
        cout<<endl;
    }
    
    
}


