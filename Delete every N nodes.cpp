/*
Delete every N nodes
Send Feedback
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : M

Line 3 : N

Sample Input 1 :
1 2 3 4 5 6 7 8 -1
2
2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
1 2 3 4 5 6 7 8 -1
2
3
Sample Output 2 :
1 2 6 7
*/

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    
    
//     if(N == 0 && M != 0)
//         return head;
//     if(M == 0)
//         return nullptr;
    
    node *temp1=head, *temp2;
    
    while(temp1!=NULL){
        int c1=1, c2=0;
        while(temp1 and c1!=M){
            c1++;
            temp1=temp1->next;
        }
        if (temp1 == nullptr)
            break;
        temp2=temp1->next;
        while(temp2 and c2!=N){
            c2++;
            temp2=temp2->next;
        }
        temp1->next=temp2;
        temp1 = temp2;
    }
    
    return head;
}
