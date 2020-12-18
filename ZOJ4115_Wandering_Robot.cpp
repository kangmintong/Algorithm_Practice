#include <cstdio>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct node
{
	long long x;
	long long y;
}Node;

Node arr[100010];

int main()
{
	long long N, n, k, tempx, tempy, tt1, tt2, tt;
	long long dx, dy, max;
	char ch;
	scanf("%ld", &N);
	while (N--)
	{
		max = 0;
		scanf("%ld%ld", &n, &k);
		scanf("%c", &ch);
		tempx = tempy = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%c", &ch);
			if (ch == 'L')	tempx -= 1;
			else if (ch == 'R') tempx += 1;
			else if (ch == 'U')	tempy += 1;
			else if (ch == 'D') tempy -= 1;
			arr[i].x = tempx;
			arr[i].y = tempy;
			//cout << tempx << "  sa  " << tempy << endl;
		}
		dx = arr[n - 1].x;
		dy = arr[n - 1].y;
		//cout << dx << ' ' << dy << "sa" << endl;

		for (int i = 0; i < n; i++)
		{
			tt1 = abs(arr[i].x) + abs(arr[i].y);
			tt2 = abs(arr[i].x + (k - 1) * dx) + abs(arr[i].y + (k - 1) * dy);
			tt = tt1 > tt2 ? tt1 : tt2;
			if (tt > max) max = tt;
		}
		printf("%ld\n", max);
	}
	return 0;
}
