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

      //Recursive approach------
    Node* reverserecursive(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* newHead=reverserecursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    bool isPalindrome(Node* head){
        if(head==NULL || head->next==NULL){
            return true;
        }
        // find middle----
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        //find second half and reverse it===
        Node* secondhalf=reverserecursive(slow->next);
        // compare bothe the halves===
        Node* p1=head;
        Node* p2=secondhalf;
        bool result=true;
        while(p2!=NULL){
            if(p1->data!=p2->data){
                result=false;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return result;
    }
};

int main(){
    LinkedList list;
    list.push_back(10);
    list.push_back(8);
    list.push_back(6);
    list.push_back(8);
    list.push_back(10);
    list.traverse();

    // Palindrome result is:
    cout<<"Is Palindrome: "<<list.isPalindrome(list.head)<<endl;
    return 0;

}