#include <iostream>
#include <string>

#define n 100
using namespace std;

class queue{

    int front;
    int back;
    int *arr;
    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    bool empty(){
        if (front>back || (front == -1 && back == -1)){
            return true;
        }
        return false;
    }

    void enqueue(int val){
        if(back==n-1){
            cout<<"queue overflow"<<endl;
            return;
        }

        if (empty()){
            front = 0;
            back = 0;
            arr[0]=val;
            return;
        }
        else{
            back++;
            arr[back]=val;
        }
    }

    void dequeue(){
        if (empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            front++;
        }
    }

    int top(){
        if (empty()){
            cout<<"queue is empty ";
            return -1;
            cout<<endl;
        }
        return arr[front];
    }

};
int main(){

    queue q;
    cout<<q.empty()<<endl;
    q.enqueue(4);
    q.enqueue(2);
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.empty()<<endl;
    cout<<q.top()<<endl;
}
