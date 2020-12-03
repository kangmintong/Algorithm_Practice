#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int x1,x2,x3,x4,x5,x6;
    scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
    
    while(x1||x2||x3||x4||x5||x6)
    {
        int ans = 0;
        ans += x6;
        
        ans += x5;
        x1 -= 11 * x5;
        
        ans += x4;
        x2 -= 5 * x4;
        if(x2<0) x1 -= (-x2)*4;
        
        ans += x3 / 4;
        x3 = x3 % 4;
        
        if(x2 <= 0)
        {
            if(x1 <= 0)
            {
                if(x3 > 0)  ans += 1;
            }else if(x1 > 0)
            {
                ans += (9 * x3 + x1 - 1) / 36 + 1;
            }
        }else if(x2 > 0)
        {
            ans += x2 / 9;
            x2 = x2 % 9;
            
            if( x3==3 && x2>1)
            {
                ans += 2;
                x1 -= 36 * 2 - 27 - 4 * x2;
            }else if(x3==3 && x2<=1)
            {
                ans += 1;
                x1 -= 36 - 27 - 4 * x2;
            }else if(x3==2 && x2<=3)
            {
                ans += 1;
                x1 -= 18 - x2 * 4;
            }else if(x3==2 && x2>3)
            {
                ans += 2;
                x1 -= 72 - 18 - x2 * 4;
            }else if(x3==1 && x2>5)
            {
                ans += 2;
                x1 -= 72 - 9 - x2 * 4;
            }else if(x3==1 && x2<=5)
            {
                ans += 1;
                x1 -= 36 - 9 - x2 * 4;
            }else if(x3 == 0 && x2>0)
            {
                ans += 1;
                x1 -= 36 - x2 * 4;
            }
            
            if(x1 > 0)  ans += (x1 - 1)/36 + 1;
        }
        
        printf("%d\n",ans);
        scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
    }
}

