// Bellman-Ford
// time complexity O(mn)
// https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MAXN = 0x3f3f3f3f;

struct Edges{
	int x, y, z;
}edges[500005];
int n, m, a;
int dist[10005];

void add()
{
	int x, y, z;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		edges[i].x = x;
		edges[i].y = y;
		edges[i].z = z;
	}
}

void BellmanFord()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[a] = 0;
	bool f = true;
	while (f)
	{
		f = false;
		for (int i = 1; i <= m; i++)
			if (dist[edges[i].y] > dist[edges[i].x] + edges[i].z)
			{
				dist[edges[i].y] = dist[edges[i].x] + edges[i].z;
				f = true;
			}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == MAXN)
			cout << "2147483647 ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
}

int main()
{
	cin >> n >> m >> a;
	add();
	BellmanFord();
	system("pause");
	return 0;
}
