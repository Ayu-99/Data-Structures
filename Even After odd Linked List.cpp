/*
Even after Odd LinkedList
Send Feedback
Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
You don't need to print the elements, instead return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
1 11 3 6 8 0 9 -1
Sample Output 2 :
1 11 3 9 6 8 0
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

node* arrange_LinkedList(node* head)
{
    //write your code here
    node *oddH=NULL, *oddT=NULL, *evenH=NULL, *evenT=NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(evenH == NULL){
                evenH=head;
                evenT=head;
                head=head->next;
            }else{
                evenT->next=head;
                evenT=evenT->next;
                head=head->next;
            }
            
            
            
        }else{
            if(oddH==NULL){
                oddH=head;
                oddT=head;
                head=head->next;
            }else{
                oddT->next=head;
                oddT=oddT->next;
                head=head->next;
            }
            
        }
        
        
    }
    if(oddH==NULL){
        return evenH;
    }
    if(evenH==NULL){
        return oddH;
    }
    
    oddT->next=NULL;
    evenT->next=NULL;
    oddT->next=evenH;
    return oddH;
    
    
}
