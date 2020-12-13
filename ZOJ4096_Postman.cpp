#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int x,int y)
{
	return x>y;
}

int main()
{
	int t,n,k,temp;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&k);
		vector<int> v1,v2;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp>0) v1.push_back(temp);
			else if(temp<0) v2.push_back(temp);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end(),comp);	
		int p1=k-1,p2=k-1;
		long long ans=0;
		if(v1.size()==0&&v2.size()==0)
		{
			printf("0\n");
			continue;
		}
		if(v2.size()==0||v1.size()>0&&v1[v1.size()-1]>-v2[v2.size()-1])
		{
			ans+=v1[v1.size()-1];
			for(int i=0;i<k&&v1.size()>0;i++) v1.pop_back();
		}
		else if(v1.size()==0||v2.size()>0&&v1[v1.size()-1]<=-v2[v2.size()-1])
		{
			ans+=(-v2[v2.size()-1]);
			for(int i=0;i<k&&v2.size()>0;i++) v2.pop_back();
		}
		
		while(v1.size())
		{
			ans+=2*v1[v1.size()-1];
			for(int i=0;i<k&&v1.size()>0;i++) v1.pop_back();
		}
		while(v2.size())
		{
			ans+=2*(-v2[v2.size()-1]);
			for(int i=0;i<k&&v2.size()>0;i++) v2.pop_back();
		}		
		printf("%lld\n",ans);
	}
}
