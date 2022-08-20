// Floyd
// time complexity O(n^3)
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int d[1005][1005];
int m, n;
int ans = 2147483647;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	cin >> n >> m;
	memset(d, 0x3f, sizeof(d));
	int x, y, z;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		d[x][y] = min(d[x][y], z);
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(5) << d[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}
