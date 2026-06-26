/*Node* swapNodesPairs(Node* head){

    if(head==NULL || head->next=NULL){
        return head;
    }

    Node* prev = NULL;
    Node* first head;
    Node* second = head->next;

    while(first!=NULL && second!=NULL){
        Node* third = second->next;

        second->next=first;
        first->next=third;
        if(prev !=NULL){
        prev->next=second;
        }
        else{
            head = second;
        }

        third=first;
        prev=first;
        first=third;
        if(third != NULL){
        second=third->next;
        }
        else{
            second=NULL;
        }
    }
    return head;
}*/


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

    // The approach is :

    Node* swapNodesPairs(Node* head){

        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* prev = NULL;
        Node* first = head;
        Node* second = head->next;

        while(first != NULL && second != NULL){

            Node* third = second->next;

            // Swap pair
            second->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = second;
            }
            else{
                head = second;
            }

            prev = first;
            first = third;

            if(first != NULL){
                second = first->next;
            }
            else{
                second = NULL;
            }
        }

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

    cout << "Original List: ";
    list.traverse();

    list.head = list.swapNodesPairs(list.head);

    cout << "After Swapping Pairs: ";
    list.traverse();

    return 0;
}