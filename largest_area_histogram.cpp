// #include <iostream>
// #include <string>
// #include <deque>
// #include <limits.h>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;
int trap(vector<int>& height) {

    int i = 0;
    int ans = 0;
    stack<int> st;
    int n = height.size();
    for(int i = 0; i<n; i++){
        while(!st.empty() && height[st.top()]<height[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()) break;
            int len = i - st.top() - 1;
            ans += (min(height[st.top()],height[i]) - height[cur]*len);
            cout<<"i: "<<i<<endl;
            cout<<"ans: "<<ans<<endl;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
}

// i havve no idea why the code isn't working