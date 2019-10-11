/*
Bubble Sort (Iterative) LinkedList
Send Feedback
Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
*/

//head is the head of the linked list
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


// int length(node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
/*
    if(head == NULL)
        return 0;
    node *temp = head;
    
    int size =  1+length(temp->next);
    return size;
    
}

node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    
    
    int len=length(head);
    for(int k=0; k<len; k++)
    {
        node* prev=NULL;
        node* current=head;
    while(current->next!=NULL)
    {
        
        if(current->data > current->next->data )
        {
           if(prev!=NULL)
           {
               node * temp=current->next->next;
               current->next->next = current;
               prev->next=current->next;
               current->next = temp;
               prev=prev->next;
               
           }
            else
            {
                head= current->next;
                current->next = head->next;
                head->next = current;
                prev = head;
            }
            
        }
        else{
        prev=current;
        current=current->next;
        }
    }
    }
    return head;
}

