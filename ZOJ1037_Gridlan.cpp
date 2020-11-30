#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  int N,m,n;
  int casenum = 1;
  double ans;
  cin >> N;
  while(N--)
  {
    cin >> m >> n;
    cout << "Scenario #" << casenum++ <<":\n";
    
    if(m*n % 2) ans = m * n + sqrt(2) - 1;
    else ans = m * n;
    
    printf("%.2f\n\n",ans);
  }
}
