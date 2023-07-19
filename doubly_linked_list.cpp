#include<iostream>
using namespace std;

class Node{
    public:

        int val;
        Node * next, * prev;
        Node(int val){
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
};

void InsertAtTail(Node * &head, int val){

    Node * newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    Node * temp_pointer = head;
    while(temp_pointer->next != nullptr){
        temp_pointer = temp_pointer->next;
    }
    temp_pointer->next = newnode;
    newnode->prev = temp_pointer;
    return;
}

void InsertAtHead(Node * &head,int val){

    Node * newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void display (Node * head){
    while (head != nullptr)
    {
        cout<<head->val<<" <==> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(Node * &head, int key){
    if (head == nullptr)
    {
        cout<<"no element is present"<<endl;
        return;
    }
    
    if (head->val == key){
        Node * todelete = head;
        head->next->prev = nullptr;
        head = head->next;
        delete todelete;
        return;
    }
    
    Node * temp_pointer = head;
    while (temp_pointer->val != key)
    {
        temp_pointer= temp_pointer->next;
    }
    
    Node *todelete = temp_pointer;
    
    temp_pointer->prev->next = temp_pointer->next;
    if (temp_pointer->next == nullptr){
        delete todelete;
        return;
    }
    else{
        temp_pointer->next->prev = temp_pointer->prev;
        delete todelete;
        return;
    }
}

int main(){
    Node * head = nullptr;
    int choice;
    while(choice !=0){
        cout<<"Enter the Choice(0.Break, 1.Insert At Head, 2.Insert at Tail, 3.Delete Element, 4.Display):";
        cin>>choice;

        if(choice == 1){
            int n;
            cout<<"Enter the element to be inserted: ";
            cin>>n;
            InsertAtHead(head,n);
        }
        else if(choice == 2){
            int n;
            cout<<"Enter the element to be inserted: ";
            cin>>n;
            InsertAtTail(head,n);
        }
        else if(choice == 3){
            int n;
            cout<<"Enter the element to be deleted: ";
            cin>>n;
            deletion(head,n);
        }
        else if(choice == 4){
            display(head);
        }
    }
    return 0;
}