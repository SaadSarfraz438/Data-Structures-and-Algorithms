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