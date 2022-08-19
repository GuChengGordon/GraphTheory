// Shortest Path Fast Algorithm
// Bellman-Ford + queue
// time complexity O(mk)
// https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MAXN = 0x3f3f3f3f;

struct node{
	int id, num;
};
vector < node > edges[10005];
queue < int > q;
int n, m, a;
bool vis[10005];
int dist[10005];

void add()
{
	int x, y;
	int z;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		edges[x].push_back({y, z});
	}
	memset(vis, 0, sizeof(vis));
}

void SPFA()
{
	q.push(a);
	memset(dist, 0x3f, sizeof(dist));
	dist[a] = 0;
	vis[a] = 1;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = 0; i < edges[x].size(); i++)
		{
			if (dist[edges[x][i].id] > dist[x] + edges[x][i].num)
			{
				dist[edges[x][i].id] = dist[x] + edges[x][i].num;
				if (!vis[edges[x][i].id])
				{
					q.push(edges[x][i].id);
					vis[edges[x][i].id] = 1;
				}
			}
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
	SPFA();
	system("pause");
	return 0;
}
