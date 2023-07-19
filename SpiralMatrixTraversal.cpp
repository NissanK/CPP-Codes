#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int top = 0;
    int bottom = matrix.size()-1;
    int left = 0;
    int right = matrix[0].size();
    int dir = 0;
    while(top<=bottom && left<=right){
        if(dir==0){
            for(int i = left ;i<=right;i++){
                ans.emplace_back(matrix[top][i]);
            }
            top++;
        }
        else if(dir==1){
            for(int i = top;i<=bottom;i++){
                ans.emplace_back(matrix[i][right]);
            }
            right--;
        }
        else if(dir==2){
            for(int i = right ;i>=left;i--){
                ans.emplace_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if(dir==3){
            for(int i = bottom;i>=top;i--){
                ans.emplace_back(matrix[i][left]);
            }
            left++;
        }
        dir = (dir+1)%4;
    }

    return ans;
}

int main(){

    vector<vector<int>> matrix = {{1,2,3},{5,6,7},{9,10,11}};
    vector<int> ans = spiralOrder(matrix);
    for(auto i:ans){
        cout<<i<<endl;
    }
}


//     B=A.size()-1;
//     L=0;
//     R=A[0].size()-1;
//     dir=0;
//     int i;
//     vector<int> ans;
    
//     while(T<=B && L<=R)
//     {
//         if(dir==0)
//         {
//             for(i=L;i<=R;i++)
//                 ans.push_back(A[T][i]);
//             T++;
//         }
//         else if(dir==1)
//         {
//             for(i=T;i<=B;i++)
//                 ans.push_back(A[i][R]);
//             R--;
//         }
//         else if(dir==2)
//         {
//             for(i=R;i>=L;i--)
//                 ans.push_back(A[B][i]);
//             B--;
//         }
//         else if(dir==3)
//         {
//             for(i=B;i>=T;i--)
//                 ans.push_back(A[i][L]);
//             L++;
//         }
//         dir=(dir+1)%4;
//     }
//     return ans;
// }
