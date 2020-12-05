#include <cstdio>
#include <iostream>
using namespace std;

int a[20][20];

int judge(int n,int m)
{
	int flag=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
		{
			if(a[i][j]==0)
			{
				flag=0;
				break;
			}
		}
	if(flag) return 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j+1<m&&a[i][j]==0&&a[i][j+1]==0) return 0;
			else if(i+1<n&&a[i][j]==0&&a[i+1][j]==0) return 0;
		}
	}
	return 1;
}

int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	
	while(m!=0&&n!=0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
	
	
	if(judge(n,m))	printf("Yes\n");
	else printf("No\n");
	scanf("%d%d",&n,&m);
	}
}
