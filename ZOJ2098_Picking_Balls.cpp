#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long C[55][55];
int ori[55];
int out[55];

void cal()
{
    C[1][0]=1;
    C[1][1]=1;
    for(int i=0;i<55;i++) C[i][0]=1;
    for(int i=2;i<=50;i++)
    {
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}

int main()
{
    cal();
    int n,k;

    while(cin>>n>>k)
    {
        if(n==-1&&k==-1) break;

        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ori[i]);
            sum+=ori[i];
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&out[i]);
        }

        double total=C[sum][k];
        double ways=1.0;
        for(int i=0;i<n;i++)
        {
            ways*=C[ori[i]][out[i]];
        }
        double poss=ways/total;
        printf("%.5f\n",poss);

    }
    
}
