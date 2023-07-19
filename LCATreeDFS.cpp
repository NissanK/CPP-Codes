#include<bits/stdc++.h>
using namespace std;


// Time Complexity of this algorithm is O(n)

const int N = 1e4;
vector<int> g[N];
vector<int> par(N);

void dfs(int vertex,int parent = -1){
    par[vertex] = parent;
    for(int child:g[vertex]){
        if(child == parent) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int vertex){
    vector<int> ans;

    while(vertex!=-1){
        ans.emplace_back(vertex);
        vertex = par[vertex];
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].emplace_back(v2);
        g[v2].emplace_back(v1);
    }
    dfs(1);
    int x;int y;
    cin>>x>>y;
    vector<int> pathX = path(x);
    vector<int> pathY = path(y);
    int minLen = min(pathX.size(),pathY.size());
    int LCA = -1;
    for(int i = 0;i<minLen;i++){
        if(pathX[i] == pathY[i]){
            LCA = pathX[i];
        }
        else{
            break;
        }
    }

    cout<<LCA<<endl;
}



// 14
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11
// 11 14

// 7 2