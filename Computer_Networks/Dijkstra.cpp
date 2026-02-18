#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq, vector<int> &d, int &n, vector<vector<int>> &adj)
{
	while(!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int w = top.first;
		int u = top.second;
		for(int v = 0; v < n; v++)
		{
			if ((v == u) || (adj[u][v] == 0))
				continue;
			if ((w + adj[u][v]) > d[v])
				continue;
			d[v] = w + adj[u][v];
			pq.emplace(d[v], v);
		}	
	}
}


int main()
{
	int n; 
	cout << "Enter the number of nodes: ";
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n, 0));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	cout << "Enter the adjacency matrix: " << endl;
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
		}
	}
	
	int src;
	cout << endl << "Enter the source vertex (0 - " << (n - 1) << "): ";
	cin >> src;
	pq.emplace(0, src);
	vector<int> d(n, INT_MAX);
	d[0] = 0;
	dijkstra(src, pq, d, n, adj);
	cout << endl << "Distance Matrix: ";
	for (int dist: d)
		cout << dist << " ";
}
