#include<iostream>
#include<limits.h>

using namespace std;

int main(){
  
  int n;
  cin>>n;

  int a[n];

  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int xorsum = 0;

  for(int i = 0;i<n;i++){
      xorsum ^= a[i];
  }
  int num;
  int stored=-1;
  
  for(int i = 0;i<32;i++){
    num = 1<<i;
    if((xorsum & num) != 0){
      stored = i;
      break;
    }
  }
  num = 1<<stored;
  xorsum = 0;
  int newxorsum = 0;
  for (int i= 0;i<n;i++){
      if((num | a[i]) == a[i]){
        xorsum ^= a[i];
      }
      else{
        newxorsum ^= a[i];
      }
  }
  cout<<xorsum<<' '<<newxorsum<<endl;

  return 0;
}