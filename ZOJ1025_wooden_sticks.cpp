#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct stick
{
    int l,w;
    int valid;
} Stick;
Stick s[5010];

bool cmp(Stick a, Stick b)
{
    if(a.l<b.l) return true;
    if(a.l==b.l&&a.w<b.w) return true;
    return false;
}

int main()
{
    int N,n;
    cin>>N;
    while(N--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&s[i].l,&s[i].w);
            s[i].valid=1;
        }
        sort(s, s+n, cmp);
        
        int sorted=0, ans=0;
        int pre_l=-1, pre_w=-1;
        while(sorted<n)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i].valid==0) continue;
                if(pre_l<0&&pre_w<0)
                {
                    ans++;
                    pre_l=s[i].l;
                    pre_w=s[i].w;
                    sorted++;
                    s[i].valid=0;
                }
                else
                {
                    if(s[i].l>=pre_l&&s[i].w>=pre_w)
                    {
                        sorted++;
                        pre_l=s[i].l;
                        pre_w=s[i].w;
                        s[i].valid=0;
                    }
                }
            }
            pre_l=pre_w=-1;
        }
        printf("%d\n",ans);
    }
}
