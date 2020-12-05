#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 110
typedef int M[MAXN][MAXN];

struct person
{
    char name[25],fav[MAXN][25];
    int nfav;
    int ori;
};

person P[MAXN];
int n,baker[MAXN],matrix[MAXN][MAXN],O[MAXN][MAXN],cse,t,res;

void copy(M x,M y)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[i][j]=y[i][j];
        }
    }
    return ;
}

void mu(M x,M y)
{
    int i,j,k,t;
    M c;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t=0;
            for(k=0;k<n;k++)
            {
                if(x[i][k] && y[k][j])
                {
                    t=(t+x[i][k]*y[k][j])%2;
                }
            }
            c[i][j]=t;
        }
    }
    copy(x,c);
    return ;
}

void Cal(M a,int k)
{
    if(k==1)
    {
        copy(a,O);
        return ;
    }
    Cal(a,k/2);
    mu(a,a);
    if(k & 1)
    {
        mu(a,O);
    }
}

int main()
{
    int i,j,k;
    scanf("%d",&cse);
    while(cse--)
    {
        scanf("%d %d",&n,&t);
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%s",P[i].name);
            scanf("%d %d",&P[i].ori,&P[i].nfav);
            baker[i]=P[i].ori%2;
            for(j=0;j<P[i].nfav;j++)
            {
                getchar();
                scanf("%s",&P[i].fav[j]);
            }
        }
        memset(O,0,sizeof(O));
        for(i=0;i<n;i++)
        {
            O[i][i]=1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<P[i].nfav;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(strcmp(P[i].fav[j],P[k].name)==0)
                    {
                        break;
                    }
                }
                O[i][k]=(O[i][k]+1)%2;
            }
        }        
        Cal(matrix,t-1);     
        res=0;
        for(i=0;i<n;i++)
        {
            int tmp=0 ;
            for(j=0;j<n;j++)
            {
                tmp=(tmp+baker[j]*matrix[j][i])%2;
            }
            if(tmp)res++;              
        }           
        printf("%d\n",res);
    }
    return 0;
}
