#include<iostream>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;

string minWindow(string s, string t) {
        
    unordered_map<char,int> t_map;
    for(auto it:t){
        t_map[it]++;
    }
    int i = 0,j=0;
    int count = t_map.size();
    int ans = INT_MAX;
    string ans_str = "";
    pair<int,int> ij;
    while(true){
        while(count == 0){
            if(j-i<ans){
                ij.first = i;
                ij.second = j;
                ans = j-i;
            }
            cout<<ans<<endl;
            cout<<"i : "<<i<<endl;
            cout<<"j : "<<j<<endl;
            if(t_map.find(s[i]) != t_map.end()){
                if(t_map[s[i]]>=0){
                    count++;
                }
                t_map[s[i]]++;
            }
            i++;
        }
        if(j==s.size()) break;
        if(t_map.find(s[j]) != t_map.end()){
            t_map[s[j]]--;
            if(t_map[s[j]]==0){
                count--;
            }
        }
        j++;
    }
    for(int i = ij.first; i!=ij.second;i++){
        ans_str += s[i];
    }
    return ans_str;
}

int main() {

    string s,t;
    cin>>s>>t;
    cout<<minWindow(s,t);
    
}

// timetopractice
// toc

// totmtaptat
// tta

// this question is on leetcode