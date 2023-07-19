#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> ans;

void Permutations(vector<int> vec, int idx){

    if(idx == vec.size()){
        ans.push_back(vec);
        return;
    }

    for(int i = idx;i<vec.size();i++){
        if(i != idx && vec[i] == vec[idx]){
            continue;
        }
        swap(vec[i],vec[idx]);
        Permutations(vec,idx+1);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(auto &i : vec){
        cin>>i;
    }

    sort(vec.begin(),vec.end());

    Permutations(vec,0);

    for(auto &i: ans){
        for(auto &j: i){
            cout<<j<<" ";
        }cout<<endl;
    }
}