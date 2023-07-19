#include<iostream>
#include<limits.h>

using namespace std;

int main(){
  int n;
  cin>>n;

  int array[n];
  for(int i= 0;i<n;i++){
    cin>>array[i];
  }
  for( int i = 0;i<(1<<n);i++){
    for(int j = 0;j<n;j++){
      if( i & (1<<j)){
        cout<<array[j]<<' ';
      }
    }cout<<endl;
  }
}