#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int grid[20][20];
bool vis[20][20][16384];
struct snake
{
    int x[9];
    int y[9];
    int head,step;
}que[100000];

int nxt[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int main()
{
    int m,n,l,stones;
    cin >> m >> n >> l;
    int cnt=1;
    while(m)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j] = 0;
            }
        }
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                for(int k=0;k<16384;k++)
                {
                    vis[i][j][k] = false;
                }
            }
        }
        
        for(int i=0;i<l;i++)
        {
            scanf("%d %d",&que[0].x[i],&que[0].y[i]);
            que[0].x[i]--;
            que[0].y[i]--;
        }
        cin >> stones;
        for(int i=0;i<stones;i++)
        {
            int x,y;
            cin >> x >> y;
            grid[x-1][y-1] = 1;
        }
        
        que[0].step = 0;
        que[0].head = 0;
        int top = 0;
        int bottom = 1;
        
        while(top != bottom)
        {
            if(!que[top].x[que[top].head] && !que[top].y[que[top].head])
            {
                printf("Case %d: %d\n",cnt++,que[top].step);
                break;
            }
            for(int i=0;i<4;i++)
            {
                int x = que[top].x[que[top].head] + nxt[i][0];
                int y = que[top].y[que[top].head] + nxt[i][1];
                // cout << x << ' ' << y << '\n';
                if(x>=0 && x<m && y>=0 && y<n && !grid[x][y])
                {
                    int flag = 1,path = 0;
                    for(int i=0;i<l;i++)
                    {
                        if(x == que[top].x[i] && y == que[top].y[i])
                        {
                            flag = 0;
                        }
                        
                    }
                    
                    if(flag)
                    {
                        que[bottom] = que[top];
                        que[bottom].step++;
                        que[bottom].head--;
                        if(que[bottom].head==-1) que[bottom].head=l-1;
                        que[bottom].x[que[bottom].head] = x;
                        que[bottom].y[que[bottom].head] = y;
                        
                        // int path = 0;
                        // int cc = 1;
                        
                        // for(int i=que[bottom].head;cc < l;i++)
                        // {
                        //     cc++;
                        //     if(i==l) i = 0;
                        //     int tempx1 = que[bottom].x[i];
                        //     int tempy1 = que[bottom].y[i];
                        //     int tempx2 = que[bottom].x[(i+1)%l];
                        //     int tempy2 = que[bottom].x[(i+1)%l];
                        //     if(tempx1 - tempx2 == 1) path = path * 4 + 0;
                        //     else  if(tempx1 - tempx2 == -1) path = path * 4 + 1;
                        //     else  if(tempy1 - tempy2 == 1) path = path * 4 + 2;
                        //     else  if(tempy1 - tempy2 == -1) path = path * 4 + 3;
                        
                        
                        // }
                        
                        int temp=0;
                        
                        int lx=x;
                        int ly=y;
                        
                        int tl=0;
                        
                        for(int j=que[top].head;tl<l;j++)
                        {
                            if(j==l) j=0;
                            
                            
                            if(tl<l-1)//计算状态
                            {
                                int valx=lx-que[top].x[j];
                                int valy=ly-que[top].y[j];
                                
                                if(valx==0 && valy==1) temp=temp<<2;
                                else if(valx==1 && valy==0) temp=temp<<2|1;
                                else if(valx==-1 && valy==0) temp=temp<<2|2;
                                else if(valx==0 && valy==-1) temp=temp<<2|3;
                                
                                lx=que[top].x[j];
                                ly=que[top].y[j];
                            }
                            
                            tl++;
                        }
                        
                        path = temp;
                        if(vis[x][y][path])
                        {
                            flag = 0;
                        }
                        vis[que[bottom].x[que[bottom].head]][que[bottom].y[que[bottom].head]][path] = true;
                        if(flag) bottom = (bottom+1)%100000;
                    }
                }
            }
            
            //cout << "top" << top << "bottom" << bottom << '\n';
            top = (top+1)%100000;
        }
        if(top == bottom) printf("Case %d: -1\n",cnt++);
        cin >> m >> n >> l;
    }
}

