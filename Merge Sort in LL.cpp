/*
Code: Merge Sort
Send Feedback
Sort a given linked list using Merge Sort.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format :
Linked list elements (separated by space and terminated by -1)
Output format :
Updated LL elements (separated by space)
Constraints :
1 <= Length of LL <= 1000
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
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


node *mergeLL(node *headA, node *headB){
    node *ft=NULL, *fh=NULL;
    while(headA!=NULL && headB!=NULL){
        if(fh==NULL){
            if(headA->data>headB->data){
                ft=headB;
                fh=headB;
                headB=headB->next;
            }else{
                ft=headA;
                fh=headA;
                headA=headA->next;
                
            }
        }
        else
        {
        
        if(headA->data>headB->data){
            ft->next=headB;
            ft=ft->next;
            headB=headB->next;
            
        }else{
            ft->next=headA;
            ft=ft->next;
            headA=headA->next;
        
        }
        
        
        
        
        }
    }
    
    
    if(headA==NULL){
        ft->next=headB;
    }
    
    if(headB==NULL){
        ft->next=headA;
    }
    
    
    return fh;
    
}


node* mergeSort(node *head) {
    //write your code here
    if(head->next == NULL)
        return head;
    /*int l=0;
    node *temp=head, *temp1=head;
    
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    
    int midIndex=l/2;
    
    // //If length of linked list is even
    // if(l%2==0){
    //     midIndex=(l-1)/2;
    // }else{
    //     midIndex=(l/2);
    // }
    
    int i=0;
    while(i!=midIndex){
        i++;
        temp1=temp1->next;
    }
    
    node *head2;
    head2=temp1->next;
    temp1->next=NULL;
    */
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    node* head2=slow->next;
    slow->next=NULL;
    
    node *headA=mergeSort(head);
    node *headB=mergeSort(head2);
    
    //Merge two sorted linked list
    
    node *fh=mergeLL(headA, headB);
    return fh;
    
    
}
