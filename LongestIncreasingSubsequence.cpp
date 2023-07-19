#include<bits/stdc++.h>
using namespace std;

// Dynamic Programming

// https://leetcode.com/problems/longest-increasing-subsequence/
// https://youtu.be/mNrzyuus2h4

int lis(int pos,vector<int> &nums,vector<int> &dp){
    if(dp[pos]!=-1) return dp[pos];
    int ans = 1;

    for(int i = 0;i<pos;i++){
        if(nums[pos] > nums[i])
            ans = max(ans,lis(i,nums,dp)+1);
    }
    return dp[pos] = ans;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,lis(i,nums,dp));
    }
    return ans;
}

// Time Complexity O(n^2)

int main(){
}