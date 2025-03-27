#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void)
{
	int n, cnt;
	cnt = 0;
	cin >> n;
	set<int> m;
	int sum;
	for (int i = 0; i * 6 <= n; i++)
	{
		for (int j = 0; (i * 6) + (j * 9) <= n; j++)
		{
			for (int k = 0; (i * 6) + (j * 9) + (k * 20) <= n; k++)
			{
				sum = (i * 6) + (j * 9) + (k * 20);
				if (sum != 0) m.insert(sum);
			}
		}
	}
	if (m.size() == 0) {
		cout << "no\n";
	}
	else
	{
		for (int i : m)
		{
			cout << i << "\n";
		}
	}
	return 0;
}
