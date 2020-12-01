#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

typedef struct Point
{
    double x,y;
}point;

typedef struct edge
{
    int st,en;
    double val;
}edge;

vector<double> ans;

vector<point> readdata()
{
    point temp;
    vector<point> v(n,temp);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&v[i].x,&v[i].y);
    }
    return v;
}

vector<edge> caldis(const vector<point> &v)
{
    vector<edge> adjacent;
    edge temp;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            temp.st = i;
            temp.en = j;
            temp.val = sqrt( (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y));
            adjacent.push_back(temp);
        }
    }
    return adjacent;
}

int comp(const edge &a,const edge &b)
{
    return a.val < b.val;
}



double findmin(const vector<edge> &adjacent,const vector<point> &v)
{
    map<int,int> m;
    for(int i=0;i<n;i++) m[i] = i;
    vector<int> temp(1,0);

    int cnt = n-1,tt;
    double ret = 0;

    for(int i=0;i<adjacent.size();i++)
    {
        if(m[adjacent[i].st] != m[adjacent[i].en])
        {
            ret += adjacent[i].val;
            tt = m[adjacent[i].en];
            for(int j=0;j<m.size();j++)
            {
                if(m[j] == tt) m[j] = m[adjacent[i].st];
            }
            --cnt;
        }
        if(cnt == 0) break;
    }

    return ret;
}

int main()
{
    scanf("%d",&n);
    if(n==0) return 0;
    while(n!=0)
    {
        vector<point> v = readdata();
        vector<edge> adjacent = caldis(v);
        sort(adjacent.begin(),adjacent.end(),comp);
        ans.push_back(findmin(adjacent,v));
        scanf("%d",&n);
    }


    printf("Case #%d:\n",1);
    printf("The minimal distance is: %.2lf\n",ans[0]);
    for(int i=1;i<ans.size();i++)
    {
        printf("\n");
        printf("Case #%d:\n",i+1);
        printf("The minimal distance is: %.2lf\n",ans[i]);


    }
}





