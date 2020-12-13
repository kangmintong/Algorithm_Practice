#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
string s[1050];
int v[15][15];
int dp[1050];

int main()
{
	int N, n, temp;

	cin >> N;
	while (N--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
			}
		}

		int K = 1 << n;
		for (int i = 0; i < K; i++)
		{
			dp[i] = 0;
			s[i] = "";
		}

		for (int i = 1; i < K; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					int max = 0;
					for (int k = 0; k < n; k++)
					{
						if (i & (1 << k))
						{
							if (v[k][j] > max)	max = v[k][j];
						}
					}

					char now = 'A' + j;
					if (dp[i - (1 << j)] + max > dp[i] || dp[i - (1 << j)] + max == dp[i] && s[i - (1 << j)] + now <= s[i] || s[i] == "" )
					{
						dp[i] = dp[i - (1 << j)] + max;
						s[i] = s[i - (1 << j)] + now;
					}

				}
			}
		}
		double ans = dp[K - 1] * 1.0 / 100;

		//for (int i = 0; i < K; i++) cout << s[i] << endl;

		printf("%.2f\n", ans);

		cout << s[K - 1] << endl;

	}
}

//1
//10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10
