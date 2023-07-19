#include<bits/stdc++.h>
using namespace std;

// question link : https://leetcode.com/problems/course-schedule-ii/

// this question is based on topological sort
// topological sort only works on directed acylic graphs (DAG)
// https://youtu.be/qe_pQCh09yU

// note u can solve this question in many different ways.

bool dfs1(int x,vector<int> graph[],vector<int> &visited){
    if(visited[x]) return true;

    visited[x] = 1;
    bool ans = false;
    for(int child : graph[x]){
        ans = ans || dfs1(child,graph,visited);
    }
    visited[x] = 0;
    return ans;
}

void dfs2(int x,vector<int> graph[],vector<int> &visited,vector<int> &ans){
    if(visited[x]) return;

    visited[x] = 1;

    for(int child : graph[x]){
        dfs2(child,graph,visited,ans);
    }
    ans.emplace_back(x);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int e = prerequisites.size();
    vector<int> graph[numCourses];

    for(auto edge : prerequisites){
        int x = edge[0];
        int y = edge[1];
        graph[y].emplace_back(x);
    }


    // graph coloring algorithm to detect cylce in directed graph 
    // https://www.youtube.com/watch?v=0dJmTuMrUZM&ab_channel=TECHDOSE

    vector<int> ans;
    for(int i = 0;i<numCourses;i++){
        vector<int> visited(numCourses);
        if(dfs1(i,graph,visited)) return ans;
    }

    // ---end graph coloring

    // topological sort begins

    vector<int> visited(numCourses);

    for(int i = 0;i<numCourses;i++){
        if(visited[i]) continue;
        dfs2(i,graph,visited,ans);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}