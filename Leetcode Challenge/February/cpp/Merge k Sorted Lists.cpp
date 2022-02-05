/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class mycompare{
	public:
	bool operator()(const ListNode* a,const ListNode* b){
        return (a->val>b->val);
        }
};
	
class Solution {
	public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=new ListNode(0);
        ListNode *temp=head;
        priority_queue<ListNode*,vector<ListNode*>,mycompare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
             pq.push(lists[i]);
        }

        while(!pq.empty()){
            auto least=pq.top();
           
        return head->next;
    }
};
