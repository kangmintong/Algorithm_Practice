#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <string.h>
#include <queue>
using namespace std;
#define N 200
#define mod 998244353
long long dp[N][N];
long long c[N][N];
int main()
{
    for(int i=0;i<N;i++)    //求组合数
        for(int j=0;j<=i;j++) c[i][j]=1;
    for(int i=2;i<N;i++)
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;    //要取模！
    
	int t,n,k,m,same,insame;
	string s1,s2;
	cin >> t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin >> n>>k>>m;
		cin >> s1;
		cin >> s2;
		same=0;
		insame = 0;
		
		for(int i=0;i<n;i++)	if(s1[i]!=s2[i])	++insame;
		
		dp[insame][0]=1;
		
		for(int cnt=1;cnt<=k;cnt++)
		{
			for(int tt=0;tt<=n;tt++)
			{
				for(int p=max(m+tt-n,0);p<=min(m,tt);p++)
				{
					dp[tt+m-2*p][cnt] += ((dp[tt][cnt-1])*c[tt][p])%mod*c[n-tt][m-p]%mod;
					dp[tt+m-2*p][cnt] %= mod;
				}
			}
		}
		printf("%ld\n",dp[0][k]);
	}
}
