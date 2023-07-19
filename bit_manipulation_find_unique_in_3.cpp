#include<iostream>
#include<limits.h>

using namespace std;

int main(){
  
  int n;
  cin>>n;

  int a[n];
  int index[64];

  for(int i = 0;i<n;i++){
    cin>>a[i];
  }

  for(int i=0;i<64;i++){
    index[i]=0;
  }

  int temp;
  int cnt;

  for(int i = 0;i<n;i++){
    temp = a[i];
    cnt = 0;
    while (temp!=0)
    {
      if(temp & 1){
        index[cnt]++;
      }
      cnt ++;
      temp = temp >> 1;
    }
  }

  for(int i = 0;i<64;i++){
    cout<<index[i]<<' ';
  }
  // code to print index array

  cout<<endl;
  int req=0;
  for(int i = 0;i<64;i++){
    if(index[i]%3!=0){
      req = (req |(1<<i));
    }
  }

  cout<<req;
  return 0;
}