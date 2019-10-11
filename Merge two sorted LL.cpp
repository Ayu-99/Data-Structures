/*
Code: Merge Two Sorted LL
Send Feedback
Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)
Output format :
Merged list elements (separated by space)
Constraints :
1 <= n, m <= 10^4
Sample Input :
 2 5 8 12 -1
 3 6 9 -1
Sample Output :
 2 3 5 6 8 9 12 
*/

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    
    Node *fh=NULL, *ft=NULL;
    while(head1!=NULL && head2!=NULL){
        
        if(fh== NULL && ft==NULL){
            if(head1->data>head2->data){
                fh=head2;
                ft=head2;
                head2=head2->next;
            }else{
                fh=head1;
                ft=head1;
                head1=head1->next;
            }
        }
        
        if(head1->data<head2->data){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;
            
        }else{
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
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




