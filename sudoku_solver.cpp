#include<bits/stdc++.h>
using namespace std;

bool isSafe(int ** arr, int i ,int j, int no){
    for(int k = 0;k<9;k++){
        if(arr[i][k]==no || arr[k][j]==no){
            return false;
        }
    }

    int sx = (i/3)*3;
    int sy = (j/3)*3;

    for(int x = sx;x<sx+3;x++){
        for(int y = sy;y<sy+3;y++){
            if(arr[i][j]==no){
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver(int ** arr, int i , int j){

    if(i==9){
        return true;
    }

    else if(j==9){
        return SudokuSolver(arr, i+1,0);
    }

    else if(arr[i][j]!=0){
        return SudokuSolver(arr,i,j+1);
    }

    else{
        for(int k = 1; k<=9 ;k++){
            if(isSafe(arr,i ,j,k)){
                arr[i][j]=k;
                if(SudokuSolver(arr,i,j+1)){
                    return true;
                }
                arr[i][j]=0;
            }
        }
    }
    return false;
}


int main(){

    int ** arr = new int*[9];
    for(int i = 0;i<9;i++){
        arr[i] = new int[9];
        for(int j = 0;j<9;j++){
            cin>>arr[i][j];
        }
    }

    cout<<endl;
    if(SudokuSolver(arr,0,0)){
        for(int i = 0;i<9;i++){
            for(int j= 0;j<9;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }
    }

    else{
        cout<<"no solution possible"<<endl;
    }

}


// 0 0 0 2 6 0 7 0 1
// 6 8 0 0 7 0 0 9 0
// 1 9 0 0 0 4 5 0 0
// 8 2 0 1 0 0 0 4 0
// 0 0 4 6 0 2 9 0 0
// 0 5 0 0 0 3 0 2 8
// 0 0 9 3 0 0 0 7 4
// 0 4 0 0 5 0 0 3 6
// 7 0 3 0 1 8 0 0 0

// 0 0 0 2 0 7 1 3 0
// 5 4 0 0 6 0 0 8 0
// 0 1 0 9 0 0 0 5 2
// 9 5 0 0 8 2 0 0 6
// 0 0 6 0 0 0 7 0 0
// 3 0 0 5 9 0 0 4 8
// 8 2 0 0 0 4 0 7 0
// 0 3 0 0 2 0 0 6 9
// 0 6 5 1 0 9 0 0 0
