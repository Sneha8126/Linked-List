
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

    

Node* swappingNodes(Node* head,int x,int y){

     if(x == y){
        return head;
    }

    Node* prevptr1=NULL;
    Node* ptr1 = head;
    Node* prevptr2=NULL;
    Node* ptr2 = head;
  
    for(int i=1; i<x && ptr1!=NULL; i++){
        prevptr1=ptr1;
        ptr1=ptr1->next;
    }
    
    for(int i = 1; i<y && ptr2!=NULL; i++){
        prevptr2=ptr2;
        ptr2=ptr2->next;
    }

  // Invalid positions
    if(ptr1 == NULL || ptr2 == NULL){
        return head;
    }

       // Connect previous nodes
    if(prevptr1 != NULL){
        prevptr1->next = ptr2;
    }
    else{
        head = ptr2;
    }

   if(prevptr2 != NULL){
        prevptr2->next = ptr1;
    }
    else{
        head = ptr1;
    }

       // Swap next pointers
    Node* temp = ptr1->next;
    ptr1->next = ptr2->next;
    ptr2->next = temp;

    return head;

}


};

int main(){
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.traverse();
    list.head = list.swappingNodes(list.head,2,5);

    // The solution is:
    cout<<"After swapping nodes : "<<endl;
    list.traverseNode(list.head);
    return 0;

}