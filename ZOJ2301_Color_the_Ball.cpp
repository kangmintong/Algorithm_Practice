#include <iostream>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define N 14007

struct node
{
    int lmax,rmax,maxi,col;
}tree[4*N];
int num[N],x[N];
int L[2005],R[2005];
char ss[2005][3];
map<int,int> mp;

void pushup(int l,int r,int rt)
{
    tree[rt].lmax = tree[2*rt].lmax;
    tree[rt].rmax = tree[2*rt+1].rmax;
    tree[rt].maxi = max(max(tree[2*rt].maxi,tree[2*rt+1].maxi),tree[2*rt].rmax+tree[2*rt+1].lmax);
    int mid = (l+r)/2;
    int L = x[mid]-x[l-1];  //真实的长度
    int R = x[r]-x[mid];
    if(tree[2*rt].lmax == L)
        tree[rt].lmax += tree[2*rt+1].lmax;
    if(tree[2*rt+1].rmax == R)
        tree[rt].rmax += tree[2*rt].rmax;
}

void pushdown(int l,int r,int rt)
{
    if(tree[rt].col != -1)
    {
        tree[2*rt].col = tree[2*rt+1].col = tree[rt].col;
        int mid = (l+r)/2;
        int L = x[mid]-x[l-1];
        int R = x[r]-x[mid];
        tree[2*rt].maxi = tree[2*rt].lmax = tree[2*rt].rmax = L*tree[rt].col;
        tree[2*rt+1].maxi = tree[2*rt+1].lmax = tree[2*rt+1].rmax = R*tree[rt].col;
        tree[rt].col = -1;
    }
}
void build(int l,int r,int rt)
{
    tree[rt].maxi = tree[rt].lmax = tree[rt].rmax = 0;
    tree[rt].col = -1;
    if(l == r) return;
    int mid = (l+r)/2;
    build(l,mid,2*rt);
    build(mid+1,r,2*rt+1);
}

void update(int l,int r,int aa,int bb,int col,int rt)
{
    if(aa <= l && bb >= r)
    {
        tree[rt].col = col;
        tree[rt].maxi = tree[rt].lmax = tree[rt].rmax = col*(x[r]-x[l-1]);
        return;
    }
    pushdown(l,r,rt);
    int mid = (l+r)/2;
    if(aa <= mid)
        update(l,mid,aa,bb,col,2*rt);
    if(bb > mid)
        update(mid+1,r,aa,bb,col,2*rt+1);
    pushup(l,r,rt);
}

int query(int l,int r,int rt)
{
    if(l == r) return x[l];
    int mid = (l+r)/2;
    pushdown(l,r,rt);
    if(tree[2*rt].maxi == tree[1].maxi)   //tree[1]  not  tree[rt]
        return query(l,mid,2*rt);
    else if(tree[2*rt].rmax+tree[2*rt+1].lmax == tree[1].maxi)
        return x[mid]-tree[2*rt].rmax+1;
    else
        return query(mid+1,r,2*rt+1);
}

int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%s",&L[i],&R[i],ss[i]);
            num[6*i-5] = L[i]-1;
            num[6*i-4] = L[i];
            num[6*i-3] = L[i]+1;
            num[6*i-2] = R[i]-1;
            num[6*i-1] = R[i];
            num[6*i] = R[i]+1;
        }
        sort(num+1,num+6*n+1);
        int ind = unique(num+1,num+6*n+1)-num-1;
        int now = 0;
        x[0] = 0;
        for(i=1;i<=ind;i++)
        {
            x[++now] = num[i];
            mp[num[i]] = now;
        }
        build(1,now,1);
        for(i=1;i<=n;i++)
        {
            int ka = mp[L[i]];
            int kb = mp[R[i]];
            if(ss[i][0] == 'w')
                update(1,now,ka,kb,1,1);
            else
                update(1,now,ka,kb,0,1);
        }
        if(tree[1].maxi <= 0)
            puts("Oh, my god");
        else
        {
            int left = query(1,now,1);
            int right = left+tree[1].maxi-1;
            printf("%d %d\n",left,right);
        }
    }
    return 0;
}
