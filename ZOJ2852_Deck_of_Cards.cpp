//ZOJ 2852 dp
#include <bits/stdc++.h>
using namespace std;
#define N 35
int dp[105][N][N][N];
int main()
{
	int n,k;
	char ch;
	vector<int> seq;
	scanf("%d",&n);
	while(n)
	{
		seq.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%c",&ch);
			while(ch==' '||ch=='\n') scanf("%c",&ch);
			if(ch=='A') seq.push_back(1);
			else if(ch>='2'&&ch<='9') seq.push_back(ch-'0');
			else if(ch=='T') seq.push_back(10);
			else if(ch=='J'||ch=='Q'||ch=='K') seq.push_back(10);
			else if(ch=='F') seq.push_back(21);
		}
		memset(dp,0,sizeof(dp));
		if(seq[0]==21)
		{
			dp[0][0][0][0]=350;
		}
		else
		{
			dp[0][seq[0]][0][0]=50;
			dp[0][0][seq[0]][0]=50;
			dp[0][0][0][seq[0]]=50;
		}
		
		for(int i=0;i<seq.size()-1;i++)
		{
			for(int j1=0;j1<N;j1++)
			{
				for(int j2=0;j2<N;j2++)
				{
					for(int j3=0;j3<N;j3++)
					{
						k=seq[i+1];
						if(dp[i][j1][j2][j3])
						{
							if(k+j1==21||k==21&&j1<21)
								dp[i+1][0][j2][j3]=max(dp[i+1][0][j2][j3],dp[i][j1][j2][j3]+150);
							else if(j1<21)
								dp[i+1][j1+k][j2][j3]=max(dp[i+1][j1+k][j2][j3],dp[i][j1][j2][j3]+50);
							//cout<<i+1<<' '<<j1+k<<' '<<j2<<' '<<j3<<' '<<dp[i+1][j1+k][j2][j3]<<endl;
							
							if(k+j2==21||k==21&&j2<21)
								dp[i+1][j1][0][j3]=max(dp[i+1][j1][0][j3],dp[i][j1][j2][j3]+250);
							else if(j2<21)
								dp[i+1][j1][j2+k][j3]=max(dp[i+1][j1][j2+k][j3],dp[i][j1][j2][j3]+50);
							//cout<<i+1<<' '<<j1<<' '<<j2+k<<' '<<j3<<' '<<dp[i+1][j1][j2+k][j3]<<endl;
								
							if(k+j3==21||k==21&&j3<21)
								dp[i+1][j1][j2][0]=max(dp[i+1][j1][j2][0],dp[i][j1][j2][j3]+350);
							else if(j3<21)
								dp[i+1][j1][j2][j3+k]=max(dp[i+1][j1][j2][j3+k],dp[i][j1][j2][j3]+50);
							//cout<<i+1<<' '<<j1<<' '<<j2<<' '<<j3+k<<' '<<dp[i+1][j1][j2][j3+k]<<endl;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<seq.size();i++)
			for(int j1=0;j1<N;j1++)
				for(int j2=0;j2<N;j2++)
					for(int j3=0;j3<N;j3++)
						if(dp[i][j1][j2][j3]>ans) ans=dp[i][j1][j2][j3];
		
		
		printf("%d\n",ans);
		scanf("%d",&n);
	}
} 
