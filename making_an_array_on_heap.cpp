#include<iostream>
#include<string>
using namespace std;

int main(){

    int *array_ptr = nullptr;
    int size=0;
    cout<<"How big do u want the array to be: ";
    cin>>size;
    array_ptr = new int[size]; //allocates array on the heap

    for (int i = 0; i < size; i++)
    {
        cin>>array_ptr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout<<array_ptr[i]<<' ';
    }

    delete [] array_ptr;// deallocates array on the heap

    return 0;
}
