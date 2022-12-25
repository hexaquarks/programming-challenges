#include <vector>
#include <algorithm> 

using namespace std;

/* My solution - Faster than 85% */
vector<vector<int>> solve(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    if (n == 0) return {};
    int m = matrix[0].size();
    if (m == 0) return {};

    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans[j][i] = matrix[i][j];
        }
    }   

    for (int i = 0; i < m; ++i)
    {
        std::sort(ans[i].begin(), ans[i].end());
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = ans[j][i];
        }
    }
    return matrix;  
}
