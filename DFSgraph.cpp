#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> g[N];
bool visited[N];

void dfs(int vertex){

    // Take action on vertex after entering
    // the vertex
    visited[vertex] = 1;
    for(int child:g[vertex]){
        // Take action on child before
        // entering the child node

        if(visited[child]) continue;
        dfs(child);

        // Take action on child after exiting
        // child node
    }

    // Take action on vertex before
    // exiting the vertex
}

int main(){
    int n,m;
    cout<<"Enter the no of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    for(int i = 0; i<m-1; i++){
        cout<<"Enter Vertex 1 and Vertex 2: ";
        int x,y;
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1);
    cout<<"After preforming DFS on node 1 checking which nodes were visited"<<endl;
    for(int i = 1;i<=n;i++){
        cout<<i<<" visited: "<<visited[i]<<endl;
    }
}