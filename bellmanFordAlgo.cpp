#include<bits/stdc++.h>
using namespace std;

//BELLMAN FORD ALGORITHM

// Dijkstra and Bellman Ford doesnt find shortest path for -ve edge weight cycles.
// Dijkstra CANNOT detect whether the graph has a -ve edge weight cycles.
// Bellman Ford CAN detect whether a *DIRECTED* graph has a negative edge weight cycle.

// Code to check the negative edge weight cycle in a graph, src : https://gist.github.com/SuryaPratapK/5d8de644480b94fe57041a6b6c857659
// https://youtu.be/FrLWd1tJ_Wc

// Bellman ford also find the shortest distance from one node to all other nodes considering only k nodes (https://leetcode.com/problems/cheapest-flights-within-k-stops/)

int n,m;
// n -> vertices , m -> edges 

bool bellmanFord(vector<pair<int,pair<int,int>>> &edges){
	vector<int> parent(n);
	vector<int> dist(n,INT_MAX);

	parent[0] = -1;
	dist[0] = 0;
	bool updated;
	
	for(int i = 0;i<n-1;i++){
		updated = false;
		for(int j = 0;j<m;j++){
			int x = edges[j].second.first;
			int y = edges[j].second.second;
			int wt = edges[j].first;

			if(dist[x]!=INT_MAX && dist[x] + wt < dist[y]){
				dist[y] = dist[x] + wt;
				parent[y] = x;
				updated = true;
			}
		}
		if(updated == false) break;
	}

	if(updated == true){
		for(int j = 0;j<m;j++){
			int x = edges[j].second.first;
			int y = edges[j].second.second;
			int wt = edges[j].first;
			if(dist[x]!=INT_MAX && dist[x] + wt < dist[y]){
				return true;
			}
		}
	}

	return false;
}

int main(){

	cin>>n>>m;

	vector<pair<int,pair<int,int>>> edges(m);

	while(m--){
		int x,y,wt;
		cin>>x>>y>>wt;
		edges.emplace_back(make_pair(wt,make_pair(x,y)));
	}

	cout<<bellmanFord(edges)<<endl;
}

//Time Complexity is O(VE)