// dijkstra 2.0
// realized with priority_queue
// time complexity O((m+n)log n)
// https://www.luogu.com.cn/problem/P4779
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 100000;
const int MAXN = 0x3f3f3f3f;

struct node
{
	int id, num;
	friend bool operator <(node a, node b)
	{
		return (a.num > b.num);
	}
};
int n, m, x;
vector < node > edges[N + 5];
priority_queue < node > q;
int dist[N + 5];
bool vis[N + 5];

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

void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	q.push({x, 0});
	dist[x] = 0;
	while (q.size())
	{
		node t = q.top();
		q.pop();
		if (vis[t.id])
			continue;
		vis[t.id] = 1;
		for (int i = 0; i < edges[t.id].size(); i++)
		{
			if (dist[edges[t.id][i].id] > dist[t.id] + edges[t.id][i].num)
			{
				dist[edges[t.id][i].id] = dist[t.id] + edges[t.id][i].num;
				q.push({edges[t.id][i].id, dist[edges[t.id][i].id]});
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
	cin >> n >> m >> x;
	add();
	dijkstra();
	system("pause");
	return 0;
}
