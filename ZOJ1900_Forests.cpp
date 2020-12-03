#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int str_2_int(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
    {
        ret=ret*10+(s[i]-'0');
    }
    return ret;
}
int hear[105][105];
vector<string> split(string s)
{
    vector<string> ret;
    string temp="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' '||s[i]=='\t')
        {
            if(temp!="")
            {
                ret.push_back(temp);
                temp="";
            }
        }
        else
        {
            temp=temp+s[i];
        }
    }
    if(temp!="")
    {
        ret.push_back(temp);
        temp="";
    }
    return ret;
}

int equal(int a,int b,int T)
{
    for(int i=1;i<=T;i++)
    {
        if(hear[a][i]!=hear[b][i]) return 0;
    }
    return 1;
}

int sign[105];

int main()
{
    int P,T,person,tree,total;
    string str;
    char ch;
    while(cin>>P>>T)
    {
        memset(hear,0,sizeof(hear));
        scanf("%c",&ch);
        total=P;
        memset(sign,1,sizeof(sign));
        while(1)
        {
            getline(cin,str);
            if(str.size()==0) break;
            vector<string> v_s=split(str);
            person=str_2_int(v_s[0]);
            tree=str_2_int(v_s[1]);
            hear[person][tree]=1;
        }
        for(int i=1;i<=P-1;i++)
        {
            for(int j=i+1;j<=P;j++)
            {
                if(equal(i,j,T)&&sign[j])
                {
                    sign[j]=0;
                    total--;
                }
            }
        }
        cout<<total<<endl;
    }
}
