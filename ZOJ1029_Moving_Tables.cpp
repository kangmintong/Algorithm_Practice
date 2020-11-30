#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<vector<int> > &v,int k)
{
    for(int i=k+1;i<200;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j] == -1) continue;
            int t = v[i][j];
            v[i][j] = -1;
            return t;
        }
    }
    return -2;
}

int main()
{
    int N,n,st,en,ans;
    vector<int> temp;
    vector<vector<int> > v;
    cin >> N;
    while(N--)
    {
        v.clear();
        for(int i=0;i<200;i++) v.push_back(temp);
        cin >> n;
        while(n--)
        {
            cin >> st >> en;
            st = (st + 1) / 2;
            en = (en + 1) / 2;
            if(st == en) continue;
            if(st > en)
            {
                int tt = st;
                st = en;
                en = tt;
            }
            v[st].push_back(en);
        }
        
        ans = 0;
        
        for(int i=0;i<200;i++) sort(v[i].begin(),v[i].end());
        
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j] == -1) continue;
                ans += 10;
                int p = v[i][j];
                v[i][j] = -1;
                while(1)
                {
                    p = find(v,p);
                    if(p == -2) break;
                }
            }
        }
        cout << ans << '\n';
    }
}

// 1-20 20-200 20-30

