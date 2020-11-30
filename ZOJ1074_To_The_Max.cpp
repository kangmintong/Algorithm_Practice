#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = 0;
    int temp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> temp[i][j];
        }
    }
    
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
            {
                a[i][j] = temp[0][0];
            }else if(i == 0)
            {
                a[i][j] = a[i][j-1] + temp[i][j];
            }else if(j == 0)
            {
                a[i][j] = a[i-1][j] + temp[i][j];
            }else a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + temp[i][j];
        }
    }
    
    int cur;
    
    for(int i1=0;i1<n;i1++)
    {
        for(int i2=i1;i2<n;i2++)
        {
            for(int j1=0;j1<n;j1++)
            {
                for(int j2=j1;j2<n;j2++)
                {
                    if(i1 >= 1 && j1 >= 1)  cur = a[i2][j2] - a[i2][j1-1] - a[i1-1][j2] + a[i1-1][j1-1];
                    else if(i1 == 0 && j1 == 0) cur = a[i2][j2];
                    else if(i1 == 0)    cur = a[i2][j2] - a[i2][j1-1];
                    else if(j1 == 0)    cur = a[i2][j2] - a[i1-1][j2];
                    if(cur > max) max = cur;
                }
            }
        }
    }
    
    cout << max;
}

