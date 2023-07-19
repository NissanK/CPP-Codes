#include<bits/stdc++.h>

using namespace std;

long long binMultiply(long long a ,long long b, int M){
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

long long binExponent(long long a, int b,int M){
	long long ans = 1;
	while(b>0){
		if(b&1){
			ans = binMultiply(ans,a,M)%M;
		}
		a =binMultiply(a,a,M)%M;
		b>>=1;
	}
	return ans;
}

int bCalculate(vector<int> &b){
	int bnumber = 0;

	int n = b.size();
	int idx = 0;
	for(int i = n-1;i>=0;i--){
		bnumber += (b[i]*binExponent(10,idx,1140))%1140;
		idx++;
	}
	return bnumber;
}


int superPow(int a, vector<int>& b) {
	int bnumber = bCalculate(b);
	return binExponent(a,b,1337);
}

int main(){

}