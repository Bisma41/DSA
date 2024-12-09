#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to remove all elements of the linked list
void removeAllLinkedListElements(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    removeAllLinkedListElements(head);
}

Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    printLinkedList(head->next);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createLinkedList(arr, n);
    
    cout << "Original linked list: ";
    printLinkedList(head);
    cout << endl;
    
    cout << "Removing all elements from the linked list." << endl;
    removeAllLinkedListElements(head);
    
    cout << "Linked list after removal: ";
    printLinkedList(head); // should print nothing if all elements are removed
    cout << endl;

    return 0
}
