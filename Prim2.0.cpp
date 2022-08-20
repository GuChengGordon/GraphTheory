// Prim 2.0
// time complexity O(m log n)
// https://www.luogu.com.cn/problem/P1546
#include <bits/stdc++.h>
using namespace std;
#define maxn 105

struct node
{
	int a, b;
	int w;
	bool operator <(const struct node &n)const
	{
		return w > n.w;
	}
};
priority_queue < node > q;
vector < node > G[maxn];
bool vis[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 0) continue;
			else
			{
				G[i].push_back({i, j, tmp});
				G[j].push_back({j, i, tmp});
			}
		}
	vis[1] = true;
	for (int i = 0; i < G[1].size(); i++)
		q.push(G[1][i]);
	int ans = 0;
	int cnt = 0;
	while (cnt < n - 1)
	{
		int w = q.top().w;
		int n = q.top().b;
		q.pop();
		if (vis[n])
			continue;
		vis[n] = true;
		ans += w;
		cnt++;
		for (int i = 0; i < G[n].size(); i++)
		{
			if (!vis[G[n][i].b])
				q.push(G[n][i]);
		}
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}
