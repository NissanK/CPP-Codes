#include<bits/stdc++.h>
using namespace std;

// Euler Graph Algorithm

// A trail which starts and ends at same vertex is called Euler circuit.

// Conditions:
// Start Node == End Node                 <---|
// 											  |---> These points implies all the vertices should have an *EVEN* degree
// Every edge must be visited only once.  <---|

// All the edges in the graph must be present in a single component.
// All other components should not have any edges and hence should be a 1-vertex component.
// Graph with no edges is a Euler Graph

// Semi - Eulerian Graph

// A Semi Eulerian Graph is a graph in which all the edges are covered but the Starting Node != Ending Node.
// Exactly TWO vertices will have *ODD* degree which will be the starting and the ending vertex of the graph.


//  A Eulerian Path means both Semi and normal Euler Graphs (both the types)

// Time Complexity : O(V+E)

// Source : https://youtu.be/WY6Jsp3NxIk

const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> visited(N);

void dfs(int v){

	visited[v] = 1;

	for(int child : graph[v]){
		if(!visited[child]){
			dfs(child);
		}
	}
}

bool isConnected(int n){
	int node = -1;
	for(int i = 0;i<n;i++){
		if(graph[i].size()>0){
			node = i;
			break;
		}
		visited[i] = 1;
	}

	if(node == -1) return true; // no edges graph check

	dfs(node);

	for(int i = 0;i<n;i++){
		if(visited[i]==0) return false;
	}
	return true;
}

int isEulerian(int n){
	if(!isConnected(n)) return 0; // not a euler graph

	int odd = 0;
	for(int i = 0;i<n;i++){
		if(graph[i].size() & 1) odd++;
	}

	if(odd > 2) return 0; // not a euler graph
	if(odd==2) return 2;
	if(odd==0) return 1;
}

int main(){
	int n,m;
	cin>>n>>m;

	while(m--){
		int x,y;
		cin>>x>>y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	int euler = isEulerian(n);
	if(euler==2) cout<<"Semi-Eulerian"<<endl;
	else if(euler==1) cout<<"Eulerian"<<endl;
	else cout<<"Not Eulerian"<<endl;
}