
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
  
            
    void printResult(Node* head){
         Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

    Node* mergetwoSotedList(Node* head1,Node* head2){
    LinkedList ans;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
while(ptr1!=NULL && ptr2!=NULL){
  if(ptr1->data < ptr2->data){
  ans.push_back(ptr1->data);
  ptr1=ptr1->next;
  }
  else{
    ans.push_back(ptr2->data);
    ptr2=ptr2->next;
  }
   }
    while(ptr1!=NULL){
    ans.push_back(ptr1->data);
    ptr1=ptr1->next;
  }

  while(ptr2!=NULL){
      ans.push_back(ptr2->data);
    ptr2=ptr2->next;
  }
return ans.head;
}

Node* mergeKsortedList(Node* lists[],int k){
Node* result = lists[0];
for(int i = 1;i<k;i++){
result = mergetwoSotedList(result,lists[i]);
}
return result;
}
};

int main(){
    //List 1
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(7);


    //List 2
    LinkedList list2;
    list2.push_back(2);
    list2.push_back(5);
    list2.push_back(8);

    //List 3
    LinkedList list3;
    list3.push_back(3);
    list3.push_back(6);
    list3.push_back(9);

    LinkedList resultList;

    Node* lists[3];

    lists[0] = list1.head;
    lists[1] = list2.head;
    lists[2] = list3.head;

    // Result 
    Node* result = resultList.mergeKsortedList(lists, 3);

    cout << "Merged K Sorted Lists: ";
    resultList.printResult(result);

    return 0;
}