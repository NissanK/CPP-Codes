#include<bits/stdc++.h>
using namespace std;

int main(){
    const int N = 1e5;

    int arr[N];

    int choice = 0;
    int currSize = 0;
    while(choice != 4){
        cout<<"Enter the choice 1.Push 2.Pop 3.Display 4.Break: ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter the element: ";
            int element;
            cin>>element;

            for(int i = currSize-1;i>=0;i--){
                arr[i+1] = arr[i];
            }
            arr[0] = element;
            currSize++;
        }
        else if(choice == 2){
            if(currSize == 0){
                cout<<"The stack is empty!"<<endl;
                continue;
            }
            cout<<"The element has been popped"<<endl;

            for(int i = 0;i<currSize-1;i++){
                arr[i] = arr[i+1];
            }
            currSize--;
        }
        else if(choice == 3){
            if(currSize == 0) cout<<"The stack is empty!"<<endl;
            for(int i = 0;i<currSize;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"BYE!"<<endl;
            break;
        }
    }
}