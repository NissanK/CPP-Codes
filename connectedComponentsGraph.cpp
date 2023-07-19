#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> g[N];
vector<bool> visited(N);

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){

    // Take action on vertex after entering
    // the vertex
    visited[vertex] = 1;
    current_cc.emplace_back(vertex);
    for(int child:g[vertex]){
        if(visited[child]) continue;
        // Take action on child before
        // entering the child node

        dfs(child);

        // Take action on child after exiting
        // child node
    }

    // Take action on vertex before
    // exiting the vertex
}

int main(){
    //assigning the values of the graph
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    for(int i = 1;i<=n;i++){
        if(visited[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }

    for(int i = 0;i<cc.size();i++){
        for(int k = 0;k<cc[i].size();k++){
            cout<<cc[i][k]<<" ";
        }
        cout<<endl;
    }
}

// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7