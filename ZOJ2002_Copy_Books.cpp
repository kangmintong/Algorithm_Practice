#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL page[510];
LL dp[505][505];
int main()
{
    int N,bks,prs;
    cin>>N;
    while(N--)
    {
        cin>>bks>>prs;
        for(int i=0;i<bks;i++)
        {
            cin>>page[i];
        }
        memset(dp,0x3f3f3f3f3f3f3f3f,sizeof(dp));
        for(int i=1;i<=prs;i++)
        {
            if(i==1)
            {
                LL sum=0;
                for(int j=0;j<bks;j++)
                {
                    sum+=page[j];
                    dp[j][i]=sum;
                }
                continue;
            }
            for(int j=0;j<bks;j++)
            {
                LL sum=page[j];
                for(int k=j-1;k>=i-2;k--)
                {
                    dp[j][i]=min(dp[j][i],max(dp[k][i-1],sum));
                    sum+=page[k];
                }
            }
        }
        LL res=dp[bks-1][prs];
        // cout<<res<<endl;
        
        vector<int> split;
        LL temp=res;
        int total=0;
        if(prs==bks)
        {
            for(int k=bks-2;k>=0;k--) split.push_back(k);
        }
        else
        {
            for(int i=bks-1;i>=0;i--)
            {
            if(temp-page[i]>=0)
            {
                temp-=page[i];
                if(i+1==prs-total)
                {
                    for(int k=i-1;k>=0;k--) split.push_back(k);
                    break;
                }
            }
            else
            {
                split.push_back(i);
                total++;
                temp=res;
                temp-=page[i];
                if(prs-total==i+1)
                {
                for(int k=i-1;k>=0;k--) split.push_back(k);
                break;
                }
            }
            }
        }
        
        

        int pp=split.size()-1;
        for(int i=0;i<bks-1;i++)
        {
            cout<<page[i]<<' ';
            if(pp>=0&&i==split[pp])
            {
                pp--;
                cout<<"/ ";
            }
        }
        cout<<page[bks-1]<<endl;
    }
}
