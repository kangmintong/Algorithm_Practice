#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void find(const vector<int> &v,vector<int> temp,int sum,int cur,int flag,map<int,int> m,vector<vector<int> > &ans)
{
    if(cur == v.size()) return;
    if(sum > v[v.size()-1]) return;
    
    if(temp.size() > 1 && flag)
    {
        if(m.count(sum))
        {
            temp.push_back(sum);
            ans.push_back(temp);
            temp.pop_back();
        }
    }
    
    find(v,temp,sum,cur+1,0,m,ans);
    
    temp.push_back(v[cur]);
    sum += v[cur];
    find(v,temp,sum,cur+1,1,m,ans);
    
}

int min(int a,int b)
{
    return a<b?a:b;
}

int comp(const vector<int> &a,const vector<int> &b)
{
    if(a.size()<b.size()) return 1;
    else if(a.size()>b.size()) return 0;
    else
    {
        int i = 0;
        while(i<min(a.size(),b.size()) && a[i] == b[i]) ++i;
        return a[i] < b[i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        int M;
        scanf("%d",&M);
        vector<int> v(M,0);
        map<int,int> m;
        
        for(int j=0;j<M;j++)
        {
            scanf("%d",&v[j]);
            m[v[j]] = 1;
        }
        
        sort(v.begin(),v.end());
        
        vector<vector<int> > ans;
        vector<int> temp;
        find(v,temp,0,0,0,m,ans);
        
        sort(ans.begin(),ans.end(),comp);
        
        if(ans.size() == 0) printf("Can't find any equations.\n");
        
        for(int i=0;i<ans.size();i++)
        {
            printf("%d",ans[i][0]);
            for(int j=1;j<ans[i].size()-1;j++)
            {
                printf("+%d",ans[i][j]);
            }
            printf("=%d\n",ans[i][ans[i].size()-1]);
        }
        printf("\n");
    }
}

