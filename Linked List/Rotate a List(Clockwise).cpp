/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) 
        return head; 
  
    // len is used to store length of the linked list 
    // tmp will point to the last node after this loop 
    ListNode* tmp = head; 
    int len = 1; 
    while (tmp->next != NULL) { 
        tmp = tmp->next; 
        len++; 
    } 
  
    // If k is greater than the size 
    // of the linked list 
    if (k > len) 
        k = k % len; 
  
    // Subtract from length to convert 
    // it into left rotation 
    k = len - k; 
  
    // If no rotation needed then 
    // return the head node 
    if (k == 0) 
        return head; 
  
    // current will either point to 
    // kth or NULL after this loop 
    ListNode* current = head; 
    int cnt = 1; 
    while (cnt < k && current != NULL) { 
        current = current->next; 
        cnt++; 
    } 
  
    // If current is NULL then k is equal to the 
    // count of nodes in the list 
    // Don't change the list in this case 
    if (current == NULL) 
        return head; 
  
    // current points to the kth node 
    ListNode* kthnode = current; 
  
    // Change next of last node to previous head 
    tmp->next = head; 
  
    // Change head to (k+1)th node 
    head = kthnode->next; 
  
    // Change next of kth node to NULL 
    kthnode->next = NULL; 
  
    // Return the updated head pointer 
    return head; 
    }
};

