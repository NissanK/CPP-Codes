#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> g[N];
vector<int> height(N);

void dfs(int vertex,int parent=-1){
    for(int child : g[vertex]){
        if(child == parent) continue;
        height[child] = height[vertex] + 1;
        dfs(child,vertex);
    }
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

    int max_height = -1;
    int max_height_node;

    for(int i = 1;i<=n;i++){
        if(max_height<height[i]){
            max_height = height[i];
            max_height_node = i;
        }
        height[i] = 0;
    }

    dfs(max_height_node);

    max_height = 0;

    for(int i = 1;i<=n;i++){
        max_height = max(max_height,height[i]);
    }

    cout<<max_height<<endl;
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