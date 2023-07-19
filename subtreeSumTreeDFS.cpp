#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> g[N];

// vector<int> val(N) if the graph has some values and we want to run the graph with those values

vector<int> subtreeSum(N);

void dfs(int vertex,int parent=0){
    //
    int sum = 0;
    for(int child : g[vertex]){
        //
        if(child == parent) continue;
        dfs(child,vertex);
        sum += subtreeSum[child];
        //
    }
    subtreeSum[vertex] = vertex + sum;
    //
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

    for(int i = 1;i<=n;i++){
        cout<<subtreeSum[i]<<" ";
    }
    cout<<endl;

}

// 13
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