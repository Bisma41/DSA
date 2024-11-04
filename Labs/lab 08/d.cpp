#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to print all elements of the linked list
void printLinkedList(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    printLinkedList(head->next);
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

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createLinkedList(arr, n);
    
    cout << "Linked list elements: ";
    printLinkedList(head);
    cout << endl;

    return 0;
}
