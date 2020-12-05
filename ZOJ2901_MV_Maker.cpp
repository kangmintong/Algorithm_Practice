#include <cstdio>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

#define MAXN 1001000
#define INF -1e18
typedef long long LL;
int a[105][105];
LL dp[40][105][105];
int bin[30];
LL ans[2][105];

int main()
{
	int t,n,l,cnt,temp,st,en;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
				
		l--;
		if(l==0)
		{
		  printf("0\n");
		  continue;
		}
		cnt=0;
		temp=l;
		memset(bin,0,sizeof(bin));
		while(temp)
		{
			bin[cnt++]=temp%2;
			temp/=2;
		}
		
		memset(dp,-2000000000,sizeof(dp));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				dp[0][i][j]=a[i][j];
			}
		
		for(int i=1;i<cnt;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					for(int t=0;t<n;t++)
					{
						if(dp[i-1][j][t]+dp[i-1][t][k]>dp[i][j][k])	dp[i][j][k]=dp[i-1][j][t]+dp[i-1][t][k];
					}
					
				}
			}
		}
		
		vector<int> tt;
		for(int i=0;i<cnt;i++)
		{
			if(bin[i])	tt.push_back(i);
		}
		memset(ans,-2000000000,sizeof(ans));
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n;k++)
			{
				if(dp[tt[0]][k][i]>ans[0][i])	ans[0][i]=dp[tt[0]][k][i];
			}
		}
		for(int j=1;j<tt.size();j++)
		{
			for(int i=0;i<n;i++)
			{
				for(int k=0;k<n;k++)
				{
					if(ans[0][i]+dp[tt[j]][i][k]>ans[1][k])
					{
						ans[1][k]=ans[0][i]+dp[tt[j]][i][k];
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				ans[0][i]=ans[1][i];
				ans[1][i]=-2000000000;
			}
		}
		LL max=INF;
		for(int i=0;i<n;i++)
		{
			if(ans[0][i]>max) max=ans[0][i];
		}
		printf("%lld\n",max);
	}
}
