#include <bits/stdc++.h>

using namespace std;

int m, n, a, b, x, y, dd[1001][1001] = {}, cld[5] = {0, -1, 1, 0, 0}, clc[5] = {0, 0, 0, 1, -1};
struct data 
{
	int I, J;
};
data tr[1001][1001];

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
				tr[I][J].I = u;
				tr[I][J].J = v;
				q.push(I);
				q.push(J);
			}
		}
	}
} 

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("BFS.inp", "r", stdin);
	//freopen("bfs.out", "w", stdout);
	cin >> m >> n >> a >> b >> x >> y;
	for (int i = 0; i <= m + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			dd[i][j] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char u;
			cin >> u;
			if (u == '1')
			{
				dd[i][j] = -1;
			}
			else
			{
				dd[i][j] = 0;
			}
		}
	}
	bfs(a, b);
	tr[a][b].I = tr[a][b].J = -1;
	if (dd[x][y] == 0)
	{
		cout << -1;
		exit(0);
	}
	
	vector <data> c;
	while (x != -1)
	{
		c.push_back({x, y});
		x = tr[x][y].I;
		y = tr[x][y].J;
	}
	
	for (int i = c.size() - 1; i >= 0; i--)
	{
		cout << c[i].I << " " << c[i].J;
		cout << '\n';
	}
}
