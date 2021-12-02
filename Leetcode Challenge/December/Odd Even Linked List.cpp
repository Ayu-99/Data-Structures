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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddh=NULL, *evenh=NULL, *oddt=NULL, *event=NULL;
        int count=1;
        while(head!=NULL){
            if(count%2==0){
                if(evenh==NULL){
                    evenh=head;
                    event=head;
                    head=head->next;
                }else{
                    event->next=head;
                    event=event->next;
                    head=head->next;
                }
            }else{
                if(oddh==NULL){
                    oddh=oddt=head;
                    head=head->next;
                }else{
                    oddt->next=head;
                    oddt=oddt->next;
                    head=head->next;
                }
            }
            count++;
        }
        
        if(oddh==NULL){
            return evenh;
        }
        
        if(evenh==NULL){
            return oddh;
        }
        
        event->next=NULL;
        oddt->next=evenh;
        
        return oddh;
    }
};
