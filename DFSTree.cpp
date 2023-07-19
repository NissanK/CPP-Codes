#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> g[N];

vector<int> height(N);
vector<int> depth(N);

void dfs(int vertex,int parent=-1){

    for(int child : g[vertex]){
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child,vertex);
        height[vertex] = max(height[vertex],height[child]+1);
    }

}

int main(){
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].emplace_back(v2);
        g[v2].emplace_back(v1);
    }
    
    dfs(1);

    for(int i = 1;i<=n;i++){
        cout<<height[i]<<" ";
    }
    cout<<endl;

    for(int i = 1;i<=n;i++){
        cout<<depth[i]<<" ";
    }
    cout<<endl;
}

// 12
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