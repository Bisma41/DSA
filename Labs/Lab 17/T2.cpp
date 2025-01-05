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

    void printUnique(){
        unordered_set<int>uniqueElements;
        Node*temp=head;
        while(temp){
            if(uniqueElements.find(temp->data)==uniqueElements.end()){
                cout<<temp->data<<" ";
                uniqueElements.insert(temp->data);
            }
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList list;
    list.append(15);
    list.append(5);
    list.append(13);
    list.append(7);
    list.append(6);
    list.append(13);
    list.append(7);
    list.append(5);
    list.append(4);
    list.append(3);
    list.append(4);

    cout<<"Unique elements: ";
    list.printUnique();

    return 0;
}

