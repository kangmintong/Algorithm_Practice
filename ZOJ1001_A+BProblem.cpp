#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long int a,b;
    vector<long int> ans;
    while(cin >> a)
    {
        cin >> b;
        ans.push_back(a+b);
        
    }
    for(int i=0;i<ans.size();i++) printf("%ld\n",ans[i]);
}

