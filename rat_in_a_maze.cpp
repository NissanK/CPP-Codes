#include<iostream>

using namespace std;

bool isSafe(int** arr,int x, int y, int n,int m){
    if (x<n && y<m && arr[x][y]==1)
    {
        return true;
    }
    return false;
}
bool ratinMaze(int** arr, int x,int y, int n ,int m, int** solArr){
    if(x==(n-1) && y==(m-1)){
        solArr[x][y]=1;
        return true;
    }
    if (isSafe(arr,x,y,n,m))
    {
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1,y,n,m,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,m,solArr)){
            return true;
        }
    
        solArr[x][y]=0;
        return false;
    }
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;

    int** arr= new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[m];
    }

    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    int** solArr= new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i]= new int[m];
        for (int j = 0; j < m; j++){
            solArr[i][j]=0;
        }
    }
    cout<<endl;
    if(ratinMaze(arr,0,0,n,m,solArr)){
        for (int i = 0; i < n; i++)
        {
            for(int j= 0;j<m;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 0
// 0 1 0 1 0
// 1 1 1 1 0
// 1 1 0 0 0
// 1 1 1 1 1