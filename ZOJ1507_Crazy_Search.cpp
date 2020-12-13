#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define MAXN 17000000

map<char,int> m;
bool hashval[MAXN];

int main()
{
    int T,n,nc;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>n>>nc>>s;
        int k=0;
        m.clear();
        for(int i=0;i<MAXN;i++) hashval[i]=false;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end()) m[s[i]]=k++;
        }
        int ans=s.size()-n+1;
        for(int i=0;i<s.size()-n+1;i++)
        {
            int hash_sum=0;
            for(int j=i;j<i+n;j++)
            {
                hash_sum=(hash_sum*k+m[s[j]])%MAXN;
            }
            if(hashval[hash_sum]) ans--;
            else hashval[hash_sum]=true;
        }
        cout<<ans<<endl;
        if(T) cout<<'\n';
    }
}

