#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
int t,n,m,te,tdays,nd,now;
vector<vector<int> > v;
vector<int> temp;
vector<int> r(11,0);
vector<int> mul(4,0);
vector<int> prime={2,3,5,7};


void add(int x)
{
    if(x==0) return;
    vector<int> tt(4,0);
    for(int i=0;i<4;i++)
    {
        if(x%prime[i]==0)
        {
            x/=prime[i];
            tt[i]++;
            i--;
        }
    }
    for(int i=0;i<4;i++) mul[i]=max(mul[i],tt[i]);
}

int multi()
{
    for(int i=0;i<4;i++) mul[i]=0;
    for(int i=1;i<=10;i++) if(r[i]) add(i);
    int ret=1;
    for(int i=0;i<4;i++) ret*=pow(prime[i],mul[i]);
    return ret;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<r.size();i++)
            r[i]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            r[m]++;
            temp.clear();
            for(int i=0;i<m;i++)
            {
                scanf("%d",&te);
                temp.push_back(te);
            }
            v.push_back(temp);
        }
        tdays=multi();
        //cout<<tdays<<endl;
        nd=0;
        now=0;
        vector<int> min;
        int Min=INF,ans=n,die,last=-1;
        while(1)
        {
            Min=INF;
            min.clear();
            for(int i=0;i<n;i++)
            {
                if(v[i][now%v[i].size()]<Min)
                {
                    Min=v[i][now%v[i].size()];
                    min.clear();
                    min.push_back(i);
                }else if (v[i][now%v[i].size()]==Min)
                {
                    min.push_back(i);
                }
                
            }
            //for(int i=0;i<min.size();i++) cout<<min[i]<<' ';
            //cout<<endl;
            if(min.size()>1)
            {
                nd++;
            }
            else
            {
                die=min[0];
                for(int i=0;i<v[die].size();i++) v[die][i]=INF;
                r[v[die].size()]--;
                nd=0;
                //tdays=multi();
                //cout<<"t "<<tdays<<endl;
                ans--;
                last=now;
            }
            now++;
            if(nd>500) break;
            if(ans==0) break;
        }
        printf("%d %d\n",ans,++last);
    }
}

