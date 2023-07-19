#include<bits/stdc++.h>

using namespace std;

const int N = 32000;

int SegPrime[N];


int main(){
    int t;
    cin>>t;

    for(int i = 2;i<N;i++){
        if(SegPrime[i]==0){
            for(int j = i*i;j<N;j+=i){
                SegPrime[j]=1;
            }
        }
    }
    
    while(t--){
        long long l,r;
        cin>>l>>r;
        vector<int> primes(r-l+1);
        for(int i = 2;i<r;i++){
            if(SegPrime[i]==0){
                int prime_num = i;
                cout<<"prime number"<<endl;
                cout<<prime_num<<endl;
                long long base = (l/prime_num) * prime_num;
                if(base<l){
                    base += prime_num;
                }
                for(long long j = base;j<=r;j+=prime_num){
                    primes[j-l] = 1;
                }
                if(base == prime_num){
                    primes[base-l] = 0;
                }
            }
        }
        for(long long i = 0;i<primes.size();i++){
            if(i+l==1){
                continue;
            }
            if(primes[i]==0){
                cout<<i+l<<endl;
            }
        }
        if(t!=0) cout<<endl;
    }
}