#include<bits/stdc++.h>
using namespace std;

// 0-1 BFS in a matrix

// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

vector<pair<int,int>> movements = {{0,1},{0,-1},{1,0},{-1,0}};

bool isValid(int x,int y ,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}

int bfs(int n ,int m ,vector<vector<int>> &grid,vector<vector<int>> &level){
    deque<pair<int,int>> q;
    q.push_back({0,0});
    level[0][0] = 0;
    //initialising the level with 0

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop_front();
        int x = curr.first;
        int y = curr.second;
        int val = grid[x][y];
        for(int i = 1; i<=4; i++){
            int wt = 1;
            int childX = x + movements[i-1].first;
            int childY = y + movements[i-1].second;

            if(val == i){
                wt = 0;
            }
            // to check if the child lies on the same or not
            
            if(!isValid(childX,childY,n,m)) continue;

            if(level[x][y] + wt < level[childX][childY]){
                if(wt == 1){
                    q.push_back(make_pair(childX,childY));
                    //push the next level to the back
                }
                else if(wt == 0){
                    q.push_front(make_pair(childX,childY));
                    //push the level to the front
                }
                level[childX][childY] = level[x][y] + wt;
            }
        }
    }
    return level[n-1][m-1];
}

int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> level(n,vector<int> (m,INT_MAX));

    return bfs(n,m,grid,level);
}
