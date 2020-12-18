#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	int N, n, temp;
	vector<int> v;
	cin >> N;
	while (N--)
	{
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		int cnt = 0;
		stack<int> s;
		int last = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && v[i] > s.top())
			{
				last = s.top();
				//cout << "pop " << last << endl;
				s.pop();
				cnt--;
			}
			if (v[i] >= last)
			{
				s.push(v[i]);
				//cout << "push " << v[i] << endl;
				cnt++;
			}
		}
		cout << n - cnt << endl;
	}
}
