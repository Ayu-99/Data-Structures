SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *temp=head, *temp1=head->next;
    while(temp1!=NULL){

        if(temp->data==temp1->data){

            temp1=temp1->next;
        }else{
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }

    }
    temp->next=NULL;
    return head;

}
