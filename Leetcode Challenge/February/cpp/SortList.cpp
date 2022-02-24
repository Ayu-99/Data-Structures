/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        //middle of linked list
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;          
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;            
        
        ListNode* l1 = sortList(head);  //2   
        ListNode* l2 = sortList(slow);  //1 
        
        return mergelist(l1, l2);         
            
    }
    

    ListNode* mergelist(ListNode *head1, ListNode *head2)
    {
        ListNode *fh=NULL, *ft=NULL;
    while(head1!=NULL && head2!=NULL){
        
        if(fh== NULL && ft==NULL){
            if(head1->val>head2->val){
                fh=head2;
                ft=head2;
                head2=head2->next;
            }else{
                fh=head1;
                ft=head1;
                head1=head1->next;
            }
        }
        if(head1 && head2) {
            if(head1->val<head2->val){
                ft->next=head1;
                ft=ft->next;
                head1=head1->next;

            }else{
                ft->next=head2;
                ft=ft->next;
                head2=head2->next;
            }
        }
        
    }
    
    if(head1!=NULL){
        ft->next=head1;
    }
    if(head2!=NULL){
        ft->next=head2;
    }
    
    return fh;
    }
};
