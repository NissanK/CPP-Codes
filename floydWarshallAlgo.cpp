#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9;

// FLOYD WARSHALL ALGORITHM 

// used to find out the distance between each node of a graph 
// this algorithm works for both directed and undirected graphs

// this algorithm works for -ve weights but it doest not work for -ve weight cycles 
// because shortest path is not defined for -ve weighted cycles

vector<vector<int>> dis(N,vector<int> (N,INF));
// vector<int> graph[N];

int main(){
    int n,edges;
    cin>>n>>edges;

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) dis[i][j] = 0;
        }
    }

    for(int i = 0;i<edges;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dis[x][y] = wt;
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dis[i][k] != INF && dis[k][j] != INF){ // negative infinity check
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    cout<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dis[i][j]!=INF) cout<<dis[i][j]<<" ";
            else cout<<'I'<<" ";
        }cout<<endl;
    }
}

// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 3 5 2
// 2 5 1
// 2 4 2
// 4 5 3
// 4 6 1
// 5 6 2