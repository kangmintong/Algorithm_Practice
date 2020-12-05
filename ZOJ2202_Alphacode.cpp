#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s;
int n;
int dp[10000000];

int valid(char a,char b)
{
    if(a=='0') return 0;
    int res=10*(a-'0')+(b-'0');
    //cout<<res<<endl;
    if(res<=26) return 1;
    return 0;
}

int main()
{
    while(cin>>s)
    {
        if(s[0]=='0') break;
        n=s.size();
        for(int i=0;i<n;i++) dp[i]=0;
        dp[0]=1;
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(valid(s[0],s[1])&&s[1]!='0') dp[1]=2;
        else if(!valid(s[0],s[1])&&s[1]=='0')
        {
            printf("0\n");
            continue;
        }
        else dp[1]=1;
        
        int flag=1;
        for(int i=2;i<n;i++)
        {
            if(valid(s[i-1],s[i]))
            {
                if(s[i]=='0') dp[i]=dp[i-2];
                else dp[i]=dp[i-2]+dp[i-1];
            }
            else
            {
                if(s[i]!='0') dp[i]=dp[i-1];
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        
        if(flag) printf("%d\n",dp[n-1]);
        else printf("0\n");
    }
}
