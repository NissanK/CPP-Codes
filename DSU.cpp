#include<bits/stdc++.h>
using namespace std;

// doesnt work for directed graphs

// DSU proves to be better than DFS in case there is a dynamic graph since operations can be performed in O(~1) (average)
// whereas in DFs it takes O(V+E)
// https://youtu.be/pNSZT8WyAdM (DFS VS DSU)

const int N = 1e5 + 10;
vector<int> parent(N);
vector<int> Size(N);

void make(int v){
	parent[v] = v;
	Size[v] = 1;
}

int find(int v){
	if(v == parent[v]) return v;
	// Path Compression
	return parent[v] = find(parent[v]);
}

void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a != b){
		// Union by Size
		if(Size[a] < Size[b]) swap(a,b);
		parent[b] = a;
		Size[a] += Size[b];
	}
}

int main(){
	// finding out the number of connected components
	int n,m;
	cin>>n>>m;

	for(int i = 1;i<=n;i++){
		make(i);
	}

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b; 
		Union(a,b);
	}

	int cc = 0;
	for(int i = 1;i<=n;i++){
		if(parent[i] == i) cc++;
	}
	cout<<cc<<endl;
}