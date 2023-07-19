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



// https://cses.fi/problemset/task/1688/

// Read the problem statement first this approach's complexity is n(log(n)) + q*(log^2(n))

void dfs(int vertex,int parent,vector<int> adj[],vector<int> &depth){
	depth[vertex] = depth[parent] + 1;

	for(auto child : adj[vertex]){
		if(child != parent){
			dfs(child,vertex,adj,depth);
		}
	}
}

int findParent(int vertex,int k,vector<vector<int>> &parents,int n){

	for(int i = 0;i<=log2(n);i++){
		if(k & (1<<i)){
			vertex = parents[i][vertex];
		}
	}
	return vertex;
}

void testcases(int t){
	int n,q;
	cin>>n>>q;
	vector<vector<int>> parents(log2(n) + 1,vector<int> (n+1,-1));
	vector<int> adj[n+1];
	vector<int> depth(n+1);
	parents[0][1] = -1;

	for(int i = 2;i<=n;i++){
		int x;
		cin>>x;
		parents[0][i] = x;
		adj[x].emplace_back(i);
		adj[i].emplace_back(x);
	}

	dfs(1,0,adj,depth);

	for(int i = 1;i<=log2(n);i++){
		for(int j = 1;j<=n;j++){
			int intermediate = parents[i-1][j];
			if(intermediate != -1){
				parents[i][j] = parents[i-1][intermediate];
			}
		}
	}

	while(q){
		int a,b;
		cin>>a>>b;

		if(depth[a] > depth[b]){
			swap(a,b);
		}

		// now b's level will always be lower than a's level
		int levelDiff = depth[b] - depth[a];

		for(int i = 0;i<=log2(n);i++){
			if(levelDiff & (1 << i)){
				b = parents[i][b];
			}
		}

		// now a and b are at the same level now

		//implementing the search for the lca below

		int st = 1;int end = depth[a];
		while(end - st > 1){
			int mid = (st + end)/2;
			int kth = depth[b] - mid;

			int parentA = findParent(a,kth,parents,n);			
			int parentB = findParent(b,kth,parents,n);			

			if(parentA == parentB){
				st = mid;
			}
			else{
				end = mid - 1;
			}
		}

		int parentAend = findParent(a,depth[a] - end,parents,n);
		int parentBend = findParent(b,depth[a] - end,parents,n);
		if(parentAend == parentBend){
			cout<<parentAend<<endl;
		}
		else{
			int parentAst = findParent(a,depth[a] - st,parents,n);
			cout<<parentAst<<endl;
		}
		q--;
	}
}

signed main(){
	fastio();
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		testcases(t);
	}
}
