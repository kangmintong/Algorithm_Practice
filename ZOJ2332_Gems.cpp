#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=1000;
const int deli=900;
#define INF 1111111111
struct edge
{
	int u,v,cap,flow;
	edge(int a,int b,int c,int d):u(a),v(b),cap(c),flow(d){};
};
vector<int> G[MAXN];
vector<edge*> e;
int a[MAXN];
int p[MAXN];

void init()
{
	for(int i=0;i<MAXN;i++)	G[i].clear();
	e.clear();
}

void addedge(int u,int v,int cap,int flow)
{
	edge* temp1=new edge(u,v,cap,0);
	edge* temp2;
	if(cap!=INF)	temp2=new edge(v,u,0,0);
	else temp2=new edge(v,u,INF,0);
	e.push_back(temp1);
	e.push_back(temp2);
	//if(u==1000&&v==997) cout<<cap<<" asd "<<flow<<endl;
	G[u].push_back(e.size()-2);
	G[v].push_back(e.size()-1);
}

void maxflow(int s,int t,int& mf)
{
	while(1)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		queue<int> q;
		q.push(s);
		a[s]=INF;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			//cout<<"G "<<u<<' '<<G[u].size()<<endl;
			for(int i=0;i<G[u].size();i++)
			{
				edge* te=e[G[u][i]];
				//cout<<te->u<<' '<<te->v<<' '<<te->cap<<' '<<te->flow<<endl;
				if(a[te->v]==0&&te->cap>te->flow)
				{
					p[te->v]=G[u][i];
					a[te->v]=min(a[te->u],te->cap-te->flow);
					q.push(te->v);
					//if(te->v==t) cout<<te->u<<" "<<te->v<<" "<<te->cap<<" "<<te->flow<<endl;
				}
			}
		}
		//cout<<"a[t] "<<a[t]<<endl;
		if(a[t]==0) break;
		
		for(int u=t;u!=s;u=e[p[u]]->u)
		{
			e[p[u]]->flow+=a[t];
			e[p[u]^1]->flow-=a[t];
		}
		mf+=a[t];
	}
}


//ZOJ 2332 GEMS
int main()
{
	int T,n,m,temp,num,a1,b1,a2,b2,sum;
	scanf("%d",&T);
	const int s=deli-2;
	const int t=deli-3;
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		sum=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&temp);
				sum+=temp;
				addedge(s,m*i+j,temp,0);
				addedge(m*i+j,deli+i,INF-1,0);
				addedge(m*i+j,deli+n+j,INF-1,0);
			}
		scanf("%d",&num);
		//cout<<sum<<endl;
		for(int i=0;i<num;i++)
		{
			scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
			addedge(a1*m+b1,a2*m+b2,INF,0);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a1);
			//cout<<"a1 "<<a1<<" "<<deli+i<<" "<<t<<" "<<endl;
			addedge(deli+i,t,a1,0);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a1);
			addedge(deli+n+i,t,a1,0);
		}
		int mf=0;
		maxflow(s,t,mf);
		//cout<<mf<<endl;
		if(mf==sum) printf("Yes\n");
		else printf("No\n");
		
	}
}
