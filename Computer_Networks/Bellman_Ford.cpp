#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, src;
	cout << endl << "Enter the number of vertices: ";
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n, 0));
	
	cout << "Enter the adjacency matrix: " << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> adj[i][j];
			
	cout << endl << "Enter the source vertex: ";
	cin >> src;
	
	vector<int> dist(n, 1e8);
	dist[src] = 0;
	
	vector<vector<int>> edges;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(adj[i][j] == 0)
				continue;
			edges.push_back({i, j, adj[i][j]});
		}
	}
	
	for(int i = 0; i < n - 1; i++)
	{
		for(vector<int> e: edges)
		{
			int u = e[0];
			int v = e[1];
			int w = e[2];
			
			if (dist[u] != 1e8 && dist[u] + w < dist[v])
				dist[v] = w + dist[u];
		}
	}
	
	for(vector<int> e: edges)
	{
		int u = e[0];
		int v = e[1];
		int w = e[2];
			
		if (dist[u] != 1e8 && dist[u] + w < dist[v])
		{
			cout << "Negative Weight Cycle present in the graph";
			return -1;
		}
	}
	
	cout << endl << "Distance Matrix: ";
	for(int i = 0; i < n; i++)
		cout << dist[i] << " ";
		
	cout << endl;
		
	return 0;
}
