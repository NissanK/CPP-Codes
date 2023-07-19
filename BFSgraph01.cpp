#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/problems/REVERSE 

const int N = 1e5 + 10;

vector<pair<int,int>> g[N];
vector<int> level(N,INT_MAX);
int n,m;

int bfs(){
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while(!q.empty()){
        int currV = q.front();
        q.pop_front();
        for(auto child : g[currV]){
            int childV = child.first;
            int wt = child.second;
            if(level[currV] + wt < level[childV]){
                level[childV]  = level[currV] + wt;
                if(wt == 1){
                    q.push_back(childV);
                }
                else{
                    q.push_front(childV);
                }
            }
        }
    }
    return level[n] == INT_MAX ? -1 : level[n];
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x == y) continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    cout<<bfs()<<endl;
}
