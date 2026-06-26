#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data =value;
        next = NULL;
        prev=NULL;
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
        if(head==NULL){
            head=newNode;
        }

        newNode->next=head;
         head->prev=newNode;
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
        newNode->prev=ptr;
        ptr->next=newNode;
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is empty.";
            return;
        }
        Node* ptr=head;
        head=head->next;
        head->prev=NULL;
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

    Node*  reverseDoublyLL1(Node* head){
    stack<int>st;
    Node* temp=head;
    while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
    }

    Node* reverseDoublyLL2(Node* head){
        Node* curr=head;
        Node* temp=NULL;
        while(curr!=NULL){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;

            curr=curr->prev;
        }
        return temp->prev;
    }
     void traverseMerge(Node* head){
         Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
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
    list.head=list.reverseDoublyLL2(list.head);
    cout<<"After reversing doubly linked list : "<<endl;
 list.traverseMerge(list.head);
    return 0;

}