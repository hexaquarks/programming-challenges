#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
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
    
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        int par[n];
        
        for (int i = 0; i < n; ++i) par[i] = -1;
        
        vector<pair<int, pair<int, int>>> adj;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int weight = computeDiff(points[i][0], points[i][1],
                                         points[j][0], points[j][1]);
                adj.push_back({weight, {i, j}});
            }
        }
        
        sort(adj.begin(), adj.end());
        
        int ans = 0;
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
        return ans;
    };
};