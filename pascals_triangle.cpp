#include<iostream>
using namespace std;

int fact(int num){
    int fact = 1;
    for(int i = 1;i<=num;i++){
        fact *= i;
    }
    return fact;
}


int bcoeff(int n, int r){
    int bcoeff;
    bcoeff = fact(n)/(fact(n-r)*fact(r));
    if(r==0||n==0){
        bcoeff=1;
    }
    return bcoeff;

}

int main()
{
    int n;
    cin>>n;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n-i+1;j++){
            cout<<"  ";
        }
        for(int j=0;j<i;j++){
            cout<<bcoeff(i-1,j)<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
