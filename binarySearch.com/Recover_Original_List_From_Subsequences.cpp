#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

/* My solution - faster than 35 %*/
void dfs(int v, vector<bool>& visited, unordered_map<int, unordered_set<int>>& adj, vector<int>& ans)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u]) dfs(u, visited, adj, ans);
    }
    ans.push_back(v);
}

vector<int> solve(vector<vector<int>>& lists) 
{
    int n = lists.size();
    if (!n) return {};
    int m = lists[0].size();
    if (!m) return {};

    unordered_map<int, unordered_set<int>> adj;
    unordered_set<int> nums;

    // constructing adjency list
    for (int i = 0; i < n; ++i)
    {
        vector<int> l = lists[i];
        if (l.size() <= 1) continue;
        int j = 1;
        while (j < l.size())
        {
            adj[l[j - 1]].insert(l[j]); 
            nums.insert(l[j]);
            nums.insert(l[j - 1]);
            ++j;
        }
    }

    int nn = nums.size();
    vector<bool> visited;
    vector<int> ans;

    visited.assign(nn, false);
    ans.clear();
    
    for (const int& num : nums)
    {
        if (!visited[num]) dfs(num, visited, adj, ans);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


/* Much faster solution */
vector<int> solve(vector<vector<int>>& lists) {
    unordered_map<int, vector<int>> edges;
    unordered_set<int> vertices;
    unordered_map<int, int> numParents;
    for (auto& list : lists) {
        vertices.insert(list[0]);
        for (int i = 1; i < list.size(); i++) {
            vertices.insert(list[i]);
            edges[list[i - 1]].push_back(list[i]);
            numParents[list[i]]++;
        }
    }
    vector<int> ret;
    for (int vertex : vertices) {
        if (numParents[vertex] == 0) {
            ret.push_back(vertex);
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        for (int child : edges[ret[i]]) {
            if (--numParents[child] == 0) {
                ret.push_back(child);
            }
        }
    }
    return ret;
}

