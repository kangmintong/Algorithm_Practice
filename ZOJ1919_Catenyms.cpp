#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> start[26];
map<string,int> vis;
vector<string> ans;

int num_st[26];
int num_en[26];
int possible_start;

void check()
{
    int st=-1;
    int st_number=0;
    int en_number=0;
    for(int i=0;i<26;i++)
    {
        if(num_st[i]-num_en[i]==1)
        {
            st=i;
            st_number++;
        }
        else if(num_st[i]==num_en[i])
        {

        }
        else if(num_en[i]-num_st[i]==1)
        {
            en_number++;
        }
        else
        {
            st_number+=1000;
        }
    }
    if(st_number==1&&en_number==1) possible_start=st;
    else if(st_number==0&&en_number==0) possible_start=-2;
    else
    {
        possible_start=-1;
    }
    
}

int dfs(int i,int j,int rem)
{
    if(vis[start[i][j]])    return 0;

    vis[start[i][j]]=1;
    ans.push_back(start[i][j]);
    num_st[start[i][j][0]-'a']--;
    num_en[start[i][j][start[i][j].size()-1]-'a']--;

    if(rem-1==0) return 1;

    int tar=start[i][j][start[i][j].size()-1]-'a';

    check();
    if(possible_start==-1||(possible_start!=-1&&possible_start!=-2&&possible_start!=tar))
    {
        ans.pop_back();
        vis[start[i][j]]=0;
        num_st[start[i][j][0]-'a']++;
        num_en[start[i][j][start[i][j].size()-1]-'a']++;

        return 0;
    }

    for(int q=0;q<start[tar].size();q++)
    {
        if(dfs(tar,q,rem-1)) return 1;
    }

    ans.pop_back();
    vis[start[i][j]]=0;
    num_st[start[i][j][0]-'a']++;
    num_en[start[i][j][start[i][j].size()-1]-'a']++;

    return 0;
}

int main()
{
    int T,n;
    string str;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<26;i++)
        {
            start[i].clear();
        }
        vis.clear();
        ans.clear();
        memset(num_st,0,sizeof(num_st));
        memset(num_en,0,sizeof(num_en));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            start[str[0]-'a'].push_back(str);
            vis[str]=0;
            num_st[str[0]-'a']++;
            num_en[str[str.size()-1]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            sort(start[i].begin(),start[i].end());
            //for(int j=0;j<start[i].size();j++) cout<<start[i][j]<<endl;
        }

        check();
        
        if(possible_start==-1)
        {
            cout<<"***"<<endl;
        }
        else if(possible_start!=-2)
        {
            int flag=0;
            for(int i=possible_start;i<possible_start+1;i++)
            {
                for(int j=0;j<start[i].size();j++)
                {
                    if(dfs(i,j,n))
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                cout<<"***"<<endl;
            }
            else
            {
                cout<<ans[0];
                for(int i=1;i<ans.size();i++)
                {
                    cout<<"."<<ans[i];
                }
                cout<<endl;
            }
        }
        else
        {
            int flag=0;
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<start[i].size();j++)
                {
                    if(dfs(i,j,n))
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                cout<<"***"<<endl;
            }
            else
            {
                cout<<ans[0];
                for(int i=1;i<ans.size();i++)
                {
                    cout<<"."<<ans[i];
                }
                cout<<endl;
            }
        }
        
        
    }
}
