#include <iostream>
#include <limits.h>

using namespace std;

void swap(int arr[],int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    int j = l;
    for (j; j < r; j++){
        if (arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,j);
    return i + 1;
}

void quicksort(int arr[],int l,int r){
    if (l<r){
        int pi = partition(arr ,l, r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);
    cout<<endl;

    for (int i = 0; i < n; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}