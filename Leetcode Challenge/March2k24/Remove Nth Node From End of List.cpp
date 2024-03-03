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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *current=head, *prev=NULL, *current1=head;
        int len=0;
        while(current1!=NULL){
            len++;
            current1=current1->next;
            
        }
        
        int n1=len-n;
        int count=0;
        
        if(n1==0) head=head->next;

        else{
            while(n1>0){
                prev=current;
                current=current->next;    
                n1--;
                if(n1==0){
                    prev->next=current->next;
                }    
            
            }
        }       
         
                
        return head;
    }
};
