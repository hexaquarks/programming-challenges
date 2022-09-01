#include <bits/stdc++.h>
using namespace std;

int find(int par[], int u)
{
    if (par[u] < 0) return u;
    return par[u] = find(par, par[u]);
};

void unite(int par[], int u, int v)
{
    par[u] = v;
};

int computeDiff(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
};

int main() 
{
	int n, temp;
	cin >> n;
	temp = n;
	
	int par[n]; // parent array
	for (int i = 0; i < n; ++i) par[i] = -1;
	
	vector<pair<int, int>> mem;
	int ans = 0;
	while (temp--)
	{
	    int x, y;
	    cin >> x >> y;
	    mem.push_back({x ,y});
	}
	
	vector<pair<int, pair<int, int>>> adj;
	
	for (int i = 0; i < n; ++i)
	{
	    for (int j = i + 1; j < n; ++j)
	    {
	        pair<int, int> curr = mem[i];
	        pair<int, int> next = mem[j];
	        int weight = 2 * computeDiff(curr.first, curr.second, next.first, next.second);
	    
	        adj.push_back({weight, {i, j}});
	    }
	}
	sort(adj.begin(), adj.end());
	
	for (int i = 0; i < adj.size(); ++i)
	{
	    int u = find(par, adj[i].second.first);
	    int v = find(par, adj[i].second.second);
	    
	    if (u != v)
	    {
	        ans += adj[i].first;
	        unite(par, u, v);
	    }
	}
    cout << ans << endl;
	return 0;
}