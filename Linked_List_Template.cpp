#include<iostream>
#include<typeinfo>
using namespace std;

template<class dt>

class Node{
    public:
    dt val;
    Node * next;
    Node(dt val){
        this->val= val;
        next = nullptr;
    }
};

template<class dt>
void InsertAtEnd(Node<dt> * &head,dt val){
    Node<dt> * newnode = new Node<dt>(val);
    if (head == nullptr){
        head = newnode;
        return;
    }
    Node<dt> * temp_pointer = head;
    while (temp_pointer->next != nullptr)
    {
        temp_pointer = temp_pointer->next;
    }
    temp_pointer->next = newnode;
}

template<class dt>
void display (Node<dt> * head){
    while (head != nullptr)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

template<class dt>
void InsertAtHead(Node<dt> * &head, dt val){
    Node<dt> * newnode = new Node<dt>(val);
    newnode->next = head;
    head = newnode;
}

template<class dt>
bool search(Node<dt> * head,dt key){
    while (head!= nullptr){
       if (head->val== key){
           return true;
       }
       head = head->next;
    }
    return false;
}


template<class dt>
void delete_at_head(Node<dt> * &head){
    Node<dt>* todelete = head;
    head = head->next;
    delete todelete;
}

template<class dt>
void deletion(Node<dt> * &head, dt key){

    if (head == nullptr){
        return;
    }

    if(head->val == key){
        delete_at_head(head);
        return;
    }

    Node<dt> * temp_pointer = head;
    while (temp_pointer->next->val != key){
        temp_pointer = temp_pointer->next;
    }

    if(temp_pointer == nullptr){
        cout<<"Element not found"<<endl;
        return;
    }
    
    Node<dt> * todelete = temp_pointer->next;
    temp_pointer->next  = temp_pointer->next->next;
    delete todelete;
}

template<class dt>
Node<dt> * reverse(Node<dt> * &head){
    Node<dt> * prevptr = nullptr;
    Node<dt> * currptr = head;
    Node<dt> * nextptr;

    while(currptr != nullptr){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}


int main(){
    Node<char> * head = nullptr;
    InsertAtHead(head,'f');
    InsertAtHead(head,'d');
    InsertAtHead(head,'a');
    InsertAtHead(head,'y');
    display(head);
    deletion(head,'a');
    display(head);
    cout<<search(head,'a');
}