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

    Node* splitAtMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }

    Node* recursivelyReverse(Node* head){
        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* newHead= recursivelyReverse(head->next);
        head->next->next=head;
        head->next=NULL;

        return newHead;
    }

    Node* ZigZagList(Node* head){
        Node* rightHead=splitAtMid(head);
        Node* rightHeadRec= recursivelyReverse(rightHead);

        //merging alternatively
        Node* left = head;
        Node* right=rightHeadRec;
        Node* tail=right;

        while(left!=NULL && right!=NULL){
            Node* leftNext = left->next;
            Node* rightNext = right->next;

            left->next=right;
            right->next=leftNext;
            tail = right;
            left=leftNext;
            right=rightNext;
        }
        if(right!=NULL){
            tail->next=right;
        }
        return head;
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
    list.pop_front();
    list.traverse();
      list.head = list.ZigZagList(list.head);
    cout<<"After applying zigzag operation: "<<endl;
    // The solution is:
    list.traverseMerge(list.head);
    return 0;

}