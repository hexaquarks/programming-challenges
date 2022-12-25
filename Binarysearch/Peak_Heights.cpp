#include <vector>
#include <limits>
#include <tuple>
#include <queue>
using namespace std;

/* Accepted solution - Faster than 70% */
vector<vector<int>> solve(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    if (!n) return {{}};
    int m = matrix[0].size();
    if (!m) return {{}};

    queue<pair<int,int>> q;
    int dx[4]{-1, 0, 1, 0};
    int dy[4]{0, -1, 0, 1};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0) q.emplace(i,j);
            else matrix[i][j] = numeric_limits<int>::max();
        }
    }

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > 1 + matrix[x][y])
            {
                matrix[nx][ny] = 1 + matrix[x][y];
                q.emplace(nx, ny);
            }
        }
    }
    return matrix;
}