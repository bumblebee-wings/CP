#include <bits/stdc++.h>

using namespace std;

void dijkstra(unordered_map<int, vector<pair<int, int>>>graph, int s, vector<int>& p, vector<int>& dis, vector<bool>& mark, bool& ispath)
{
	dis[s] = 0;

	for (auto u : graph)
	{
		int un = -1;
		for (auto j : graph)
		{
			if (!mark[j] && un == -1 || d[j] < d[un])
				un = j;
		}

		if (d[un] == INT_MAX)
		{
			ispath = false;
			break;
		}

		for (auto to : graph[un])
		{
			int tov = to->first;
			int tol = to->second;

			if (d[un] + tol < d[tov])
			{
				d[tov] = d[un] + tol;
				p[tov] = un;
			}
		}
	}
}

vector<int> restored_path(int s, int t, vector<int>& const p)
{
	vector<int> path;

	for (int v = t; v != s; v = p[v])
	{
		path.push_back(v);
	}
	path.push_back(s);

	reverse(path.begin(), path.end());
	return path;
}
int main()
{
	int n, m;
	cin >> n >> m;
	unordered_map<int, vector<pair<int, int>>> graph;
	vector<int> p(n, -1);
	vector<bool>mark(n, false);
	vector<int> dis(n, INT_MAX);
	vector<int> path;
	bool ispath = true;
	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(b, w);
		graph[b].push_back(a, w);
	}

	dijkstra(graph, 1, p, dis, mark, ispath);

	path = restored_path(1, n, p);

	if (ispath) 
	{
		for (auto i : path)
		{
			cout << i << " ";
		}
		return;
	}
	else
	{
		return -1;
	}
}