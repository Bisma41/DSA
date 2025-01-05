#include<iostream>
using namespace std;
struct Node{int data;Node* next;Node* prev;};
class DQueue{
private:
    Node* head;
public:
    DQueue(){head=nullptr;}
    int size(){if(head==nullptr)return 0;
    int count=1;Node* temp=head->next;
    while(temp!=head){count++;temp=temp->next;}
    return count;}
    
    int front(){if(head==nullptr){
        cout<<"Queue is empty"<<endl;return -1;}
    return head->data;}
    int back(){if(head==nullptr){
        cout<<"Queue is empty"<<endl;return -1;}
        return head->prev->data;}
        
    void push_front(int value){
        Node* newNode=new Node{value,nullptr,nullptr};
        if(head==nullptr){
            head=newNode;
            head->next=head;
            head->prev=head;}
            else{newNode->next=head;
            newNode->prev=head->prev;
            head->prev->next=newNode;
            head->prev=newNode;
            head=newNode;}}
            
    void push_back(int value){
        Node* newNode=new Node{value,nullptr,nullptr};
        if(head==nullptr){
            head=newNode;
			head->next=head;
			head->prev=head;
			}
            else{newNode->next=head;
			newNode->prev=head->prev;
			head->prev->next=newNode;
			head->prev=newNode;
			}
			}
    int pop_front(){
        if(head==nullptr){
            cout<<"Queue is empty."<<endl;return -1;}
            int value=head->data;
            if(head->next==head){
                delete head;head=nullptr;}
                else{Node* temp=head;
                head->prev->next=head->next;
                head->next->prev=head->prev;
                head=head->next;delete temp;
                    
                }
                return value;
        
    }
    int pop_back(){
        if(head==nullptr){
            cout<<"Queue is empty"<<endl;
            return -1;}
            int value=head->prev->data;
            if(head->next==head){
                delete head;
                head=nullptr;
                
            }
                else{Node* temp=head->prev;head->prev=temp->prev;
                temp->prev->next=head;
                delete temp;
                    
                }
                return value;
        
    }
    bool is_empty(){return head==nullptr;}
    void Clear(){while(!is_empty()){pop_front();}}
    void print(){if(head==nullptr){cout<<"No Elements"<<endl;
    return;
        
    }
    Node* temp=head;
    do{cout<<temp->data<<" ";temp=temp->next;
        
    }
    while(temp!=head);
    cout<<endl;
        
    }
};
int main(){
    DQueue dq;
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(1);
    dq.push_back(7);
    dq.push_back(9);
    cout<<"Elements: ";dq.print();
    cout<<"Size: "<<dq.size()<<endl;
    cout<<"Front: "<<dq.front()<<endl;
    cout<<"Back: "<<dq.back()<<endl;
    dq.push_front(10);cout<<"push_front(10): ";dq.print();
    dq.push_back(10);cout<<"push_back(10): ";dq.print();
    dq.pop_front();cout<<"pop_front(): ";dq.print();
    dq.pop_back();cout<<"pop_back(): ";dq.print();
    cout<<"Is empty: "<<(dq.is_empty()?"True":"False")<<endl;
    dq.Clear();cout<<"Clear: ";dq.print();
    return 0;
}

