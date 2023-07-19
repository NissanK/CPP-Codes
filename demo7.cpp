#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

int INF = 1e9;

vector<pair<int,int>> movements = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int x, int y ,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}

int characterReplacement(string s, int k) {
    int n = s.size();

    int st = 0;int end = 0;
    int ans = 0;
    int maxFreq = 0;
    vector<int> hsh(26,0);

    while(end < n){
        hsh[s[end] - 'a']++;

        maxFreq = max(maxFreq,hsh[s[end]-'a']);
        while(end - st + 1 - maxFreq > k){
            hsh[s[st] - 'a']--;
            st--;
        }
        end++;
    }
    return maxFreq;
}


int main(){

}