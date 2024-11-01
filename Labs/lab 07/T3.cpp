#include<iostream>
#include<unordered_set>
using namespace std;

struct DNode{
    int data;
    DNode*next;
    DNode*prev;
    DNode(int val):data(val),next(nullptr),prev(nullptr){}
};

class DoublyLinkedList{
public:
    DNode*head;
    DoublyLinkedList():head(nullptr){}

    void append(int val){
        if(!head){
            head=new DNode(val);
            return;
        }
        DNode*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new DNode(val);
        temp->next->prev=temp;
    }

    void removeDuplicates(){
        unordered_set<int>uniqueElements;
        DNode*temp=head;
        while(temp){
            if(uniqueElements.find(temp->data)!=uniqueElements.end()){
                DNode*toDelete=temp;
                if(temp->prev)temp->prev->next=temp->next;
                if(temp->next)temp->next->prev=temp->prev;
                temp=temp->next;
                delete toDelete;
            }
            else{
                uniqueElements.insert(temp->data);
                temp=temp->next;
            }
        }
    }

    void display(){
        DNode*temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLinkedList dlist;
    dlist.append(4);
    dlist.append(3);
    dlist.append(1);
    dlist.append(9);
    dlist.append(7);
    dlist.append(8);
    dlist.append(4);
    dlist.append(3);

    cout<<"Doubly Linked List before removing duplicates: ";
    dlist.display();

    dlist.removeDuplicates();

    cout<<"Doubly Linked List after removing duplicates: ";
    dlist.display();

    return 0;
}

