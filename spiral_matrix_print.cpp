#include<iostream>
using namespace std;
int main(){
  
  int n,m;
  cin>>n>>m;

  int array[n][m];

  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin>>array[i][j];
    }
  }

  int rst = 0;
  int cst = 0;
  int rend = n-1;
  int cend = m-1;

  while(rst<=rend && cst<=cend){

    for(int i = cst;i<=cend;i++){
      cout<<array[rst][i]<<' ';
    }
    rst++;

    for(int i = rst;i<=rend;i++){
      cout<<array[i][cend]<<' ';
    }
    cend--;

    for(int i = cend;i>=cst;i--){
      cout<<array[rend][i]<<' ';
    }
    rend--;

    for(int i = rend;i>=rst;i--){
      cout<<array[i][cst]<<' ';
    }
    cst++;
  }

  return 0;
}