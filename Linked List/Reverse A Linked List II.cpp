/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    
    ListNode* reverse(ListNode* head){
        ListNode* current = head; 
        ListNode *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
        return head;
    }
    
    ListNode* reverseHelper(ListNode* start, ListNode* end){
        end->next=NULL;
        return reverse(start);
        
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n==1){
            return head;
        }
        if(head->next==NULL){
            if(m==n==1){
                return head;
            }
            return head;
        }
        
        ListNode* current=head;
        ListNode* prev=NULL;
        int count=0;
        while(count<m-1){
            prev=current;
            current=current->next;
            count++;
        }
        
        ListNode* start=current;
        while(count<n-1){
            current=current->next;
            count++;
        }
        
        ListNode* nextPrev=NULL;
        if(current->next!=NULL){
            nextPrev=current->next;
            
        }
        ListNode* end=current;
        
        
        ListNode* rev=reverseHelper(start, end);
        if(prev!=NULL){
            prev->next=rev;    
        }
        
        ListNode* temp=rev;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        if(nextPrev!=NULL){
            temp->next=nextPrev;
     
        }
        
        if(prev==NULL){
            return rev;
        }
               
        return head;
        
    }
};
