#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> countArr(1e4);

    for(int i = 0;i<n;i++){
        countArr[nums[i]]++;
    }

    for(int i = 1;i<=1e4;i++){
        countArr[i] += countArr[i-1];
    }

    vector<int> sortedArr(n);


    for(int i = n-1;i>=0;i--){
        int num = countArr[nums[i]] - 1;
        countArr[nums[i]]--;
        sortedArr[num] = nums[i];
    }
    for(auto i:sortedArr){
        cout<<i<<endl;
    }
}