// Shortest Path Fast Algorithm
// Bellman-Ford + priority_queue
// time complexity O(m log n)
// https://www.luogu.com.cn/problem/P4779
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int MAXN = 0x3f3f3f3f;

int n, m, a;
bool vis[100005];
int dist[100005];
struct node{
	int id, num;
	friend bool operator <(node a, node b)
	{
		return (a.num > b.num);
	}
};
struct cmp{
	bool operator()(int a, int b)
	{
		return dist[a] > dist[b];
	}
};
vector < node > edges[100005];
priority_queue < int, vector < int >, cmp > q;

void add()
{
	int x, y, z;
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
		int x = q.top();
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
