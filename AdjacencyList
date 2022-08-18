//Adjacency List
//realized with vector
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 100;

/*
struct node{
	int id, int num;
};
*/
int m; // vers' number
int n; // edge's number
vector < int > edges[N + 5]; // vector < node > edges[N + 5];

void add()
{
	int x, y;
	// int z;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		// cin >> z;
		edges[x].push_back(y); // edges[x].push_back({y, z});
		// edges[y].push_back(x); || edges[y].push_back({x, z});
	}
}

void output()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < edges[i].size(); j++)
			cout << edges[i][j];
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
