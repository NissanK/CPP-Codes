#include<bits/stdc++.h>
using namespace std;

int rear = -1,front = -1,sizeOfQueue;

void enqueue(vector<char> &q,char value){
    if((front == 0 && rear == sizeOfQueue -1) 
    || (rear == (front - 1)%(sizeOfQueue-1))){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else if(front == -1){
        front = rear = 0;
        q[rear] = value;
    }
    else if(rear == sizeOfQueue - 1 && front != 0){
        rear = 0;
        q[rear] = value;
    }
    else{
        rear++;
        q[rear] = value;
    }
}

int dequeue(vector<char> &q){
    if(front == -1){
        cout<<"Queue is Empty"<<endl;
        return INT_MIN;
    }
    int val = q[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else front  = (front + 1) % sizeOfQueue;
    return val;
}

void display(vector<char> &q){
    if(front == -1){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    if(rear >= front){
        for(int i = front;i<=rear;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }

    else{
        for(int i = front;i<sizeOfQueue;i++){
            cout<<q[i]<<" ";
        }
        for(int i = 0;i<=rear;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    const int n = 1000;

    cout<<"Enter the size of queue: ";
    cin>>sizeOfQueue;
    vector<char> queue(sizeOfQueue);

    int choice = -1;
    while(choice != 0){
        cout<<"Enter the choice(0: Break, 1: Enqueue, 2: Dequeue, 3: Display): ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter the element to be enqueued: ";
            char val;
            cin>>val;
            enqueue(queue,val);
        }
        else if(choice == 2){
            dequeue(queue);
        }
        else if(choice == 3){
            display(queue);
        }
        else if(choice == 0){
            break;
        }
        else{
            cout<<"Wrong Choice"<<endl;
        }
    }
}