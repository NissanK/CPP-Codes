#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int		long long
#define ll 		long long
#define lld		long double
#define PI 		3.141592653589793238462
#define sz(x) 	((int)(x).size())
#define INF 	1e18
#define M    	1000000007
#define MOD1	 998244353
#define INF 	1e18
#define nline 	"\n"
#define pb 		push_back
#define ppb 	pop_back
#define ff 		first
#define ss 		second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key 

// Nissan Kumar is my name and I am the doomsday. 

/*...............................................................*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}


ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

void google(int t) {cout << "Case #" << t << ": ";}

vector<ll> sieveVector(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

vector<int> sieve(int n){vector<int> primes(n + 1,1);primes[0] = 0;primes[1] = 0;for(int i = 2;i*i<=n;i++){if(primes[i]){for(int j = 2*i;j<=n;j+=i){primes[j] = 0;}}}return primes;}
// change to j = i*i for better performance
vector<int> spf(int n){vector<int> spf(n + 1);for(int i = 2;i<=n;i++){spf[i] = i;}for(int i = 2;i*i<=n;i++){if(spf[i] == i){for(int j = i * i;j<=n;j+=i){if(spf[j] == j)spf[j] = i;}}}return spf;}

/*.....................................................*/

void dfs(int vertex,int parent,vector<vector<int>> &parents,vector<int> adj[],vector<int> &inTime,vector<int> &outTime,int &counter){
	inTime[vertex] = counter;
	counter++;
	parents[0][vertex] = parent;

	for(auto child: adj[vertex]){
		if(child != parent){
			dfs(child,vertex,parents,adj,inTime,outTime,counter);
			counter++;
		}
	}
	outTime[vertex] = counter;
}

bool isAncestor(int a,int b,vector<int> &inTime,vector<int> &outTime){
	if(a == b) return true;

	return inTime[a] < inTime[b] && outTime[b] < outTime[a];
}

void dfs2(int vertex,int parent,vector<int> &nodes,vector<int> adj[]){

	for(auto child : adj[vertex]){
		if(child != parent){
			dfs2(child,vertex,nodes,adj);
			nodes[vertex] += nodes[child];
		}
	}
}

void testcases(int t){
	int n,m;
	cin>>n>>m;

	vector<int> adj[n+1];
	vector<vector<int>> parents(log2(n) + 1,vector<int> (n,-1));
	int root = 0;
	for(int i = 0;i<n-1;i++){
		int x,y;
		cin>>x>>y;

		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
		if(adj[x].size() == 1) root = x;
		if(adj[y].size() == 1) root = y;
	}
	vector<int> inTime(n+ 1);
	vector<int> outTime(n+1);
	int counter = 0;
	dfs(root,-1,parents,adj,inTime,outTime,counter);
	parents[0][root]  = -1;

	vector<int> allNodes(n + 1);

	for(int i = 1;i<=log2(n);i++){
		for(int j = 1;j<=n;j++){
			int intermediate = parents[i-1][j];
			if(intermediate != -1){
				parents[i][j] = parents[i-1][intermediate];
			}
			else parents[i][j] = -1;
		}
	}

	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(isAncestor(a,b,inTime,outTime)){
			if(parents[0][a] != -1){
				allNodes[parents[0][a]] += -1;
			}
			allNodes[b] += 1;
		}
		else if(isAncestor(b,a,inTime,outTime)){
			if(parents[0][b] != -1){
				allNodes[parents[0][b]] += -1;
			}
			allNodes[a] += 1;
		}
		else{
			int lca = a;
			for(int i = log2(n);i>=0;i--){
				int parentA = parents[i][lca];
				if(parentA != -1 && !isAncestor(parentA,b,inTime,outTime)){
					lca = parentA;
				}
			}
			lca = parents[0][lca];
			int ParentOfLca = parents[0][lca];
			if(ParentOfLca != -1){
				allNodes[ParentOfLca] += -1;
			}
			allNodes[lca]+= -1;
			allNodes[a] += 1;
			allNodes[b] += 1;
		}
	}
	dfs2(root,-1,allNodes,adj);
	for(int i =1;i<=n;i++){
		cout<<allNodes[i]<<" ";
	}cout<<endl;

}

signed main(){
	fastio();
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		testcases(t);
	}
}