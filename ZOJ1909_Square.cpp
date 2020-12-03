#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int N,m,sum,edge;
vector<int> a;

int dfs(int num,int rem,int pos)
{
    if(num==0) return 1;
    else if (rem==0)
    {
        rem=edge;
        num--;
        return dfs(num,rem,0);
    }
    else
    {
        for(int i=pos;i<m;i++)
        {
            if(a[i]<=rem)
            {
                int temp_ai=a[i];
                a[i]=INF;
                int flag=dfs(num,rem-temp_ai,i);
                a[i]=temp_ai;
                if(flag) return 1;
            }
        }
    }
    return 0;
    
    
}

int main()
{
    cin>>N;
    int temp;
    while(N--)
    {
        cin>>m;
        sum=0;
        a.clear();
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            a.push_back(temp);
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        if(sum%4)
        {
            cout<<"no"<<endl;
        }
        else
        {
            edge=sum/4;
            int flag=dfs(3,edge,0);
            if(flag) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        
    }
}
