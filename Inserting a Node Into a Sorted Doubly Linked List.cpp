DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *new_node=new DoublyLinkedListNode(data);
    new_node->prev=NULL;
    new_node->next=NULL;


    if(head==NULL){
        head=new_node;
        return head;
    
    }else if(head->data>new_node->data){
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
        return head;
    }else{
        
        DoublyLinkedListNode *current = head; 
  
        // locate the node after which the new node 
        // is to be inserted 
        while (current->next != NULL &&  
               current->next->data < new_node->data) 
            current = current->next; 
  
        /* Make the appropriate links */
        new_node->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            new_node->next->prev = new_node; 
  
        current->next = new_node; 
        new_node->prev = current; 
    } 

    return head;
}
