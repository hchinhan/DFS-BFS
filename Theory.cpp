#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, dd[1000001] = {}, tr[100001] = {};
vector <int> dt[100001]; 

void dfs(int i)
{
	for (int j = 0; j < dt[i].size(); j++)
	{
		int u = dt[i][j];
		if (tr[u] == 0)
		{
			tr[u] = i;
			dfs(u);
		}
	}
}

int main ()
{
	freopen("dfs.inp", "r", stdin);
	cin >> n >> m;
	cin >> a >> b;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		dt[u].push_back(v);
	}
	tr[a] = -1;
	dfs(a);
	vector <int> c;
	while (b != -1)
	{
		c.push_back(b);
		b = tr[b];
	}
	//sort(a, a + n)
	reverse(c.begin(), c.end());
	for (int i = 0; i <= c.size() - 1; i++)
	{
		cout << c[i] << " ";
	}
}
