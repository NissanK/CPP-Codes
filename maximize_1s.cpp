#include <iostream>
#include <string>
#include <deque>
#include <limits.h>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

int findZeroes(int arr[], int n, int m) {

    int zerocount = 0;int i = 0;int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if(arr[j]==0){
            zerocount++;
        }
        while(zerocount>m){
            if(arr[i]==0) zerocount--;
            i++;
        }
        ans = max(ans,j-i+1);
    }
    return ans;
}  

int main() {}

// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1