#include<bits/stdc++.h>
using namespace std;

// Knapsack 2
// Only the constraints are different from Knapsack 1

// watch luv video

long long knapsack(int idx,int amountLeft,vector<int> &weights,vector<int> &prices,vector<vector<long long>> &dp){
    if(amountLeft == 0) return 0;
    if(idx < 0) return 1e11;
    if(dp[idx][amountLeft] != -1) return dp[idx][amountLeft];
    // not adding the ith element
    long long ans = knapsack(idx - 1,amountLeft,weights,prices,dp);

    // adding the ith element
    if(amountLeft - prices[idx] >= 0){
        ans = min(ans,knapsack(idx -1,amountLeft - prices[idx],weights,prices,dp) + weights[idx]);
    } 
    return dp[idx][amountLeft] = ans;
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

    for(int i = 1e5;i>=0;i--){
        if(knapsack(n-1,i,weights,prices,dp) <= w){
            cout<<i<<endl;
            break;
        }
    }

}