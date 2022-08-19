// edges
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct Edges{
	int x, y, z;
}edges[10005];
int n, m;

int main()
{
	cin >> n >> m;
	int x, y, z;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		edges[i].x = x;
		edges[i].y = y;
		edges[i].z = z;
	}
	system("pause");
	return 0;
}
