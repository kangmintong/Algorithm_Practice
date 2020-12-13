#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define maxn 100010
using namespace std;
bool is_prime[10000010];
void init()
{
    memset(is_prime,0,sizeof(is_prime));
    int m=sqrt(10000010);
    for(int i=2; i<=m; i++)
        if(!is_prime[i])
            for(int j=i*i; j<10000010; j+=i)
                is_prime[j]=1;
    is_prime[1]=1;
}
int num[maxn<<2];
int sum[maxn<<2];
int a[maxn+5];
void pushdown(int site,int len)                 //懒人思想的重要函数
{
    if(num[site]!=0)
    {
//        printf("****\n");
//        printf("ssss = %d num = %d\n",site,num[site]);
        if(!is_prime[num[site]])
        {
            sum[site<<1]=(len-len/2);
            sum[site<<1|1]=len>>1;
        }
        else
            sum[site<<1]=sum[site<<1|1]=0;
        num[site<<1]=num[site<<1|1]=num[site];
        num[site]=0;
    }
}
void pushup(int site)
{
    sum[site]=sum[site<<1]+sum[site<<1|1];
   // printf("site = %d num = %d\n",site,sum[site]);
}
void add(int site,int L,int R,int l,int val)
{
    if(L==R&&L==l)
    {
        num[site]+=val;
       // printf("site = %d num = %d\n",site,num[site]);
        if(!is_prime[num[site]])
            sum[site]=1;
        else
            sum[site]=0;
       // printf("site = %d num = %d\n",site,sum[site]);
        return ;
    }
    pushdown(site,R-L+1);
    int mid=(L+R)>>1;
    if(l<=mid)
        add(site<<1,L,mid,l,val);
    else
        add(site<<1|1,mid+1,R,l,val);
    pushup(site);
}
void Replace(int site,int L,int R,int l,int r,int val)
{
    if(R==r&&L==l)
    {
        if(!is_prime[val])
            sum[site]=r-l+1;
        else
            sum[site]=0;
        num[site]=val;
        //printf("site = %d num = %d prime = %d\n",site,num[site],sum[site]);
        return ;
    }
    pushdown(site,R-L+1);
    int mid=(L+R)>>1;
    if(r<=mid)
        Replace(site<<1,L,mid,l,r,val);
    else if(l>mid)
        Replace(site<<1|1,mid+1,R,l,r,val);
    else
    {
        Replace(site<<1,L,mid,l,mid,val);
        Replace(site<<1|1,mid+1,R,mid+1,r,val);
    }
    pushup(site);
}
int Query(int site,int L,int R,int l,int r)
{
    if(L==l&&R==r)
    {
        return sum[site];
    }
    pushdown(site,R-L+1);
    int mid=(L+R)>>1;
    if(r<=mid)
        return   Query(site<<1,L,mid,l,r);
    else if(l>mid)
        return  Query(site<<1|1,mid+1,R,l,r);
    else
        return  Query(site<<1,L,mid,l,mid)+Query(site<<1|1,mid+1,R,mid+1,r);
}
int main()
{
    int t,n,m;
    init();
    scanf("%d",&t);
    while(t--)
    {
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            add(1,1,n,i,a[i]);
        }
        char st[5];
        int l,r,x;
        while(m--)
        {
            scanf("%s",st);
            if(st[0]=='A')
            {
                scanf("%d %d",&x,&l);
                add(1,1,n,l,x);
            }
            else if(st[0]=='R')
            {
                scanf("%d %d %d",&x,&l,&r);
                Replace(1,1,n,l,r,x);
            }
            else if(st[0]=='Q')
            {
                scanf("%d %d",&l,&r);
                printf("%d\n",Query(1,1,n,l,r));
            }
        }
    }
    return 0;
}
