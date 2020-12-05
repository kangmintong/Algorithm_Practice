//zoj 2107 最近点对 循环法
// 分治法 最近点对 zoj2107
#include <bits/stdc++.h>
#define INF 0x1fffffff
using namespace std;
int n;
typedef struct Node
{
	double x,y;
}node;
vector<node*> sx;

bool comp1(node* n1,node* n2)
{
	if(n1->x==n2->x) return n1->y<n2->y;
	else return n1->x<n2->x;
}
bool comp2(node* n1,node* n2)
{
	if(n1->y==n2->y) return n1->x<n2->x;
	else return n1->y<n2->y;
}

double dis(node* n1,node* n2)
{
	return sqrt((n1->x-n2->x)*(n1->x-n2->x) + (n1->y-n2->y)*(n1->y-n2->y));
}

int main()
{
	double tx,ty;
	double res=INF;
	scanf("%d",&n);
	while(n)
	{
		res=INF;
		sx.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&tx,&ty);
			node* tnode=new node;
			tnode->x=tx; tnode->y=ty;
			sx.push_back(tnode);
		}
		sort(sx.begin(),sx.end(),comp1);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(dis(sx[j],sx[i])<res) res=dis(sx[i],sx[j]);
				else break;
			}
		}
		//cout<<"res "<<res<<endl;
		sort(sx.begin(),sx.end(),comp2);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(dis(sx[j],sx[i])<res) res=dis(sx[i],sx[j]);
				else break;
			}
		}
		
		
		printf("%.2f\n",res/2.0);
		scanf("%d",&n);
	}
} 
