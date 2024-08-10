
Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head;

    // Find the length of the list
    Node* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }

    // If k is greater than the length of the list, reduce k
    k = k % length;
    if (k == 0) return head;

    // Traverse to the (k+1)-th node
    current->next = head; // Connect the end of the list to the head to make it circular
    int stepsToNewHead = k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
     Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}