#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data =value;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void push_front(int value){
        Node* newNode= new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void push_back(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is empty.";
            return;
        }
        Node* ptr=head;
        head=head->next;
        delete ptr;
    }
    void pop_back(){
        if(head==NULL){
            cout<<"List is empty.";
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        delete ptr->next;
        ptr->next=NULL;
    }
    void traverse(){
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    void removeCycle(Node* head){
        //detect cycle
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"cycle exist."<<endl;
                isCycle=true;
                break;
            }
        }
        if(!isCycle){
            cout<<"No cycle exist."<<endl;
            return;
        }
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else{
            Node* prevptr=fast;
            while(slow!=fast){
                slow=slow->next;
                prevptr=fast;
                fast=fast->next;
            }
            prevptr->next=NULL;
        }

    }
};

int main(){
    LinkedList list;
    list.push_back(10);
    list.push_back(8);
    list.push_back(6);
    list.push_back(20);
    list.push_front(5);
    list.traverse();
    list.removeCycle(list.head);
    list.traverse();

    return 0;

}