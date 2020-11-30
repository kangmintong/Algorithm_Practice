#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<vector<char> > ans;

void find(stack<char> s,string s1,string s2,int p1,int p2,vector<char> temp)
{
    if(p1 == s1.size() && p2 == s2.size())
    {
        ans.push_back(temp);
        return;
    }
    
//    for(int i=0;i<temp.size();i++) printf("%c ",temp[i]);
//    printf("%d %d ",p1,p2);
//    if(!s.empty()) printf("%c %c",s.top(),s2[p2]);
//    printf("\n");
    
    if(p1 < s1.size())
    {
        s.push(s1[p1]);
        p1++;
        temp.push_back('i');
        find(s,s1,s2,p1,p2,temp);
        s.pop();
        p1--;
        temp.pop_back();
    }
    
    
    if(!s.empty() && s.top()==s2[p2])
    {
        char ch = s.top();
        s.pop();
        p2++;
        temp.push_back('o');
        find(s,s1,s2,p1,p2,temp);
        s.push(ch);
        p2--;
        temp.pop_back();
    }
    
}

int main()
{
    string s1,s2;
    while(cin >> s1)
    {
        cin >> s2;
        vector<char> temp;
        if(s1.size() != s2.size())
        {
            temp.push_back('e');
            ans.push_back(temp);
            continue;
        }
        stack<char> s;
        find(s,s1,s2,0,0,temp);
        temp.push_back('e');
        ans.push_back(temp);
    }
    
    printf("[\n");
    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i][0] == 'e')
        {
            printf("]\n");
            printf("[\n");
        }else
        {
            for(int j=0;j<ans[i].size();j++)  printf("%c ",ans[i][j]);
            printf("\n");
        }
    }
    printf("]\n");
}

