#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

map<string,int> m_val;
vector<vector<int> > input;

void read_words()
{
    int m;
    cin >> m;
    string temp;
    string temp2;
    
    while(m--)
    {
        cin >> temp;
        int val;
        cin >> val;
        
        for(string :: iterator it = temp.begin();it != temp.end();it++)
        {
            temp2.push_back(*it);
            m_val[temp2] += val;
        }
        temp2.clear();
    }
}

void read_input()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        vector<int> temp;
        int t;
        char ch;
        while(1)
        {
            cin >> ch;
            t = ch - '0';
            if(t == 1)
            {
                input.push_back(temp);
                break;
            }
            temp.push_back(t);
        }
    }
}

vector<string> info= { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void  construct(vector<string> &vs,int key)
{
    string temp;
    
    if(vs.size() == 0)
    {
        for(string :: iterator it = info[key-2].begin();it != info[key-2].end();it++)
        {
            temp.push_back(*it);
            vs.push_back(temp);
            temp.pop_back();
        }
    }else{
        
        int size = vs.size();
        for(int i=0;i<size;i++)
        {
            temp = vs[i];
            if(m_val.find(vs[i]) == m_val.end() || m_val[vs[i]] == 0)
            {
                //vs.erase(vs.begin() + i);
                continue;
            }
            for(string :: iterator it = info[key-2].begin();it != info[key-2].end();it++)
            {
                temp.push_back(*it);
                if(it == info[key-2].begin())
                {
                    vs[i] = temp;
                }else
                {
                    vs.push_back(temp);
                }
                temp.pop_back();
            }
        }
    }
}

int cnt = 1;
void process()
{
    printf("Scenario #%d:\n",cnt++);
    vector<string> vs;
    for(int i=0;i<input.size();i++)
    {
        string max_str;
        int max = 0;
        vs.clear();
        for(int j=0;j<input[i].size();j++)
        {
            max = 0;
            
            construct(vs,input[i][j]);
            //
            //            for(int q=0;q<vs.size();q++)
            //            {
            //                cout << vs[q];
            //                printf("\n");
            //            }
            //            printf("\n");
            for(int k=0;k<vs.size();k++)
            {
                if(m_val[vs[k]] > max)
                {
                    max = m_val[vs[k]];
                    max_str = vs[k];
                }
            }
            if(max)
            {
                cout << max_str;
                printf("\n");
            }else printf("MANUALLY\n");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int N;
    cin >> N;
    
    while(N--)
    {
        m_val.clear();
        input.clear();
        read_words();
        read_input();
        
        process();
    }
}


