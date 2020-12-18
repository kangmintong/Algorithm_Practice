#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int inf=0x3f3f3f3f;
const double PI=acos(-1.0);
const int mod=1e9+7;
string x;
int main()
{
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        cin>>x;
        ll l=x.size();
        ll sum=(1+l)*l/2+1;
        ll a=0,b=0,xx=0,yy=0;
        for(ll i=0; i<l; i++)
        {
            if(x[i]=='0')
                a++;
            if(x[i]=='8')
                b++;
            if(x[i]=='6')
                xx++;
            if(x[i]=='9')
                yy++;
        }
        if(xx==l||yy==l)
        {
            printf("%lld\n",sum-1);
            continue;
        }
        sum-=(1+a)*a/2;
        sum-=(1+b)*b/2;
        sum-=xx*yy;
        printf("%lld\n",sum);
    }
    return 0;
}



