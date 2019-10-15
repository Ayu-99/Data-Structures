bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int l1=0, l2=0;
    SinglyLinkedListNode *temp=head1, *temp1=head2;
    SinglyLinkedListNode *temp3=head1, *temp4=head2;

    while(temp!=NULL){
        l1++;
        temp=temp->next;
    }

    while(temp1!=NULL){
        l2++;
        temp1=temp1->next;
    }

    if(l1==l2){

        while(temp3!=NULL && temp4!=NULL){
            if(temp3->data==temp4->data){
                temp3=temp3->next;
                temp4=temp4->next;
                continue;
            }else{
                return false;
            }
        }

    }else{
        return false;
    }

    return true;
}
