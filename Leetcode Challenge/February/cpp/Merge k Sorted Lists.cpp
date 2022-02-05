/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq; //min heap
        
        if(lists.size()==0){
            return NULL;
        }
        if(lists[0]==NULL && lists.size()==1){
            return NULL;
        }
        for(int i=0;i<lists.size();i++){
            ListNode *head=lists[i];
            if(head==NULL){
                continue;
            }
            ListNode *temp=head;
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        
        if(pq.size()==0){
            return NULL;
        }
    
        ListNode *newNode=new ListNode(pq.top());
        pq.pop();
        ListNode *finalHead=newNode;
        ListNode *tail=finalHead;
        while(!pq.empty()){
            ListNode *nextNode=new ListNode(pq.top());
            pq.pop();
            tail->next=nextNode;
            tail=tail->next;
            
        }
        
        tail->next=NULL;
        return finalHead;
        
    }
};
