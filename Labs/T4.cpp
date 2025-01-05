#include<iostream>
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

    void splitEven(){
        Node*temp=head;
        while(temp){
            if(temp->data%2==0){
                int halfVal=temp->data/2;
                Node*newNode=new Node(halfVal);
                newNode->next=temp->next;
                temp->data=halfVal;
                temp->next=newNode;
                temp=newNode->next;
            }
            else{
                temp=temp->next;
            }
        }
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
    LinkedList list;
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(12);
    list.append(9);

    cout<<"List before splitEven: ";
    list.display();

    list.splitEven();

    cout<<"List after splitEven: ";
    list.display();

    return 0;
}

