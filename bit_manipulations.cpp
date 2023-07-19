#include<iostream>

using namespace std;

int getBit(int n, int pos)
{
  return ((n & (1<<pos))!=0);
}
int setbit(int n, int pos){
  return (n | (1<<pos));
}
int clearbit(int n,int pos){
  return (n & ~(1<<pos));
}
int updatebit(int n, int pos, int value){
  return (n & ~(1<<pos));
  return (n | (value<<pos));
}
int main(){
  // cout<<updatebit(5,2,0);
  // cout<<clearbit(5,2);
  // cout<<setbit(5,1);
  cout<<getBit(5,2);
  return 0;
}