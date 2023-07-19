#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 500;
	bool primeSieve[n+1]=  {0};
	int lp[n+1] = {0};
	int hp[n+1] = {0};

	for(int i = 2;i<=n;i++){
		if(primeSieve[i]==0){
			lp[i]=hp[i]=i;
			for(int j = 2*i;j<=n;j+=i){
				primeSieve[j] = 1;
				hp[j] = i;
				if(lp[j]==0){
					lp[j] = i;
				}
			}
		}
	}

	for(int i = 2;i<=n;i++){
		cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
	}
}