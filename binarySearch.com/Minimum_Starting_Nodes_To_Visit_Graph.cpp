#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

/* My solution - faster than 60% */
vector<int> solve(vector<vector<int>>& edges) 
{
    set<int> nodesIn;
    unordered_set<int> nodesOut;
    vector<int> ans;
    int n = edges.size();

    for (int i = 0; i < n; ++i)
    {
        nodesIn.insert(edges[i][0]);
        nodesOut.insert(edges[i][1]);
    }

    for (const int& val : nodesIn)
    {
        if (nodesOut.find(val) == nodesOut.end()) ans.push_back(val);
    }
    
    return ans;
}