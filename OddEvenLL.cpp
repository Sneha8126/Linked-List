
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

    void traverseNode(Node* head){
         Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

    Node* EvenOddLinkedList(Node* head){
    Node* curr = head;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    while(curr!=NULL){
        
        if(curr->data %2==0){
            if(evenHead==NULL){
                evenHead = curr;
                evenTail = curr;
            }
            else{
                evenTail->next=curr;
                evenTail=curr;
            } 
        }
        else if(curr->data %2!=0){
            if(oddHead==NULL){
             oddHead = curr;
             oddTail = curr;
            }
            else {
            oddTail->next = curr;
            oddTail=curr;
            } 
        }
        curr=curr->next;
    }
 if(evenHead == NULL)
        return oddHead;

    if(oddHead == NULL)
        return evenHead;

    evenTail->next = oddHead;
    oddTail->next = NULL;    

    return evenHead;

}


};

int main(){
    LinkedList list;
    list.push_back(10);
    list.push_back(7);
    list.push_back(8);
    list.push_back(3);
    list.push_back(20);
    list.push_back(5);
    list.traverse();
    list.head = list.EvenOddLinkedList(list.head);
    cout<<"After odd even segregate : "<<endl;

    //Result is:
    list.traverseNode(list.head);
    return 0;

}