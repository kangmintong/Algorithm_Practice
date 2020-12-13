//极大极小+3\8 24点 ZOJ3459

#include <bits/stdc++.h>
using namespace std;
#define eps 1e-18
int num[4];
char color[4];
bool is24[11*11*11*11];
double val[8];
int vis[8];

bool ok[100010];
int s[4];
int id[110];
int a[110];
//bool judge(int dep)
//{
//	if(dep==7) return fabs(val[6]-24.0)<eps;
//	for(int i=0;i<dep;i++)
//		if(!vis[i])
//			for(int j=i+1;j<dep;j++)
//				if(!vis[j])
//				{
//					val[dep]=val[i]+val[j];
//					vis[i]=vis[j]=1;
//					if(judge(dep+1)) return true;
//					val[dep]=val[i]-val[j];
//					if(judge(dep+1)) return true;
//					val[dep]=-val[i]+val[j];
//					if(judge(dep+1)) return true;
//					val[dep]=val[i]*val[j];
//					if(judge(dep+1)) return true;
//					if(val[i]>eps)
//					{
//						val[dep]=val[j]/val[i];
//						if(judge(dep+1)) return true;
//					}
//					if(val[j]>eps)
//					{
//						val[dep]=val[i]/val[j];
//						if(judge(dep+1)) return true;
//					}
//					vis[i]=vis[j]=0;
//				}
//	return false;
//}
//
//void construct()
//{
//	bool temp;
//	for(int i=1;i<=10;i++)
//		for(int j=i;j<=10;j++)
//			for(int k=j;k<=10;k++)
//				for(int w=k;w<=10;w++)
//				{
//					val[0]=i; val[1]=j; val[2]=k; val[3]=w;
//					memset(vis,0,sizeof(vis));
//					temp=judge(4);
//					//cout<<i<<' '<<j<<' '<<k<<' '<<w<<' '<<temp<<endl;
//					for(int l0=0;l0<4;l0++)
//					{
//						for(int l1=0;l1<4;l1++)
//						{
//							if(l1==l0) continue;
//							for(int l2=0;l2<4;l2++)
//							{
//								if(l2==l0||l2==l1) continue;
//								for(int l3=0;l3<4;l3++)
//								{
//									if(l3==l0||l3==l1||l3==l2) continue;
//									is24[(int)(val[l0]*11*11*11+val[l1]*11*11+val[l2]*11+val[l3])]=temp;
//								}
//							}
//						}
//					}
//				}
//} 
int get_id(int a[])
{
    int base=1;
    int tmp=0;
    for(int i=0;i<4;i++)
    {
        tmp+=(a[i]-1)*base;
        base*=10;
    }
    return tmp;
}

bool judge(int dep)
{
    if(dep == 7)
        return fabs(val[6]-24.0) < eps;
    for(int i=0;i<dep;i++)if(!vis[i])
        for(int j=i+1;j<dep;j++)if(!vis[j])
        {
            vis[i]=vis[j]=true;
            val[dep]=val[i]+val[j];
            if(judge(dep+1))
                return true;
            val[dep]=val[i]-val[j];
            if(judge(dep+1))
                return true;
            val[dep]=-val[i]+val[j];
            if(judge(dep+1))
                return true;
            val[dep]=val[i]*val[j];
            if(judge(dep+1))
                return true;
            if(fabs(val[j]) > eps)
            {
                val[dep]=val[i]/val[j];
                if(judge(dep+1))
                    return true;
            }
            if(fabs(val[i]) > eps)
            {
                val[dep]=val[j]/val[i];
                if(judge(dep+1))
                    return true;
            }
            vis[i]=vis[j]=false;
        }
    return false;
}
void init()
{
    for(s[0]=1;s[0]<=10;s[0]++)
        for(s[1]=s[0];s[1]<=10;s[1]++)
            for(s[2]=s[1];s[2]<=10;s[2]++)
                for(s[3]=s[2];s[3]<=10;s[3]++)
                {
                    memset(vis,false,sizeof(vis));
                    for(int i=0;i<4;i++)
                        val[i]=s[i];
                    if(judge(4))
                    {
                        for(int i=0;i<4;i++)
                            id[i]=i;
                        do
                        {
                            for(int i=0;i<4;i++)
                                a[i]=s[id[i]];
                            ok[get_id(a)]=true;
                        }while(next_permutation(id,id+4));
                    }
                }
}

int t,n,m;
int num1[15];
char color1[15];
int ok1[15];
int num2[15];
char color2[15];

bool dfs(int dep)
{
	int temp=get_id(num);
	int tempint;
	char tempch;
	if(dep%2==0)
	{
		if(ok[temp])
		{
			if(dep!=0) return true;
			if(!dfs(dep+1)) return true;
		}
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!ok1[j]) continue;
				tempint=num[i];
				tempch=color[i];
				ok1[j]=0;
				
				bool flag= !dfs(dep+1);
				num[i]=tempint;
				tempch=color1[j];
				color[i]=tempch;
				ok1[j]=1;
				if(flag) return true;
			}
		}
		return false;
	}
	else
	{
		if(!ok[temp]) return true;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(color[j]=='r') continue;
				tempint=num2[j];
				num2[j]=num[i];
				num[i]=tempint;
				tempch=color2[j];
				color2[j]=color[i];
				color[i]=tempch;
				bool flag=!dfs(dep+1);
				tempint=num2[j];
				num2[j]=num[i];
				num[i]=tempint;
				tempch=color2[j];
				color2[j]=color[i];
				color[i]=tempch;
				if(flag) return true;
			}
		}
		return false;
		
	}
}

int main()
{
	memset(ok,false,sizeof(ok));
	init();
	scanf("%d",&t);
	for(int cas=0;cas<t;cas++)
	{
		for(int i=0;i<4;i++)
		{
			scanf("%d",&num[i]);
			scanf("%c",&color[i]);
			while(color[i]==' '||color[i]=='\n') scanf("%c",&color[i]);	
		}
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num1[i]);
			scanf("%c",&color1[i]);
			ok1[i]=1;
			while(color1[i]==' '||color1[i]=='\n') scanf("%c",&color1[i]);	
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&num2[i]);
			scanf("%c",&color2[i]);
			while(color2[i]==' '||color2[i]=='\n') scanf("%c",&color2[i]);	
		}
		
		if(dfs(0)) printf("Sima Yi Wins!\n");
		else printf("Zhang Jiao Wins!\n");
	}
}
