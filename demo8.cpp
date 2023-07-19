#include<bits/stdc++.h>
using namespace std;

// rabin karp and string hashing

// with refrence to the question word break on leetcode - https://leetcode.com/problems/word-break/

const int M = 1e9 + 7;
bool solve(int st,int end,vector<long long> &prefixHsh,set<int> &dict,vector<long long> &powers,vector<vector<int>> &dp){
    int n = prefixHsh.size();
    if(st == n){
        return true;
    }
    else if(end == n) return false;
    if(dp[st][end] != -1) return dp[st][end];
    // cout<<prefixHsh[end]<<" "<<prefixHsh[st]<<endl;
    long long currHash = (prefixHsh[end] - (prefixHsh[st-1]*powers[end - st + 1])%M + M)%M;
    // cout<<"st: "<<st<<" end: "<<end<<" "<<currHash<<endl; 
    bool ans = solve(st,end + 1,prefixHsh,dict,powers,dp);
    if(dict.find(currHash)!= dict.end()){
        ans = ans | solve(end + 1,end + 1,prefixHsh,dict,powers,dp);
    }
    return dp[st][end] = ans;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = wordDict.size();
    set<int> dict;

    for(int i = 0;i<n;i++){
        string currWord = wordDict[i];
        int m = currWord.size();
        long long hsh = 0;
        for(int j = 0;j<m;j++){
            hsh = ((hsh*31)%M + (currWord[j] - 'a' + 1))%M;
        }
        dict.insert(hsh);
    }

    n = s.size() + 1;
    vector<long long> prefixHsh(n);
    for(int i = 1;i<n;i++){
        prefixHsh[i] = ((prefixHsh[i-1]*31)%M + (s[i-1] - 'a' + 1))%M;
    }
    
    vector<long long> powers(301);
    powers[0] = 1;
    for(int i = 1;i<=300;i++){
        powers[i] = (powers[i-1]*31)%M;
    }
    vector<vector<int>> dp(n,vector<int> (n,-1));
    bool ans = solve(1,1,prefixHsh,dict,powers,dp);
    return ans;
}


int main(){
}