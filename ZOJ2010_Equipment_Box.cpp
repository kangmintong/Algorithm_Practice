#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int a,b,x,y;
#define PI 3.1415926
#define margin 0

int judge()
{
    int tmp;
    if(a>b)
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    if(x>y)
    {
        tmp=x;
        x=y;
        y=tmp;
    }
    
    if(a>=x&&b>=y) return 1;
    if(a==x&&b<y) return 0;
    if(b==y&&a<x) return 0;
    
    for(double i=0;i<=90;i+=0.1)
    {
        double theta=i*PI/180.0;
        double length1=x*sin(theta)+y*cos(theta);
        double length2=x*cos(theta)+y*sin(theta);
        if(length1<=a&&length2<=b) return 1;
    }
    
    return 0;
    
//    double theta1_1st=asin(1.0*a/sqrt(1.0*(x*x+y*y)))-atan(1.0*y/x);
//    double theta2_1st=PI-asin(1.0*a/sqrt(1.0*(x*x+y*y)))-atan(1.0*y/x);
//    double theta1_2nd=asin(1.0*b/sqrt(1.0*(x*x+y*y)))-atan(1.0*y/x);
//    double theta2_2nd=PI-asin(1.0*b/sqrt(1.0*(x*x+y*y)))-atan(1.0*y/x);
//
//    double theta_1st,theta_2nd;
//    int flag1=0,flag2=0;
//    if(0-margin<=theta1_1st&&theta1_1st<=PI/2+margin) theta_1st=theta1_1st;
//    else if(0-margin<=theta2_1st&&theta2_1st<=PI/2+margin) theta_1st=theta2_1st;
//    else flag1=1;
//    if(0-margin<=theta1_2nd&&theta1_2nd<=PI/2+margin) theta_2nd=theta1_2nd;
//    else if(0-margin<=theta2_2nd&&theta2_2nd<=PI/2+margin) theta_2nd=theta2_2nd;
//    else flag2=1;
//
//    double length1=1.0*x*cos(theta_1st)+1.0*y*sin(theta_1st);
//    double length2=1.0*x*cos(theta_2nd)+1.0*y*sin(theta_2nd);
//
//    //if(flag1&&flag2) return 0;
//    cout<<theta_1st<<' '<<theta_2nd<<' '<<length1<<' '<<length2<<endl;
//    if(flag1==0&&flag2==0)
//    {
//        if(length1<=y+margin||length2<=x+margin) return 1;
//        else return 0;
//    }
//    else if(flag1==0)
//    {
//        if(length1<=y+margin) return 1;
//        else return 0;
//    }
//    else if(flag2==0)
//    {
//        if(length2<=x+margin) return 1;
//        else return 0;
//    }
//    else return 0;
}

int main()
{
    
    int N;
    cin>>N;
    while(N--)
    {
        cin>>a>>b>>x>>y;
        if(judge()) cout<<"Escape is possible."<<endl;
        else cout<<"Box cannot be dropped."<<endl;
    }
}
