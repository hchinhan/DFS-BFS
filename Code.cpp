#include <bits/stdc++.h>

using namespace std;

int m, n, dd[1001][1001] = {}, cld[5] = {0, 1, -1, 0, 0}, clc[5] = {0, 0, 0, 1, -1};


void bfs(int i, int j)
{
	dd[i][j] = 1;
	queue <int> q;
	q.push(i);
	q.push(j);
	while (q.empty() != 1)
	{
		int u = q.front();
		q.pop();
		int v = q.front();
		q.pop();
		for (int k = 1; k <= 4; k++)
		{
			int I = u + clc[k]; int J = v + cld[k];
			if (dd[I][J] == 0)
			{
				dd[I][J] = dd[u][v] + 1;
				q.push(I);
				q.push(J);
			}
		}
	}
}

void dfs (int i, int j, int a)
{
	dd[i][j] = dd[i][j] + a;
	for (int k = 1; k <= 4; k++)
		{
			int I = i + clc[k]; int J = j + cld[k];
			if (dd[I][J] == 0)
			{
				dfs(I, J, a + 1);
			}
		}
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("biggest_area.inp", "r", stdin);
	cin >> m >> n;
	for (int i = 0; i <= m + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			dd[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int u;
			cin >> u;
			if (u == 0)
			{
				dd[i][j] = -1;
			}
			else
			{
				dd[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dd[i][j] == 0)
			{
				dfs(i, j, 1);
			}
		}
	}
	
	int d = dd[1][1];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d = max(d, dd[i][j]);
		}
	}
	cout << d;
}
