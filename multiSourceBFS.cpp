#include<bits/stdc++.h>
using namespace std;

// MULTI SOURCE BFS EXAMPLE QUESTION (refer luv video)

// https://www.codechef.com/problems/SNSOCIAL 

int n,m;

vector<pair<int,int>> movements = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

bool isValid(int x,int y){
    return x >= 0 && y>=0 && x<n && y<m;
}

int bfs(vector<vector<int>> &graph,vector<vector<int>> &visited,vector<vector<int>> &level){
    queue<pair<int,int>> q;
    int maxVal = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            maxVal = max(maxVal,graph[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(graph[i][j] == maxVal){
                q.push(make_pair(i,j));
                visited[i][j] = 1;
            } 
        }
    }
    int ans = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(auto movement: movements){
            int cX = x + movement.first;
            int cY = y + movement.second;

            if(!isValid(cX,cY)) continue;
            if(visited[cX][cY]) continue;
            
            q.push(make_pair(cX,cY));
            visited[cX][cY] = 1;
            level[cX][cY] = level[x][y] + 1;
            ans = max(level[cX][cY],ans);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> graph(n,vector<int> (m));
        vector<vector<int>> visited(n,vector<int> (m));
        vector<vector<int>> level(n,vector<int> (m));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>graph[i][j];
            }
        }

        cout<<bfs(graph,visited,level)<<endl;
    }
}