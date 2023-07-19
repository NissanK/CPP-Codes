#include<bits/stdc++.h>
using namespace std;

#define int long long 

// Dijikstra Algorithm with example question

// https://codeforces.com/contest/20/problem/C

// similar to BFS
// dijkstra doesnt find shortest path for graphs with -ve edge weights.
// Time Complexity : O(VLog(V) + ElogV) for the set approach

const int N = 1e5 + 10;
vector<pair<int,int>> graph[N];
vector<int> visited(N);
vector<int> dis(N,1e12);
vector<int> parent(N,-1); // parent is only required for this particular question
vector<int> path; // this as well only for question
int n,m;

void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    minHeap.push(make_pair(0,1));
    dis[1] = 0;

    while(!minHeap.empty()){
        auto p = minHeap.top();
        minHeap.pop();

        int dist = p.first;
        int v = p.second;
        if(visited[v]) continue;
        visited[v] = 1;

        for(auto child : graph[v]){
            int childV = child.first;
            int wt = child.second;
            if(dist + wt < dis[childV]){
                dis[childV] = dist + wt;
                minHeap.push(make_pair(dis[childV],childV));
                parent[childV] = v;
            }
        }
    }

    if(dis[n] == 1e12){
        return;
    }
    else{
        while(n != -1){
            path.push_back(n);
            n = parent[n];
        }
        reverse(path.begin(),path.end());
    }
}

signed main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        if(x == y) continue;
        graph[x].push_back(make_pair(y,wt));
        graph[y].push_back(make_pair(x,wt));
    }
    dijkstra();
    if(path.empty()) cout<<-1<<endl;
    else{
        for(auto x: path){
            cout<<x<<" ";
        }cout<<endl;
    }
}