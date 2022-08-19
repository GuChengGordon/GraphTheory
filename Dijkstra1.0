// dijkstra
// https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 10000;
const int MAXN = 0x3f3f3f3f;

struct node
{
	int id, num;
};
int n; // vers' number
int m; // edge's number
int x;
vector < node > edges[N + 5];
int dist[N + 5];
bool vis[N + 5];

void add()
{
	int x, y;
	int z;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		cin >> z;
		edges[x].push_back({y, z});
	}
	memset(vis, 0, sizeof(vis));
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[x] = 0;
	for (int i = 1; i < n; i++)
	{
		int minn = MAXN, p;
		for (int j = 1; j <= n; j++)
		{
			if (dist[j] < minn && !vis[j])
			{
				minn = dist[j];
				p = j;
			}
		}
		vis[p] = 1;
		for (int j = 0; j < edges[p].size(); j++)
			dist[edges[p][j].id] = min(dist[edges[p][j].id], dist[p] + edges[p][j].num);
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
	cin >> n >> m >> x;
	add();
	dijkstra();
	system("pause");
	return 0;
}
