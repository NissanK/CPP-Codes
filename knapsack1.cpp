#include<bits/stdc++.h>
using namespace std;

// KNAPSACK 1

// https://atcoder.jp/contests/dp/tasks/dp_d 

// video refrence
// https://youtu.be/tkoM1Pgt0Q4 

long long knapsack(int idx,int w,vector<int> &weights,vector<int> &prices,vector<vector<long long>> &dp){
    if(idx < 0) return 0;
    if(w == 0) return 0;
    if(dp[idx][w] != -1) return dp[idx][w];

    // not considering the ith element 
    long long ans = knapsack(idx -1,w,weights,prices,dp);

    //considering the ith element
    if(w - weights[idx] >= 0){
        ans = max(ans,knapsack(idx - 1,w- weights[idx],weights,prices,dp) + prices[idx]);
    }

    return dp[idx][w] = ans;
}

int main(){
    int n,w;
    cin>>n>>w;

    vector<int> weights(n);
    vector<int> prices(n);

    for(int i = 0;i<n;i++){
        cin>>weights[i];
        cin>>prices[i];
    }

    vector<vector<long long>> dp(n+5,vector<long long> (1e5 + 5,-1));

    cout<<knapsack(n-1,w,weights,prices,dp)<<endl;
}