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
