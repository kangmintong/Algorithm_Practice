//LCD DP ZOJ1733

#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000
int dp[MAXN][MAXN];

int find(char ch,string& s,int j)
{
	for(int i=j;i>=0;i--)
		if(s[i]==ch) return i;
	return -1;
}

int main()
{
	string s1,s2;
	int m,n,k;
	while(cin>>s1)
	{
		cin>>s2;
		memset(dp,0,sizeof(dp));
		m=s1.size(); n=s2.size();
		
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=dp[i-1][j];
				k=find(s1[i-1],s2,j-1);
				if(k>=0&&dp[i-1][k]+1>dp[i][j]) dp[i][j]=dp[i-1][k]+1;
				//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i-1][j]<<' '<<dp[i][j]<<endl;
			}
		}
		printf("%d\n",dp[m][n]);
	}
}

//aaaaaaaaaaaaaaaaccccc
//csssssssssssssssss
