#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int va,vb,rem,na,nb;
    while(cin >> va)
    {
        cin >> vb;
        cin >> rem;
        
        int k = 0;
        while(1)
        {
            if((rem - k * va) % vb == 0)
            {
                na = k;
                nb = (rem - k * va) / vb;
                break;
            }else if((rem + k * va) % vb == 0)
            {
                na = -k;
                nb = (rem + k * va) / vb;
                break;
            }
            k++;
        }
        
        if(na > 0 && nb < 0)
        {
            int cur_b = 0;
            while(na > 0 && nb < 0)
            {
                printf("fill A\n");
                printf("pour A B\n");
                na--;
                cur_b += va;
                if(cur_b >= vb)
                {
                    printf("empty B\n");
                    printf("pour A B\n");
                    nb++;
                    cur_b -= vb;
                }
            }
        }else if(na < 0 && nb > 0)
        {
            int cur_a = 0;
            while(na < 0 && nb > 0)
            {
                printf("fill B\n");
                printf("pour B A\n");
                nb--;
                cur_a += vb;
                if(cur_a >= va)
                {
                    printf("empty A\n");
                    printf("pour B A\n");
                    na++;
                    cur_a -= va;
                }
            }
            printf("pour A B\n");
        }
        
        if(na == 0 && nb == 0)
        {
            printf("success\n");
        }else if(na == 0)
        {
            printf("fill B\n");
            printf("success\n");
        }else if(nb == 0)
        {
            printf("fill A\n");
            printf("pour A B\n");
            printf("success\n");
        }
    }
}

