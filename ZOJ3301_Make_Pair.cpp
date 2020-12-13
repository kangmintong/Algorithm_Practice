#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node
{
	int v,no;
}Node;

bool comp(Node* a,Node* b)
{
	return (a->v)<(b->v);
}

int main()
{
	int n,temp,cnt=0;
	while(cin>>n)
	{
		if(cnt++) printf("\n");	
		vector<Node*> v;
		for(int i=0;i<n;i++)
		{
			Node* p=new node;
			scanf("%d",&(p->v));
			p->no=i+1;
			v.push_back(p);
		}
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<n;i+=2)
		{
			printf("%d %d\n",v[i]->no,v[i+1]->no);
		}
	}
}
