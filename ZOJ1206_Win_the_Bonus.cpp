

#include <stdio.h>
#include <string.h>
#define MIN -99999999

int opt[10001][10][10];///用于DP的数组

int cost[1000];///存放数字串及相应的分数

///玩家的数字串的长度
int n;

void DP()
{
    int i, j, k, p;
    int temp;
    ///只有一个或者两个字符的时候 值为零
    for (k=1; k<=2; k++)
        for (i=0; i<10; i++)
            for (j=0; j<10; j++)
                opt[k][i][j] = 0;
    ///递归计算3到n个字符的分值
    for (k=3; k<=n; k++)
        for (i=0; i<10; i++)
            for (j=0; j<10; j++)
            {
                ///长度为k个字符的时候 计算由ijp构成的数字串最大分值
                opt[k][i][j] = MIN;
                for(p = 0; p < 10; p++)
                {
                    temp = opt[k-1][j][p] + cost[i*100+j*10+p];
                    if (opt[k][i][j] < temp)
                        opt[k][i][j] = temp;
                }
            }
}

void print()
{
    int i, j, k, p;
    int m = MIN;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(m < opt[n][i][j])
            {
                m = opt[n][i][j];
                k = i;
                p = j;
            }
    for(i=n; i>=3; i--)
        for(j=0; j<10; j++)
            if(opt[i-1][p][j] + cost[k*100+p*10+j] == m)
            {
                m -= cost[k*100+p*10+j];
                printf("%d", k);
                k = p;
                p = j;
                break;
            }
    printf("%d%d\n", k, p);
}

int main()
{
    int i;
    
    /*
     *银行职员的人数
     */
    int m;
    
    ///每个银行职员的数字串和分数
    int banker, point;
    
    while(scanf("%d%d", &m, &n) != EOF)
    {
        ///cost数组全部刷为0
        memset(cost, 0, sizeof(cost));
        
        ///存储m个职员的奖励或者惩罚的情况
        for(i = 0; i < m; i ++)
        {
            scanf("%d%d", &banker, &point);
            cost[banker] = point;
        }
        DP();
        ///当玩家的数字串长度为1或者2时 输出0或者00
        if(n == 1) printf ("0\n");
        else if(n == 2) printf ("00\n");
        else print();
    }
    return 0;
}

