#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
int n,m,u,v,d;
int a[20][20];
int mindis[20][20];
int degree[20];
int ANS;
int is_cover[20];
vector<int> odd;

void cal_min_per_node(int s)
{
    int dis_s[n+1],is_in_q[n+1];
    for(int i=1;i<=n;i++)
    {
        dis_s[i]=INF;
        is_in_q[i]=0;
    }
    dis_s[s]=0;
    is_in_q[s]=1;
    queue<int> q;
    q.push(s);
    
    while(!q.empty())
    {
        int tmp=q.front();
        for(int i=1;i<=n;i++)
        {
            if(dis_s[tmp]+a[tmp][i]<dis_s[i])
            {
                dis_s[i]=dis_s[tmp]+a[tmp][i];
                if(is_in_q[i]==0)
                {
                    q.push(i);
                    is_in_q[i]=1;
                }
            }
        }
        q.pop();
        is_in_q[tmp]=0;
    }
    for(int i=1;i<=n;i++)
    {
        mindis[s][i]=dis_s[i];
    }
}

void cal_min_dist()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    mindis[i][j]=0;
    
    for(int i=1;i<=n;i++)
    cal_min_per_node(i);
}

void dfs_ans(int k,int cur_dist)
{
    if(k==0)
    {
        if(cur_dist<ANS) ANS=cur_dist;
    }
    else
    {
        //vector<int> tmp_v=odd;
        int s1=odd.back(),s2;
        odd.pop_back();
        for(int i=odd.size()-1;i>=0;i--)
        {
            s2=odd[i];
            odd.erase(odd.begin()+i);
            dfs_ans(k-2, cur_dist+mindis[s1][s2]);
            odd.insert(odd.begin()+i, s2);
        }
        odd.push_back(s1);
        
    }
}

int min(int a,int b)
{
    if(a<b) return a;
    return b;
}

int sum_edge;
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&m);
        
        for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++)
        {
            a[i][j]=INF;
        }
        for(int i=1;i<n+1;i++)
        {
            degree[i]=0;
        }
        
        sum_edge=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&d);
            a[u][v]=a[v][u]=min(a[u][v],d);
            degree[u]+=1;
            degree[v]+=1;
            sum_edge+=d;
        }
        
        cal_min_dist();
        
        
        odd.clear();
        for(int i=1;i<=n;i++)
        {
            if(degree[i]%2==1) odd.push_back(i);
        }
        
        ANS=INF;
        for(int i=1;i<=n;i++) is_cover[i]=0;
        dfs_ans(odd.size(),0);
        printf("%d\n",ANS+sum_edge);
        
    }
}

