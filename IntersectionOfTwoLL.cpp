#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void push_back(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = newNode;
            return;
        }

        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    void traverse(){
        Node* ptr = head;

        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    /*int length(Node* head){
        int l = 0;

        while(head != NULL){
            l++;
            head = head->next;
        }

        return l;
    }

    Node* intersection(Node* head1, Node* head2){

        int l1 = length(head1);
        int l2 = length(head2);

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        int d=0;

        if(l1 > l2){
            d = l1 - l2;

            for(int i = 0; i < d; i++){
                ptr1 = ptr1->next;
            }
        }
        else{
            d = l2 - l1;

            for(int i = 0; i < d; i++){
                ptr2 = ptr2->next;
            }
        }

        while(ptr1 != NULL && ptr2 != NULL){

            if(ptr1 == ptr2){
                return ptr1;
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL;
    }*/

    int size(Node* head){
    int sz=0;
    Node* ptr=head;
    while(ptr!=NULL){
        ptr=ptr->next;
        sz++;
    }
    return sz;
}

Node* intersectionPoint(Node* list1, Node* list2){
    int length1 = size(list1);
    int length2 = size(list2);
    int d=0;
    Node* ptr1 = list1;
    Node* ptr2 = list2;
  
    if(length1>length2){
        d=length1-length2;
        for(int i=0;i<d;i++){
            ptr1=ptr1->next;
        }
    }
    else if(length2>length1){
    d = length2-length1;
    for(int i=0;i<d;i++){
        ptr2=ptr2->next;
    }
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;
   }
   return NULL;
}

};

int main(){

    LinkedList list1;
    LinkedList list2;

    // List 1
    list1.push_back(3);
    list1.push_back(5);

    // Common part
    Node* common = new Node(10);
    common->next = new Node(15);
    common->next->next = new Node(20);

    // Attach common part to list1
    Node* temp = list1.head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = common;

    // List 2
    list2.push_back(4);
    list2.push_back(9);
    list2.push_back(9);

    // Attach same common part to list2
    temp = list2.head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = common;

    cout << "List 1: ";
    list1.traverse();

    cout << "List 2: ";
    list2.traverse();

    Node* ans = list1.intersectionPoint(list1.head, list2.head);

    if(ans != NULL){
        cout << "Intersection Point = " << ans->data << endl;
    }
    else{
        cout << "No Intersection Found" << endl;
    }

    return 0;
}

  
