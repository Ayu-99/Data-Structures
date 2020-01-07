/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 
 */
 
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode* head){
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    
    TreeNode* helper(ListNode* head, int start, int end){
        
        if(start>end){
            return NULL;
        }
        ListNode* current=head;
        
        int mid = start+(end-start)/2;

        int count=0;
        while(count<mid && current->next!=NULL){
            current=current->next;
            count++;
        }
        
        TreeNode *root=new TreeNode(current->val);
        root->left=helper(head, start, mid-1);
        root->right=helper(head, mid+1, end);
        
        return root;
        
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len=length(head);
        
        return helper(head, 0, len-1);
        
    }
};
