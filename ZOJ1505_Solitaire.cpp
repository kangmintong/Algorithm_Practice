#include <iostream>
#include <cstdio>
using namespace std;

int a[10][10],b[10][10];
int ANS;

void init()
{
    ANS=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }
    }
}

int cal_diff()
{
    int ret=0;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(a[i][j]&&!b[i][j]) ret++;
        }
    }
    return ret;
}

void dfs(int k)
{
    if(k==0)
    {
        if(cal_diff()==0) ANS=1;
        return;
    }
    if(k<cal_diff()||ANS) return;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(!a[i][j]) continue;
            if(i-1>=1&&a[i-1][j]==0)
            {
                a[i][j]=0;
                a[i-1][j]=1;
                dfs(k-1);
                a[i-1][j]=0;
                a[i][j]=1;
            }
            if(i+1<=8&&a[i+1][j]==0)
            {
                a[i][j]=0;
                a[i+1][j]=1;
                dfs(k-1);
                a[i+1][j]=0;
                a[i][j]=1;
            }
            if(j-1>=1&&a[i][j-1]==0)
            {
                a[i][j]=0;
                a[i][j-1]=1;
                dfs(k-1);
                a[i][j-1]=0;
                a[i][j]=1;
            }
            if(j+1<=8&&a[i][j+1]==0)
            {
                a[i][j]=0;
                a[i][j+1]=1;
                dfs(k-1);
                a[i][j+1]=0;
                a[i][j]=1;
            }
            if(i-2>=1&&a[i-1][j]&&a[i-2][j]==0)
            {
                a[i][j]=0;
                a[i-2][j]=1;
                dfs(k-1);
                a[i-2][j]=0;
                a[i][j]=1;
            }
            if(j-2>=1&&a[i][j-1]&&a[i][j-2]==0)
            {
                a[i][j]=0;
                a[i][j-2]=1;
                dfs(k-1);
                a[i][j-2]=0;
                a[i][j]=1;
            }
            if(i+2<=8&&a[i+1][j]&&a[i+2][j]==0)
            {
                a[i][j]=0;
                a[i+2][j]=1;
                dfs(k-1);
                a[i+2][j]=0;
                a[i][j]=1;
            }
            if(j+2<=8&&a[i][j+1]&&a[i][j+2]==0)
            {
                a[i][j]=0;
                a[i][j+2]=1;
                dfs(k-1);
                a[i][j+2]=0;
                a[i][j]=1;
            }
        }
    }
}

int main()
{
    int x,y;
    while(cin>>x)
    {
        init();
        scanf("%d",&y);
        a[x][y]=1;
        for(int i=0;i<3;i++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        for(int i=0;i<4;i++)
        {
            scanf("%d%d",&x,&y);
            b[x][y]=1;
        }
        
        dfs(8);
        if(ANS) printf("YES\n");
        else printf("NO\n");
        
    }
}

