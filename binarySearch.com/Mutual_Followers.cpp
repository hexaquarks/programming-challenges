#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/* My solution - Faster than 91% */
vector<int> solve(vector<vector<int>>& relations) 
{
    int n = relations.size();
    if (n == 0) return {};

    unordered_map<int, vector<int>> mem;    
    set<int> ans;

    for (int i = 0; i < n; ++i)
    {
        int l = relations[i][0], r = relations[i][1];
        vector<int> temp = mem[r];
        if (find(temp.begin(), temp.end(), l) != temp.end()) 
        { 
            ans.insert(l); 
            ans.insert(r);
        }
        mem[l].push_back(r);
    }
    vector<int> f(ans.begin(), ans.end());
    return f;
}
