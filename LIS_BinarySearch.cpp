#include<bits/stdc++.h>
using namespace std;

// Program to find the longest increasing subsequence
// https://youtu.be/on2hvxBXJH4

// Time Complexity: O(Nlog(N))
// Space Complexity: O(N)

//NOTE : Temp is NOT the LIS

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i = 0;i<n;i++) cin>>nums[i];

    vector<int> temp;

    for(int i= 0;i<n;i++){
        if(temp.empty() || temp.back() < nums[i]){
            temp.emplace_back(nums[i]);
        }
        else{
            int st = 0;
            int end = temp.size()-1;
            // binary search to find the lower bound of nums[i] in temp vector
            while(st<end){
                int mid = (st + end) / 2;
                if(nums[i] > temp[mid]){
                    st = mid + 1;
                }
                else{
                    end = mid;
                }
            }
            int lowerBound = -1;
            if(temp[st] >= nums[i]){
                lowerBound = st;
            }
            else lowerBound = end;
            temp[lowerBound] = nums[i];
        }
    }

    cout<<temp.size()<<endl;
}

// Code to print the LIS : Time Complexity : O(N^2)
// Source Striver : https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43&ab_channel=takeUforward

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> hsh(n);
    int lastIndex = 0;
    int ans = 1;
    for(int i = 0;i<n;i++){
        hsh[i] = i;
        for(int j = 0;j<i;j++){
            if(nums[j] < nums[i]){
                if(dp[j] + 1 > dp[i]){
                    hsh[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(dp[i] > ans){
            lastIndex = i;
            ans = dp[i];
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while(lastIndex != hsh[lastIndex]){
        lastIndex = hsh[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(),lis.end());
    for(int i =0;i<ans;i++){
        cout<<lis[i]<<" ";
    }cout<<endl;
    return ans;
}

// Binary Search Code using lower_bound
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.emplace_back(arr[0]);
    for(int i = 1;i<n;i++){
        if(arr[i] > temp.back()){
            temp.emplace_back(arr[i]);
        }
        else{
            auto idx = lower_bound(temp.begin(),temp.end(),arr[i]);
            (*idx) = arr[i];
        }
    }
    return temp.size();
}