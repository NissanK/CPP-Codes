#include <iostream>
#include <limits.h>

using namespace std;

void Merge(int arr[],int l,int mid,int r){
    
    int n1 = mid-l+1;
    int n2 = r-mid;

    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++){
        arr1[i]= arr[l+i];
    }

    for(int i = 0;i<n2;i++){
        arr2[i]= arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++; i++;
        }
        else{
            arr[k]=arr2[j];
            k++; j++;
        }
    }

    while(i<n1){
        arr[k]=arr1[i];
        k++; i++;
    }

    while(j<n2){
        arr[k]=arr2[j];
        k++; j++;
    }
}

void MergeSort(int arr[],int l ,int r){

    if(l<r){
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1);
    cout<<endl;

    for (int i = 0; i < n; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}

