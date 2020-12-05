//
//  main.cpp
//  ZOJ 3088 SPFA 最长路
//
//  Created by Mintong Kang on 2020/5/16.
//  Copyright © 2020 Mintong Kang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int t,n,m,k,temp,u,v,dis,mid,ansst;
int ls[2][1010][1010];
int mindist[2][1010],last[2][1010];
double max_ratio=0;
vector<int> st;
void SFPA(int s,int ty);
int main(int argc, const char * argv[]) {
    scanf("%d",&t);
    while(t--)
    {
        memset(ls, INF, sizeof(ls));
        st.clear();
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&dis);
            ls[0][v][u]=-dis;
        }
        bool in[1010];
        memset(in, false, sizeof(in));
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&u,&v,&dis);
            ls[1][u][v]=dis;
            if(!in[u])  st.push_back(u);
            in[u]=true;
        }
        max_ratio=0;
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            mid=INF;
            memset(mindist,INF,sizeof(mindist));
            memset(last,0,sizeof(last));
            u=i;
            SFPA(u,1);
            SFPA(u,0);
//            cout<<u<<endl;
//            for(int i=1;i<=n;i++)
//            {
//                cout<<i<<' '<<mindist[0][i]<<' '<<mindist[1][i]<<endl;
//            }
            for(int j=1;j<=n;j++)
            {
                //cout<<u<<' '<<mindist[0][i]<<' '<<mindist[1][i]<<endl;
                if(mindist[0][j]==INF||mindist[1][j]==INF||mindist[1][j]==0||mindist[0][j]==0 || j==u) continue;
                if(1.0*(-mindist[0][j])/mindist[1][j]>max_ratio)
                {
                    max_ratio=1.0*(-mindist[0][j])/mindist[1][j];
                    mid=j;
                }
            }
            if(mid!=INF)
            {
                ans.clear();
                ans.push_back(mid);
                int tt=mid;
                while(tt!=u)
                {
                    tt=last[1][tt];
                    ans.insert(ans.begin(), tt);
                }
                tt=mid;
                while(tt!=u)
                {
                    tt=last[0][tt];
                    ans.push_back(tt);
                }
            }
        }
        printf("%d ",ans[0]);
        for(int i=1;i<ans.size();i++) printf("%d ",ans[i]);
        printf("\n");
        printf("%.3f\n",max_ratio);
    }
}
void SFPA(int s,int ty)
{
    bool isin[1010];
    memset(isin, false, sizeof(isin));
    queue<int> q;
    int cur;
    q.push(s);
    isin[s]=true;
    mindist[ty][s]=0;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        isin[cur]=false;
        for(int i=1;i<=n;i++)
        {
            if(ls[ty][cur][i]!=INF && mindist[ty][cur]+ls[ty][cur][i]<mindist[ty][i])
            {
                mindist[ty][i]=mindist[ty][cur]+ls[ty][cur][i];
                last[ty][i]=cur;
                if(!isin[i])
                {
                    q.push(i);
                    isin[cur]=true;
                }
            }
        }
    }
}

//1
//4 3 5
//4 1 6
//4 3 1
//3 1 4
//1 2 1
//2 3 3
//1 3 5
//3 4 2
//1 4 10

