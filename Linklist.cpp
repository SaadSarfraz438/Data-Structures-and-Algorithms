#include<iostream>
using namespace std;

// ================= NODE STRUCTURE =================
struct Node
{
    int data;
    Node *next;
};

// ============== LINKED LIST CLASS ==============
class LinkList{
private:

Node * head;

public:

    // ================= CONSTRUCTOR =================
LinkList(){
    head = nullptr;
}

    // ================= INSERT AT START =================
void insertAtstart(int data){
    Node *temp = new Node{data,head};
    head = temp;
}

    // ================= INSERT AT END =================
void insertAtEnd(int data){
    Node *temp = new Node{data,nullptr};
    if(head == nullptr){
      head= temp;
      return;
    }
    Node *current = head;
    while(current->next != nullptr){
        current = current->next;

    }
    current->next = temp;
}

    // ================= INSERT AT POSITION =================
void insertAtposition(int data,int pos)
{
    if (pos == 1){
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
    // ================= DELETE FROM START =================
void deleteFromStart(){
    if(head == nullptr){
        cout<<"List is empty\n";
        return;
    }
    Node *temp =head;
    head = head->next;
    delete temp;
}

    // ================= DELETE FROM END =================
void deleteFromEnd(){
    if(head ==nullptr){
        cout<<"List is empty\n";
        return;
    }
   
    Node * current = head;
    while(current->next->next != nullptr){
        current =current->next;
    }
   
    delete current->next;
    current->next =nullptr;
   
   
}

    // ================= DELETE AT POSITION =================
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

    // ================= SEARCH =================
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

    // ================= DISPLAY =================
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

// ================= MAIN FUNCTION =================
int main(){
LinkList list;
int choice, data,pos,val;
do{
    cout<<"\n Linked List Menu \n";
    cout<<"1. Insert at Start \n";
    cout<<"2. Insert at End\n";
    cout<<"3. Insert at Position\n";
    cout<<"4. Delete from Start\n";
    cout<<"5. Delete from End\n";
    cout<<"6. Delete at Position\n";
    cout<<"7. Search\n";
    cout<<"8. Display\n";
    cout<<"0. Exit\n";
    cin>>choice;

    switch(choice){
        case 1:
        cin>>data;
        list.insertAtstart(data);
        break;
        case 2:
        cin>>data;
        list.insertAtEnd(data);
        break;
        case 3:
        cout<<"Enter the Data"<<endl;
        cin>>data;
        cout<<"Enter the position"<<endl;
        cin>>pos;
        list.insertAtposition(data, pos);
        break;
        case 4:
        list.deleteFromStart();
        break;
       
        case 5:
        list.deleteFromEnd();
        break;
        case 6:
        cout<<"Enter the position which you want to delete\n";
        cin>>pos;
        list.deleteAtposition(pos);
        break;
        case 7:
        cout<<"Enter the value which you want to search\n";
        cin>>val;
        list.search(val);
        case 8:
        list.display();
        break;
       

    }
}while(choice !=0);

    return 0;
}