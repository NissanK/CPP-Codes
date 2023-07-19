#include<bits/stdc++.h>
using namespace std;

//KOSARAJU ALGORITHM

//Code to print the strong connected components in a graph(SCC)
//Time Complexity O(V + E)

// https://youtu.be/Rs6DXyWpWrI

const int N = 1e5 + 10;
vector<int> graph[N],rev[N];
vector<int> visited(N);

vector<vector<int>> SCC;
vector<int> currSCC;

stack<int> st;

void dfs1(int vertex){
    visited[vertex] = 1;

    for(int child : graph[vertex]){
        if(!visited[child]){
            dfs1(child);
        }
    }
    st.push(vertex);
}

void dfs2(int vertex){
    visited[vertex] = 1;
    currSCC.emplace_back(vertex);

    for(int child : rev[vertex]){
        if(!visited[child]){
            dfs2(child);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].emplace_back(y);
        rev[y].emplace_back(x);
    }

    dfs1(0);

    int cnt = 0;

    for(int i = 0;i<n;i++){
        visited[i] = 0;
    }

    while(!st.empty()){
        int top = st.top();
        if(!visited[top]){
            dfs2(top);
            SCC.push_back(currSCC);
            currSCC.clear();
            cnt++;
        }
        st.pop();
    }

    //code to print the SCC components
    cout<<cnt<<endl;
    for(auto scc : SCC){
        for(auto vertex : scc){
            cout<<vertex<<" ";
        }cout<<endl;
    }
}

// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4