#include<bits/stdc++.h>
using namespace std;

// Program to find and print the longest increasing subsequence
// https://youtu.be/IFfYfonAFGc 

// Time Complexity: O(N^2)
// Space Complexity: O(N)

int main(){
    int n;
    cin>>n;

    vector<int> nums(n),hsh(n);

    for(int i = 0;i<n;i++) cin>>nums[i];
    for(int i = 0;i<n;i++) hsh[i] = i;

    vector<int> lis(n,1);
    int ans = 0;
    int ansIndex = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(nums[i] > nums[j]){
                if(lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                    hsh[i] = j;
                }
            }
        }

        if(lis[i] > ans){
            ans = lis[i];
            ansIndex = i;
        }
    }

    cout<<ans<<endl;

    //To Print Code
    vector<int> sequence;
    while(ansIndex != hsh[ansIndex]){
        sequence.emplace_back(nums[ansIndex]);
        ansIndex = hsh[ansIndex];
    }
    sequence.emplace_back(nums[ansIndex]);
    reverse(sequence.begin(),sequence.end());

    for(auto ele : sequence) cout<<ele<<" ";
    cout<<endl;
}