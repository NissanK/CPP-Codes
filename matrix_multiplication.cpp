#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{

    int n1, n2;
    cin >> n1 >> n2;

    int m1[n1][n2];
    cout << "Enter matrix 1" << endl;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> m1[i][j];
        }
    }

    cout << "Enter the value of n3" << endl;
    int n3;
    cin >> n3;
    cout << "Enter matrix 2" << endl;
    int m2[n2][n3];

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin >> m2[i][j];
        }
    }

    int mx[n1][n3];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                mx[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    
    cout << "Resultant matrix" << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << mx[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
