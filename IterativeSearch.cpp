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
    int IterativeSearch(int key){
        Node* ptr=head;
        int idx=0;
        while(ptr!=NULL){
            if(ptr->data==key){
                return idx;
            }
            ptr=ptr->next;
            idx++;
        }
        return -1; // Key not found
    }

    int RecursiveSearch(Node* head,int key){
        if(head==NULL){
            return -1;
        }
        if(head->data==key){
            return 0;
        }
        int idx=RecursiveSearch(head->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
};

int main(){
    LinkedList list;
    list.push_back(10);
    list.push_back(8);
    list.push_back(6);
    list.push_back(20);
    list.push_back(50);
    list.push_back(60);
    list.push_front(5);
    list.pop_front();
    list.pop_back();
    list.traverse();
    cout<<"The key at index :"<<list.IterativeSearch(20)<<endl;
    cout<<"The key at index :"<<list.RecursiveSearch(list.head, 20)<<endl;
    return 0;

}