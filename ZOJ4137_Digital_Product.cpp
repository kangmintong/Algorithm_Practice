#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

#define mm 1000000007

string s;

int f(int i)
{
    int q;
    char ch;
    while(i)
    {
        q = i % 10;
        if(q == 0) return 0;
        ch = (char)(q+'0');
        i /= 10;
        s.push_back(ch);
    }
    return 1;
}

int cal()
{
    long long ret = 1;
    for(int i=0;i<s.size();i++)
    {
        ret *= (int)(s[i]-'0');
        ret %= mm;
    }
    return (int)ret;
}

int main()
{
    int N,l,r;
    cin >> N;
    
    while(N--)
    {
        cin >> l;
        cin >> r;
        
        int res = 0;
        
        s.clear();
        int k = 1;
        for(int i=l;i<=r;i++)
        {
            k = f(i);
            if(k==0) break;
        }
        if(k == 0)
        {
            printf("0\n");
        }else
        {
            res = cal();
            printf("%d\n",res);
        }
    }
}

