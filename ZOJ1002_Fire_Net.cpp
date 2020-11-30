#include <cstdio>
#include <vector>
using namespace std;

int Max = 0;
int n;

int can(int mi,int mj,vector<vector<int> > grid)
{
    if(grid[mi][mj] < 2) return 0;
    int flag = 1;
    for(int j=mj+1;j<n;j++)
    {
        if(grid[mi][j] == -1) break;
        if(grid[mi][j] == 1)
        {
            flag = 0;
            break;
        }
    }
    
    for(int j=mj-1;j>=0;j--)
    {
        if(grid[mi][j] == -1) break;
        if(grid[mi][j] == 1)
        {
            flag = 0;
            break;
        }
    }
    
    for(int i=mi-1;i>=0;i--)
    {
        if(grid[i][mj] == -1) break;
        if(grid[i][mj] == 1)
        {
            flag = 0;
            break;
        }
    }
    
    for(int i=mi+1;i<n;i++)
    {
        if(grid[i][mj] == -1) break;
        if(grid[i][mj] == 1)
        {
            flag = 0;
            break;
        }
    }
    
    return flag;
}

void find(int mi, int mj, int cur,vector<vector<int> > grid);

void findnext(int mi,int mj,int cur,vector<vector<int> > grid)
{
    if(mj < n-1) find(mi,mj+1,cur,grid);
    else if(mi < n-1) find(mi+1,0,cur,grid);
    else
    {
        if(cur > Max) Max = cur;
    }
}

void print(vector<vector<int> > grid)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

void find(int mi, int mj, int cur,vector<vector<int> > grid)
{
    
    //print(grid);
    
    if(grid[mi][mj] < 2)
    {
        findnext(mi,mj,cur,grid);
        return;
    }
    
    if(can(mi,mj,grid))
    {
        grid[mi][mj] = 1;
        cur++;
        findnext(mi,mj,cur,grid);
        cur--;
        grid[mi][mj] = 0;
        findnext(mi,mj,cur,grid);
    }else
    {
        grid[mi][mj] = 0;
        findnext(mi,mj,cur,grid);
    }
    
}

int main()
{
    vector<int> ans;
    while(1)
    {
        vector<vector<int> > grid;
        vector<int> temp(4,0);
        for(int i=0;i<4;i++) grid.push_back(temp);
        scanf("%d",&n);
        if(n == 0) break;
        
        Max = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch;
                scanf("%c",&ch);
                if(ch == '\n')  scanf("%c",&ch);
                if(ch == '.') grid[i][j] = 2;
                else if(ch == 'X') grid[i][j] = -1;
            }
        }
        
        find(0,0,0,grid);
        ans.push_back(Max);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        printf("%d\n",ans[i]);
    }
    
}

