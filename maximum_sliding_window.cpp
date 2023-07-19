#include <iostream>
#include <deque>
#include <set>
#include <vector>

using namespace std;

//method 1 time complexity O(nlogn)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0;i<k;i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*(--s.end()));
        for(int i = k;i<nums.size();i++){
            s.erase(s.lower_bound(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(*(--s.end()));
        }
        return ans;
    }
};


//method 2 time complexity O(n)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> ans;
    deque<int> q;
    for(int i = 0;i<k;i++){
        while(!q.empty() and nums[q.back()] < nums[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    for(int i = k; i<nums.size();i++){
        if(q.front() == i-k){
            q.pop_front();
        }
        while(!q.empty() and nums[q.back()] < nums[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    
}
// https://leetcode.com/problems/sliding-window-maximum/submissions/