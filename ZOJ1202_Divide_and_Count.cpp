#include <iostream>
#include <cstdlib>

typedef long long LL;
using namespace std;

LL C[150][150];
LL fac[15];
LL record[15];
LL nums[15];

void GetC()
{
    for(int i=0;i<150;i++)
    {
        C[i][0]=1;
    }
    for(int i=1;i<150;i++)
    {
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

void GetFac()
{
    fac[0]=1;
    for(int i=1;i<15;i++)
    {
        fac[i]=fac[i-1]*i;
    }
}



int main()
{
    GetC();
    GetFac();
    LL ans=1,N,temp,total=0;
    while(cin>>N)
    {
        ans=1;
        total=0;
        for(int i=0;i<15;i++) record[i]=0;
        for(int i=0;i<N;i++)
        {
            cin>>nums[i];
            record[nums[i]]++;
            total+=nums[i];
        }
        for(int i=0;i<N;i++)
        {
            ans*=C[total][nums[i]];
            total-=nums[i];
        }
        for(int i=0;i<15;i++)
        {
            ans/=fac[record[i]];
        }
        cout<<ans<<endl;
    }

}

