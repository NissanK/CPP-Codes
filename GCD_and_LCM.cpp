#include<bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
	if(b==0) return a;
	return GCD(b,a%b);
}

int main(){
	cout<<GCD(12,15)<<endl;
	cout<<GCD(12,18)<<endl;
	cout<<__gcd(12,18)<<endl;
	cout<<12*18/__gcd(12,18)<<endl;//LCM of two numbers
}