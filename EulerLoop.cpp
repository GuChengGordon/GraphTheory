// EulerLoop
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct node{
	int u, v;
};
int n, m;
int arr[105][105];
stack < node > s;

void dfs(int u)
{
	int v;
	for (v = 1; v <= n; v++)
	{
		if (arr[u][v])
		{
			arr[u][v]--;
			arr[v][u]--;
			dfs(v);
			s.push({u, v});
		}
	}
}

int main()
{
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		arr[u][v]++;
		arr[v][u]++;
	}
	dfs(1);
	while (s.size())
	{
		cout << s.top().u << "->" << s.top().v << endl;
		s.pop();
	}
	system("pause");
	return 0;
}
