/*
Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
Assume i & j given will be within limits. And i can be greater than j also.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : i and j (separated by space)

Sample Input 1 :
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9
Sample Input 2 :
3 4 5 2 6 1 9 -1
2 4
Sample Output 2 :
3 4 6 2 5 1 9

*/
/* -------------------------------------------------------------------------------------------------------------------------------*/
//head is the head of the linked list, n is number of elements to be reversed
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

#include<cstdlib>
node *swap_nodes(node *head, int i, int j){
    
    
    
    if(i==0 || j==0){
        
        if(i>j){
            int temp;
            temp=i;
            i=j;
            j=temp;
        }
        
        node *c1=head, *p1=NULL, *c2=head, *x;
        int k=0;
        while(c1!=NULL){
            
            p1=c1;
            c1=c1->next;
            
            k++;
            if(k==j){
                break;
            }
        }
        
        p1->next=c2;
        x=c1->next;
        c1->next=c2->next;
        c2->next=x;
        head=c1;    
        
        
    }else if(abs(i-j)==1){
        
        if(i>j){
            int temp;
            temp=i;
            i=j;
            j=temp;
        }
        
        node *c1=head, *p1=NULL, *c2=head;
        int k=0, m=0;
        while(c1!=NULL){
            k++;
            p1=c1;
            c1=c1->next;
            if(k==i){
                break;
            }
        }
        
        while(c2!=NULL){
            m++;
            c2=c2->next;
            if(j==m){
                break;
            }
        }
        
        p1->next=c2;
        c1->next=c2->next;
        c2->next=c1;
        
        
        
    }else if((i==0 || j==0) && abs(i-j)==1){
        
        node *c1=head, *c2=head->next;
        c1->next=c2->next;
        c2->next=c1;
        head=c2;
        
    }else{
        
        
        
        node *c1=head, *c2=head, *p1=NULL, *p2=NULL;
        int k=0, m=0;
        while(c1!=NULL){
            k++;
            p1=c1;
            c1=c1->next;
            if(k==i){
                break;
            }
            
        }
        
        while(c2!=NULL){
            m++;
            p2=c2;
            c2=c2->next;
            if(m==j){
                break;
            }
        }
        
        
        p1->next=c2;
        p2->next=c1;
        node *c=c1->next;
        c1->next=c2->next;
        c2->next=c;
        
        
    }
    
    
    return head;
    
    
}    
