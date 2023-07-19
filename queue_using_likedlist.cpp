#include <iostream>
#include <string>

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

class queue{
    Node * front;
    Node * back;
    public:

    queue(){
        front = nullptr;
        back = nullptr;
    }
    void enqueue(int val){

        Node * newnode = new Node(val);
        if (front==nullptr && back == nullptr){
            front = newnode;
            back = newnode;
            return;
        }
        back->next = newnode;
        back = back->next;
    }

    void dequeue(){
        if (front == nullptr && back == nullptr){
            cout<<"No elements in the queue"<<endl;
            return;
        }
        if (front->next == nullptr){
            back = nullptr;
        }
        Node * todelete = front;
        front = front->next;
        delete todelete;

    }

    int peek(){
        if (front == nullptr){
            cout<<"No elements in the queue"<<endl;
            return -1;
        }
        return front->val;
    }

    bool empty(){
        if (front == nullptr)
        {
            return true;
        }
        return false;
    }
};

int main(){

    queue q;
    int choice = -1;
	while(choice != 0){
		cout<<"Enter your choice 0.Break, 1.Enqueue, 2.Dequeue, 3.PeekQueue, 4.Empty: ";
		cin>>choice;
		if(choice == 1){
			int element;
			cout<<"Enter the element: ";
			cin>>element;
			q.enqueue(element);
		}
		else if(choice == 2){
			q.dequeue();
		}
		else if(choice == 3){
            int ans = q.peek();
            if(ans!=-1)
                cout<<"The top element is: "<<q.peek()<<endl;
		}
		else if(choice == 4){
			if(q.empty()){
                cout<<"The queue is empty"<<endl;
            }
            else{
                cout<<"The queue is not empty"<<endl;
            }
		}
	}
}
