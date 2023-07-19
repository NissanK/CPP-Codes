#include<bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {
    long long sum = 0;
    for(int i = 1;i * i<=num ;i++){
        if(num % i == 0){
            sum += i;
            if(i * i != num) sum += num / i;
        }
    }
    return (sum - num) == num;
}

int main(){
    int num;
    cin>>num;
    cout<<checkPerfectNumber(num)<<endl;
}