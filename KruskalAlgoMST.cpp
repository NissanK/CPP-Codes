#include<bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm ( Minimum Spanning Tree ) using DSU 
// https://youtu.be/xDrLSOxaFrA

const int N = 1e5 + 10;

vector<int> parent(N),sz(N);

void make(int x){
	parent[x] = x;
	sz[x] = 1;
}

int find(int v){
	if(parent[v] == v){
		return v;
	}
	return find(parent[v]);
}

void Union(int a,int b){
	a = parent[a];
	b = parent[b];

	if(a!=b){
		if(sz[a] < sz[b]) swap(a,b);
		parent[b] = a;
		sz[a] = sz[b] + sz[a];
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	while(m--){
		int x,y,wt;
		cin>>x>>y>>wt;
		edges.emplace_back(make_pair(wt,make_pair(x,y)));
	}

	sort(edges.begin(),edges.end());

	for(int i = 1;i<=n;i++){
		make(i);
	}

	int totalWeight = 0;
	for(auto &edge : edges){
		int wt = edge.first;
		int x = edge.second.first;
		int y = edge.second.second;
		if(find(x) == find(y)) continue;
		Union(x,y);
		totalWeight += wt;
	}
	cout<<totalWeight<<endl;
}

// 6 9
// 5 4 9
// 1 4 1
// 5 1 4
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7