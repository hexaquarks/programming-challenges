#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int getIndex(const string& s, const vector<string>& v)
{
    auto it = find(v.begin(), v.end(), s);
    if (it != v.end()) return it - v.begin();
    else {assert(true); return -1;}
}

bool dfs(
    const vector<vector<int>>& adj, 
    vector<int>& color, 
    const int u, 
    const int c)
{   
    color[u] = c;
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            color[v] = 1 - c;
            if (!dfs(adj, color, v, 1 - c)) return false;
        }
        else if (color[v] == c) return false;
    }
    return true;
}

int main()
{
    IOS;
    int n, m;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) cin >> names[i];
    
    vector<vector<int>> adj(n, vector<int>());
    
    cin >> m;
    while (m--)
    {
        string a, b;
        cin >> a >> b;
        int ia = getIndex(a, names), ib = getIndex(b, names); 
        adj[ia].push_back(ib);
        adj[ib].push_back(ia);
    }
    
    vector<int> color(n);
    for (int i=0; i < n; ++i) color[i] = -1;
    
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            if (!dfs(adj, color, i, 0))
            {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == 0) cout << names[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        if (color[i]) cout << names[i] << " ";
    }
    return 0;
}