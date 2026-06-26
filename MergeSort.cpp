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

    Node* splitAtMide(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL ){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }

    Node* merge(Node* left,Node* right){
        Node* i=left;
        Node* j=right;
        LinkedList ans;
        while(i!=NULL && j!=NULL){
            if(i->data<j->data){
                ans.push_back(i->data);
                i=i->next;
            }
            else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){
            ans.push_back(i->data);
            i=i->next;
        }
         while(j!=NULL){
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
    }
    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* rightHead = splitAtMide(head);
        Node* left = mergeSort(head);
        Node* right= mergeSort(rightHead);

        return merge(left,right);
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
    list.head = list.mergeSort(list.head);
    cout<<"After sorting: "<<endl;
    list.traverseMerge(list.head);
    return 0;

}