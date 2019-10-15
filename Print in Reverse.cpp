void reversePrint(SinglyLinkedListNode* head) {
    
    SinglyLinkedListNode *current=head, *next=NULL, *prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;;

    
    }
    head=prev;
    SinglyLinkedListNode *temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data<<endl;
        temp1=temp1->next;
    }

}
