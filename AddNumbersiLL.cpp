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
    Node* addNumbers(Node* l1, Node* l2){
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        int carry=0;
        while(l1 != NULL || l2 != NULL || carry){
            int sum=carry;
            if(l1!=NULL){
                sum=sum+l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum=sum+l2->data;
                l2=l2->next;
            }
            carry = sum/10;
            Node* newNode = new Node(sum%10);
            curr->next = newNode;
            curr=curr->next;

        }
        return dummyNode->next;
    }
    void printResult(Node* head){
         Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList list1;
  
    list1.push_back(3);
    list1.push_back(5);

    LinkedList list2;
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(9);
     list2.push_back(9);

    LinkedList resultList;

    Node* result = resultList.addNumbers(list1.head, list2.head);

    cout << "Result: ";
    resultList.printResult(result);

    return 0;
}