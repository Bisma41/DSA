#include <iostream>
#include "Node_Template.cpp"  // Ensure this file defines Node<T>

using namespace std;

template <typename T>
class LinkedList {
    Node<T>* head;

public:
    LinkedList() : head(NULL) {}  // Initialize head to NULL

    ~LinkedList() {
        while (head) {
            deleteNodeFromStart();
        }
    }

    LinkedList& addNodeAtStart(T d) {
        head = new Node<T>(d, head);
        return *this;
    }

    LinkedList& addNodeAtEnd(T d) {
        if (!head) {
            head = new Node<T>(d);
        } else {
            Node<T>* t = head;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = new Node<T>(d);
        }
        return *this;
    }

    LinkedList& deleteNodeFromStart() {
        if (head) {
            Node<T>* t = head;
            head = head->next;
            delete t;
        }
        return *this;
    }

    LinkedList& deleteNodeFromEnd() {
        if (!head) return *this;  // No node to delete

        if (head->next == NULL) {  // Only one node
            delete head;
            head = NULL;
        } else {
            Node<T>* t = head;
            while (t->next->next != NULL) {  // Move to second last node
                t = t->next;
            }
            delete t->next;  // Delete last node
            t->next = NULL;
        }
        return *this;
    }

    void show() const {
        for (Node<T>* t = head; t != NULL; t = t->next) {
            cout << t->data << ' ';
        }
        cout << '\n';
    }

    // Add a new element in order (assumes the list is already sorted)
    void addInOrder(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* curr = head;
            while (curr->next && curr->next->data < val) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    // Remove consecutive duplicate elements
    void removeDuplicatesElements() {
        if (!head) return;

        Node<T>* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                Node<T>* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }

    // Remove all elements that have duplicates
    void removeDuplicates() {
        Node<T>* curr = head;
        Node<T>* prev = NULL;

        while (curr) {
            bool hasDuplicate = false;
            Node<T>* runner = curr;

            // Check for duplicates
            while (runner->next) {
                if (runner->next->data == curr->data) {
                    hasDuplicate = true;
                    Node<T>* temp = runner->next;
                    runner->next = runner->next->next;  // Skip duplicate
                    delete temp;
                } else {
                    runner = runner->next;
                }
            }

            // If there were duplicates, remove the current node
            if (hasDuplicate) {
                if (prev) {
                    prev->next = curr->next;  // Link previous node to next node
                } else {
                    head = curr->next;  // Update head if first node is a duplicate
                }
                Node<T>* temp = curr;  // Store current node to delete
                curr = curr->next;      // Move to next node
                delete temp;            // Delete current node
            } else {
                prev = curr;           // Only move prev if no deletion
                curr = curr->next;     // Move to next node
            }
        }
    }

    void display() const {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;

    // Add elements in order
    list.addInOrder(3);
    list.addInOrder(1);
    list.addInOrder(2);
    list.addInOrder(3);
    list.addInOrder(3);
    list.addInOrder(4);
    list.addInOrder(4);
    list.display();  // Output: 1 2 3 3 3 4 4

    // Remove consecutive duplicates
    list.removeDuplicatesElements();
    list.display();  // Output: 1 2 3 4

    // Add more elements
    list.addInOrder(5);
    list.addInOrder(3);
    list.addInOrder(3);
    list.display();  // Output: 1 2 3 3 4 5

    // Remove all duplicates
    list.removeDuplicates();
    list.display();  // Output: 1 2 4 5

    return 0;
}
