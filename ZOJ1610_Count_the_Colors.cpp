//有点不同 没有回溯 最后只有单点查询 ZOJ 1610
#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 10000

struct node
{
	int l,r,color;	
}tree[MAXN*4+10];
int lazy[MAXN*4+10];
int count[MAXN];
int last;

void push_down(int cur)
{
	if(lazy[cur])
	{
		int LC=cur*2,RC=cur*2+1;
		lazy[LC]=lazy[RC]=lazy[cur];
		lazy[cur]=0;
		tree[LC].color=tree[RC].color=tree[cur].color;
	}	
}

void build(int cur,int L,int R)
{
	tree[cur].l=L;
	tree[cur].r=R;
	tree[cur].color=-1;	
	if(L==R)
	{
		return;
	}
	int mid=(L+R)/2;
	build(cur*2,L,mid);
	build(cur*2+1,mid+1,R);	
} 

void update(int L,int R,int co,int cur)
{
	if(L<=tree[cur].l&&R>=tree[cur].r)
	{
		tree[cur].color=co;
		lazy[cur]=1;
		return;
	}
	push_down(cur);
	int mid=(tree[cur].l+tree[cur].r)/2;
	if(L<=mid)	update(L,R,co,cur*2);
	if(R>mid)	update(L,R,co,cur*2+1);
}

void query(int L,int R, int cur)
{
	if(tree[cur].l==tree[cur].r)
	{
		if(tree[cur].color>=0&&tree[cur].color!=last)	count[tree[cur].color]++;
		last=tree[cur].color;
		return;
	}
	push_down(cur);
	int mid=(L+R)/2;
	query(L,mid,cur*2);
	query(mid+1,R,cur*2+1);
}

int main()
{
	int n,s1,s2,c,first=0;
	while(cin>>n)
	{
		memset(lazy,0,sizeof(lazy));
		build(1,0,MAXN);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&s1,&s2,&c);
			update(s1,s2-1,c,1);
		}
		
		last=-1;
		memset(count,0,sizeof(count));
		query(0,MAXN,1);
		for(int i=0;i<MAXN;i++)
		{
			if(count[i]>0) printf("%d %d\n",i,count[i]);
		}
		printf("\n"); 
		
	}
}
