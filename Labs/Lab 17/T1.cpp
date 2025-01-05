#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int val):data(val),next(nullptr){}
};

class LinkedList{
public:
    Node*head;
    LinkedList():head(nullptr){}

    void append(int val){
        if(!head){
            head=new Node(val);
            return;
        }
        Node*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new Node(val);
    }

    void unionLists(LinkedList&list2){
        unordered_set<int>uniqueElements;
        Node*temp1=head;

        while(temp1){
            uniqueElements.insert(temp1->data);
            temp1=temp1->next;
        }

        Node*temp2=list2.head;
        Node*lastNode=head;
        while(lastNode->next){
            lastNode=lastNode->next;
        }
        while(temp2){
            if(uniqueElements.find(temp2->data)==uniqueElements.end()){
                lastNode->next=new Node(temp2->data);
                lastNode=lastNode->next;
                uniqueElements.insert(temp2->data);
            }
            temp2=temp2->next;
        }

        list2.head=nullptr;
    }

    void display(){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList list1,list2;
    list1.append(5);
    list1.append(1);
    list1.append(3);
    list1.append(7);
    list1.append(6);
    list1.append(2);

    list2.append(4);
    list2.append(9);
    list2.append(8);

    cout<<"List1 before union: ";
    list1.display();

    cout<<"List2 before union: ";
    list2.display();

    list1.unionLists(list2);

    cout<<"List1 after union: ";
    list1.display();

    cout<<"List2 after union(should be empty): ";
    list2.display();

    return 0;
}

