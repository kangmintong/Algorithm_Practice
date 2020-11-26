#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int a[2][105][105];
int n;

void cal_closure()
{
    for(int p=0;p<2;p++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(a[p][j][i]&&a[p][i][k]) a[p][j][k]=1;
                }
            }
        }
    }
}

vector<int> ret;
void isok()
{
    ret.clear();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        a[0][i][j]+=a[1][i][j];
        if(a[0][i][j]>1) return;
        if(i==j&&a[0][i][j]) return;
    }
    
    for(int i=1;i<=n;i++)
    {
        int sum1=0,sum2=0;
        for(int j=1;j<=n;j++)
        {
            sum1+=a[0][j][i];
            sum1-=a[1][j][i];
            sum2+=a[1][j][i];
        }
        if(sum1<=(n-1)/2 && sum2<=(n-1)/2) ret.push_back(i);
    }
    
}

int main()
{
    int N,m,lar,sma,first=1;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<2;i++)
        for(int j=0;j<n+1;j++)
        for(int k=0;k<n+1;k++)
        a[i][j][k]=0;
        
        for(int p=0;p<m;p++)
        {
            scanf("%d%d",&lar,&sma);
            a[0][lar][sma]=1;
            a[1][sma][lar]=1;
        }
        
        cal_closure();
        
        string ans;
        for(int i=0;i<n;i++) ans.push_back('0');
        isok();
        for(int i=0;i<ret.size();i++) ans[ret[i]-1]='1';
        
        cout<<ans<<endl;
        first=0;
    }
}

