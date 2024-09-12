 int getMiddle(Node* head) {
        // code here
        if(!head) return -1;
        Node* start = head;
        Node* end = head;
        while(end && end -> next) {
            start = start->next;
            end = end->next->next;
        }
        return start->data;
    }