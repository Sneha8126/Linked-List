#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    void traverse() {
        Node* ptr = head;

        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout<<endl;
    }

    void deleteNafterM(int M, int N) {
        Node* curr = head;

        while (curr != NULL) {

            // Skip M nodes
            for (int i = 1; i < M && curr != NULL; i++) {
                curr = curr->next;
            }

            if (curr == NULL) {
                return;
            }

            // Delete next N nodes
            Node* temp = curr->next;

            for (int i = 0; i < N && temp != NULL; i++) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }

            curr->next = temp;
            curr = temp;
        }
    }

    void DeleteNnodesafterMnodes(int M,int N){
    Node* curr=head;
    while(curr!=NULL){
        for(int i=1;i<M && curr!=NULL; i++){
        curr=curr->next;
        }
        if(curr==NULL){
            return;
        }
        Node* temp=curr->next;
        for(int i=0;i<N && temp!=NULL; i++){
           Node* nextNode= temp->next;
            delete temp;
            temp=nextNode;
        }
        curr->next=temp;
        curr=temp;
    }
}
};

int main() {

    LinkedList list;

    // Creating list: 1 -> 2 -> 3 -> ... -> 10
    for (int i = 1; i <= 10; i++) {
        list.push_back(i);
    }

    cout << "Original List: ";
    list.traverse();

    int M = 2;
    int N = 3;

    list.DeleteNnodesafterMnodes(M, N);

    cout << "Updated List: ";
    list.traverse();

    return 0;
}


