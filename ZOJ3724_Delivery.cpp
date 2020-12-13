#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define maxn 100000
#define maxm 200000
#define lowbit(k) k&(-k)
using namespace std;
 
struct Node
{
    int u,v;
    ll d;
    int idx; int kind;
    bool operator < (const Node &b) const{
        if (u == b.u){
            if (v == b.v) return kind < b.kind;
            else return v < b.v;
        }
        else return u > b.u;
    }
}seg[maxm*2];
int top;
ll d[maxn + 50];
ll sd[maxn + 50];
ll ans[maxm + 50];
ll n, m;
 
ll bit[maxn + 50];
 
void upd(int x, ll val){
    while (x <= n){
        bit[x] = min(bit[x], val);
        x += lowbit(x);
    }
}
 
ll query(int x){
    ll res = (1LL) << 60;
    while (x){
        res = min(res, bit[x]);
        x -= lowbit(x);
    }
    return res;
}
 
int main()
{
    while (cin >> n >> m){
        for (int i = 1; i <= n - 1; i++){
            scanf("%lld", &d[i]);
        }
        sd[1] = 0;
        for (int i = 1; i <= n - 1; i++){
            sd[i + 1] = sd[i] + d[i];
        }
        int ui, vi; ll qi; top = 0;
        for (int i = 0; i < m; i++){
            scanf("%d%d%lld", &seg[top].u, &seg[top].v, &seg[top].d);
            seg[top].idx = i; seg[top].kind = 0;
            top++;
        }
        int q; cin >> q;
        for (int i = 0; i < q; i++){
            scanf("%d%d", &seg[top].u, &seg[top].v);
            seg[top].kind = 1; seg[top].idx = i; top++;
        }
        sort(seg, seg + top);
        memset(ans, 0, sizeof(ans));
        memset(bit, 0, sizeof(bit));
        for (int i = 0; i < top; i++){
            if (seg[i].kind == 0 && seg[i].u < seg[i].v){
                upd(seg[i].v, seg[i].d - (sd[seg[i].v] - sd[seg[i].u])); // 节省距离的相反数
            }
            if (seg[i].kind == 1 && seg[i].u < seg[i].v){
                ans[seg[i].idx] = query(seg[i].v) + sd[seg[i].v] - sd[seg[i].u];
            }
        }
        for (int i = 1; i <= n; i++) bit[i] = (1LL << 60);
        for (int i = 0; i < top; i++){
            if (seg[i].kind == 0 && seg[i].u>seg[i].v){
                upd(seg[i].v, seg[i].d + sd[seg[i].u] - sd[seg[i].v]);
            }
            if (seg[i].kind == 1 && seg[i].u>seg[i].v){
                ans[seg[i].idx] = query(seg[i].v) - (sd[seg[i].u] - sd[seg[i].v]);
            }
        }
        for (int i = 0; i < q; i++){
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}
