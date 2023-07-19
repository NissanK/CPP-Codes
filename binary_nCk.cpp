#include<bits/stdc++.h>

// program to calculate nCk using binary operations and for q queries
// n, k and M are given in integer range

using namespace std;
int binExp(int a , int b,int M){
	int ans = 1;
	while(b>0){
		if(b&1){
			ans = (ans * 1ll * a) % M;
		}
		a = (a * 1ll * a)%M;
		b>>=1;
	}
	return ans;
}
const int N = 1e5 +10;
vector<int> factorials(N);
const int M = 1e9+7;

int main(){
	factorials[0]=factorials[1]= 1;

	for(int i = 1;i<=N;i++){
		factorials[i] = (factorials[i-1]* 1ll *i)%M;
	}

	int q;
	cin>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		int numerator = factorials[n];
		int denominator = (factorials[k] * 1ll * factorials[n-k])%M;
		int ans = (numerator * 1ll * binExp(denominator,M-2,M)) % M;
		cout<<ans<<endl;
	}
}