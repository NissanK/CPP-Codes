#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};

void insert_at_head(Node* &head, int val){
    Node* newnode=new Node(val);
 
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
        return;
    }
    Node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
}

void insert_at_tail(Node * &head, int val){

    Node * newnode = new Node(val);
    if (head == nullptr){
       newnode->next = newnode;
       head = newnode;
       return;
    }

    Node * temp_pointer = head;
    if (temp_pointer->next == nullptr){
        temp_pointer->next = newnode;
        newnode->next = head;
        return;
    }
    
    while(temp_pointer->next != head){
        temp_pointer = temp_pointer->next;
    }
    temp_pointer->next = newnode;
    newnode->next = head;
}

void display (Node * head){
    if (head == nullptr)
    {
        cout<<"linked list is empty"<<endl;
    }
    
    Node * temp_pointer = head;
    while (temp_pointer->next!= head){
        cout<<temp_pointer->val<<"->";
        temp_pointer = temp_pointer->next;
    }
    cout<<temp_pointer->val<<endl;
}

Node * delete_at_head (Node * &head){
    if (head == nullptr){
        cout<<"linked list is empty"<<endl;
        return head;
    }

    if (head->next==head){
        head = nullptr;
        delete head;
        return head;
    }
    
    Node * temp_pointer = head;
    while (temp_pointer->next != head){
        temp_pointer= temp_pointer->next;
    }
    Node * todelete = head;
    Node * newhead = head->next;
    temp_pointer->next = head->next;
    delete todelete;
    return newhead;
}

void deletion(Node * &head, int pos){
    if (pos==1){
        head = delete_at_head(head);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    Node *todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main (){
    
    Node * head = nullptr;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    display(head);
    deletion(head,1);
    display(head);

    return 0;
}