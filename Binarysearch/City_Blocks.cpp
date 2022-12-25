#include <vector>
#include <unordered_map>

using namespace std;

/* My solution - Faster than ~70% */
int solve(vector<vector<string>>& matrix, vector<string>& blocks) 
{
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;

    unordered_map<string, pair<int, int>> mem;   

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            mem[matrix[i][j]] = make_pair(i, j);
        }
    }

    int ans = 0, currX = 0, currY = 0;
    for (int i = 0; i < blocks.size(); ++i)
    {
        pair<int, int>& coord = mem[blocks[i]];
        ans += abs(coord.first - currX) + abs(coord.second - currY);
        currX = coord.first;
        currY = coord.second;
    }
    return ans;
}
