#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> visited(N);
vector<int> level(N);

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()){
        int currVertex = q.front();
        q.pop();

        for(int child : g[currVertex]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
                level[child] = level[currVertex] + 1;
            }
        }
    }
}

int main(){
    int n,e;
    cout<<"Enter the Number of Elements: ";
    cin>>n;

    cout<<"Enter the number of edges: ";
    cin>>e;
    for(int i = 0; i<e-1; i++){
        cout<<"Enter Vertex 1 and Vertex 2: ";
        int x,y;
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    bfs(1);
    cout<<"The levels of each node from the root node are: "<<endl;
    for(int i = 1; i<=n ;i++){
        cout<<i<<" "<<"level: "<<level[i]<<endl;
    }
}

// 13
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11