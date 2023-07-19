#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// problem statement: https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
// alternate question: https://leetcode.com/problems/next-greater-element-i/

int main() {
    
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    stack<int> st;

    int NGE[n];

    for(int i = 0;i<n;i++){
        if(st.empty() || arr[i]<=arr[st.top()]){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]<arr[i]){
                int idx = st.top();
                st.pop();
                NGE[idx] = arr[i];
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        NGE[idx] = -1;
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" "<<NGE[i]<<endl;
    }
}
