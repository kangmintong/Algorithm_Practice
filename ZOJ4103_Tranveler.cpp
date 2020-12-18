#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,int> m;

int st[50];
int en[50];

void create()
{
	st[1]=1;
	en[1]=1;
	st[2]=2;
	en[2]=3;
	for(int i=3;i<33;i++)
	{
		st[i] = st[i-2]*2+2;
	}
	for(int i=3;i<33-1;i++)
	{
		en[i] = st[i+1] - 1;
		for(int j=st[i-1];j<=en[i-1];j++)
		{
			m[j+1] = st[i]; 
		}
	//	printf("%d %d\n",st[i],en[i]);
	}
	m[1] = 1;
	m[2] = 2;
}

int main()
{
	int t,n;
	cin >> t;
	create();
	//printf("%d",m[5000]);
	while(t--)
	{
		cin >> n;
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		vector<int> ans;
		int M=n,k=n/2,t=m[k];
		ans.push_back(M);
		ans.push_back(t);
		while(k>1)
		{
			M = t;
			t = k-1;
			ans.push_back(t);
			k = M / 2;
		}
		
		
		vector<int> Ans;
		for(int i=ans.size()-1;i>=0;i--)	Ans.push_back(ans[i]);
		printf("1");
		for(int i=1;i<Ans.size();i++)
		{
			for(int j=Ans[i];j>Ans[i-1];j--)	printf(" %d",j);
		}
		printf("\n");
	}
}
