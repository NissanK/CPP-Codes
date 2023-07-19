#include <bits/stdc++.h>
using namespace std;

// Insertion Sort code below

void insertionSort(vector<int> &arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Merge Sort code below

void Merge(vector<int> &arr,int l,int mid,int r){
    
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

void MergeSort(vector<int> &arr,int l ,int r){

    if(l<r){
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
	
}

// Quick Sort code below

int partition(vector<int>& arr,int l,int r){
    int pivot = arr[r];
    int i = l-1;
    int j = l;
    for (j; j < r; j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[j]);
    return i + 1;
}

void quickSort(vector<int> &arr,int l,int r){
    if (l<r){
        int pi = partition(arr ,l, r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }

}

int main()
{
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	vector<int> arr(n);
	for(int i = 0;i<n;i++){
		cout<<"Enter element: ";
		cin>>arr[i];
	}

	int choice = -1;
	while(choice != 0){
		cout<<"Enter the choice 0.Break, 1.Insertion Sort, 2.Merge Sort, 3.Quick Sort: ";
		cin>>choice;
        vector<int> cpy(arr);
        if(choice == 1){
            insertionSort(cpy,n);
            cout<<"Elements after Insertion Sort: "<<endl;
            for(int i = 0;i<n;i++){
                cout<<cpy[i]<<" ";
            }
            cout<<endl;
        }
        else if(choice == 2){
            MergeSort(cpy,0,n-1);
            cout<<"Elements after Merge Sort: "<<endl;
            for(int i = 0;i<n;i++){
                cout<<cpy[i]<<" ";
            }
            cout<<endl;
        }
        else if(choice == 3){
            quickSort(cpy,0,n-1);
            cout<<"Elements after Quick Sort: "<<endl;
            for(int i = 0;i<n;i++){
                cout<<cpy[i]<<" ";
            }
            cout<<endl;
        }
	}
}