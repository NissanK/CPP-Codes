#include <bits/stdc++.h>

using namespace std;

// Strongly Connected Components Code
// With refrence to the CSES Problem https://cses.fi/problemset/task/1683/

void dfs1(int vertex,stack<int> &st,vector<int> &visited,vector<int> adj[]){
	visited[vertex] = 1;

	for(auto child : adj[vertex]){
		if(visited[child] == 0){
			dfs1(child,st,visited,adj);
		}
	}

	st.push(vertex);
}

void dfs2(int vertex,vector<int> &temp,vector<int> &visited,vector<int> adj[]){
	visited[vertex] = 1;
	temp.emplace_back(vertex);

	for(auto child :  adj[vertex]){
		if(visited[child] == 0){
			dfs2(child,temp,visited,adj);
		}
	}
}

void testcases(int t){
	int n,m;
	cin>>n>>m;

	vector<int> adj[n+1],tadj[n+1];

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		tadj[b].emplace_back(a);
	}

	vector<int> visited(n + 1);
	stack<int> st;
	for(int i = 1;i<=n;i++){
		if(visited[i] == 0){
			dfs1(i,st,visited,adj);
		}
	}
	for(int i = 1;i<=n;i++){
		visited[i] = 0;
	}

	vector<vector<int>> scc;

	while (!st.empty())
	{	
		int vertex = st.top();
		st.pop();
		vector<int> temp;
		if(visited[vertex] == 0){
			dfs2(vertex,temp,visited,tadj);
			scc.emplace_back(temp);
		}
	}
	vector<int> ans(n + 1);
	
	int cnt = 0;
	for(auto component : scc){
		cnt++;
		for(auto vertex : component){
			ans[vertex] = cnt;
		}
	}

	cout<<scc.size()<<endl;
	for(int i= 1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

signed main(){
	// fastio();
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		testcases(t);
	}
}