/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<unordered_map>
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      map<int, ListNode*> m;
        ListNode* ptr = head, *p;
        int consec_sum = 0, sum;
        
        p = new ListNode(0);
        p->next = head;
        head = p;
        m[0] = head;
        
        while (ptr) {
            
            consec_sum += ptr->val;
            
            if(m.find(consec_sum) != m.end()) {
            
                ListNode* b = m[consec_sum];
                
                p = b->next;
                
                b->next = ptr->next;
                
                sum = consec_sum;
                while (p!=ptr) {
                    sum += p->val;
                    m.erase(sum);
                    p = p->next;
                }
            } else
                m[consec_sum] = ptr;
            
            ptr = ptr->next;
        }
        return head->next;
    }  
        
       
      
};
