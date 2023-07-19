#include<bits/stdc++.h>

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1>n2){
        return findMedianSortedArrays(nums2,nums1);
    }

    int low = 0;int high = n1;

    while(low<=high){
        
        int mid1 = (high+low)/2;
        int mid2 = (n1 + n2 + 1)/2 - mid1;

        int left1 = mid1 == 0? INT_MIN : nums1[mid1-1];
        int left2 = mid2 == 0? INT_MIN : nums2[mid2-1];

        int right1 = mid1 == n1 ? INT_MAX : nums1[mid1];
        int right2 = mid2 == n2 ? INT_MAX : nums2[mid2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2) & 1){
                return max(left1,left2);
            }
            else{
                return (max(left1,left2) + min(right1,right2))/2.0;
            }
        }

        else if(left1>right2){
            high = mid1-1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0.0;
}

int main(){

}