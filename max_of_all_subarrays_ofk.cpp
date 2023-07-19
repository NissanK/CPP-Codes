#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;


vector <int> max_of_subarrays(int *arr, int n, int k){
    deque<int> que;
    for(int i = 0;i<k;i++){
        if(que.empty()){
            que.push_back(arr[i]);
            continue;
        }
        if(que.front()>=arr[i]){
            while(que.back() <= arr[i]){
                que.pop_back();
            }
            que.push_back(arr[i]);
        }
        if(que.front()<arr[i]){
            while(!que.empty()){
                que.pop_front();
            }
            que.push_back(arr[i]);
        }
    }
    vector<int> ans;
    ans.push_back(que.front());
    int i = 1;
    int j = k;
    while(j<n){
        if(que.front() == arr[i-1]){
            que.pop_front();
        }
        if(que.front()>=arr[j] ){
            while(que.back() <= arr[j]){
                que.pop_back();
            }
            que.push_back(arr[j]);
                
        }
        else{
            while(!que.empty()){
                que.pop_front();
            }
            que.push_back(arr[j]);
        }
        ans.push_back(que.front());
        i++;j++;
    }
    return ans;
}

int main(){
    int arr[17] = {6,3,8,39,495,38,23,5,4,3,2,6,8,9,5,3};
    int n = 17;
    int k = 5;
    vector<int> ans = max_of_subarrays(arr,n,k);
    for(auto num : ans){
        cout<<num<<" ";
    }cout<<endl;
}