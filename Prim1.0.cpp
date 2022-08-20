// Prim
// time complexity O(n^2)
// https://www.luogu.com.cn/problem/P1546
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int n;
int arr[105][105];
int minn[105];//minn表示不在树中的点和在树中的点的最小权值
int ans;
bool f[105];

int main()
{
	memset(minn, 0x3f3f3f3f, sizeof(minn));
	minn[1] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		for (int j = 1; j <= n; j++)
			if (!f[j] && minn[j] < minn[p])
				p = j;
		f[p] = true;
		for (int j = 1; j <= n; j++)
			if (!f[j] && arr[p][j] < minn[j])
				minn[j] = arr[p][j];
	}
	for (int i = 1; i <= n; i++)
		ans += minn[i];
	cout << ans << endl;
	system("pause");
	return 0;
}
