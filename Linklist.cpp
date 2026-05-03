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
   
    Node *temp = new Node{data,current->next};
    current->next = temp;
}
void deleteFromStart(){
    if(head == nullptr){
        cout<<"List is empty\n";
        return;
    }
    Node *temp =head;
    head = head->next;
    delete temp;
}
}
