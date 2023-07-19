#include<bits/stdc++.h>

using namespace std;

// for a,b<10^9 and M = 1e9 + 7

const int M = 1e9 + 7;

int binaryExponentiation(int a ,int b){
	int ans = 1;
	while(b>0){
		if(b&1){
			ans = (ans * 1ll* a )%M;
		}
		a = (a * 1ll * a)%M;
		b >>= 1;
	}
	return ans;
}
	
// for a<10^18 and M = 1e18 + 7(any prime number greater than 10^18)

const long long M = 1e18 + 7;

long long binaryExponentiation(long long a ,int b){
	long long ans = 1;
	while(b>0){
		if(b&1){
			ans = binMultiply(a,b)%M;
		}
		a = binMultiply(a,a)%M;
		b >>= 1;
	}
	return ans;
}

// log2^(n) complexity

long long binMultiply(long long a ,long long b){
	long long ans = 0;
	while(b>0){
		if(b&1){
			ans = (ans + a)%M;
		}
		a = (a + a)%M;
		b >>= 1;
	}
	return ans;
}
// for b >= 10^18 we use ETF method to find out ETF of M and then mod it with our b
int main(){
	cout<<binaryExponentiation(100000,101932)<<endl;
}