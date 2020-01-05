/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/


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
            priority_queue<int, vector<int>, greater<int>> pq;
        
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
