// Adjacency Matrix
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 100;

int m; // vers' number
int n; // edge's number
int edges[N + 5][N + 5];

void add()
{
	int x, y;
	// int z;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		// cin >> z;
		edges[x][y] = 1; // edges[x][y] = z;
		// edges[y][x] = 1; || edges[y][x] = z;
	}
}

void output()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(5) << edges[i][j];
		cout << endl;
	}
}

int main()
{
	cin >> m >> n;
	add();
	output();
	system("pause");
	return 0;
}
