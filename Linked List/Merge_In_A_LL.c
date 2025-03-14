#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

//fucntion for creating 'second' LL
void create2(int A[],int n){
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=0;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void concatenate(struct Node *p,struct Node *q){
    third=p;
    while(p->next)
        p=p->next;
    p->next=q;
    second=NULL;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data <q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=p;
}
int main(){
    int A[]={1,3,5,7,9,11};
    int B[]={2,4,6,8,10,12};
    create(A,6);
    create2(B,6);
    printf("1st LL: ");
    display(first);
    printf("2nd LL: ");
    display(second);
    Merge(first,second);
    printf("Merged LL: ");
    display(third);
    return 0;
}
