#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class LinkList{
private:

Node * head;
public:
LinkList(){
    head = nullptr;
}
void insertAtstart(int data){
    Node *temp = new Node{data,head};
    head = temp;
}

void insertAtEnd(int data){
    Node *temp = new Node{data,nullptr};
    if(head == nullptr){
      head= temp;
      return;
    }
node*current=head;
while(current->next!=nullptr){
    current->next;
}
current->next=temp;
}
void insertAtposition(int data,int pos){
    if(pos==1){
        insertAtstart(data);
        return;
    }
    Node *current = head;
    for(int i=1;i<pos && current != nullptr;i++){
        current = current->next;
    }
    if(current == nullptr){
        cout<<"Invalid position"<<endl;
        return;
    }
   
    Node *temp=new Node{data,current->next};
    current->next=temp;
}
void deleteFromStart(){
    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }
    Node*temp=head;
    head = head->next;
    delete temp;
}
void deleteFromEnd(){
    if(head ==nullptr){
        cout<<"List is empty\n";
        return;
    }
    Node*current = head;
    while(current->next->next != nullptr){
        current =current->next;
    }
    delete current->next;
    current->next =nullptr;
}
void deleteAtposition(int pos){
    if(head = nullptr){
        cout<<"List is empty\n";
        return;
    }
    if (pos ==1){
        deleteFromStart();
        return;
    }
    Node * current =head;
    for(int i=1; i<pos && current != nullptr; i++){
        current =current->next;
    }
    if(current == nullptr || current->next == nullptr){
        cout<<"invalid poistion";
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}
void search(int key){
    Node *current = head;
    int pos =1;
    while(current != nullptr){
        if(current->data == key){
        cout<<"Element found at position"<<pos<<endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout<<"Element not found\n";
}

void display(){
    if (head == nullptr){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node * current = head;
    while(current != nullptr){
        cout<<current->data<<"->";
        current= current->next;

    }
    cout<<"Null \n";
}


};