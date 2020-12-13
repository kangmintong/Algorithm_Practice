//ZOJ domination
#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
double dp[MAXN][MAXN][MAXN*MAXN];

int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		memset(dp,0,sizeof(dp));
		dp[1][1][1]=1;
		for(int k=2;k<m*n+1;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i-1)	dp[i][j][k]+=dp[i-1][j][k-1]*(m-i+1)*j*1.0/(m*n-k+1);
					if(j-1) dp[i][j][k]+=dp[i][j-1][k-1]*(n-j+1)*i*1.0/(m*n-k+1);
					if(i<m||j<n) dp[i][j][k]+=dp[i][j][k-1]*(i*j-k+1)*1.0/(m*n-k+1);
					if(i-1&&j-1) dp[i][j][k]+=dp[i-1][j-1][k-1]*(m*n-m*(j-1)-n*(i-1)+(i-1)*(j-1))*1.0/(m*n-k+1);
//					cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<' '<<dp[i-1][j][k-1]*(m-i+1)*j*1.0/(m*n-k+1)<<' '
//					<<dp[i][j-1][k-1]*(n-j+1)*i*1.0/(m*n-k+1)<<' '<<dp[i][j][k-1]*(i*j-k+1)*1.0/(m*n-k+1)<<
//					' '<<dp[i-1][j-1][k-1]*(m*n-m*(j-1)-n*(i-1)+(i-1)*(j-1))*1.0/(m*n-k+1)<<endl;
				}
			}
		}
		double ans=0;
		for(int i=0;i<m*n+1;i++) ans+=i*dp[m][n][i];
		//for(int i=0;i<m*n+1;i++) cout<<i<<' '<<dp[m][n][i]<<endl;
		printf("%.12f\n",ans);
	}
}
