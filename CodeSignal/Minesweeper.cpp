#include <bits/stdc++.h>
using namespace std;

int counter(vector<vector<bool>>& m, vector<vector<int>>& ans, int x, int y)
{
    int count = 0;
    for (int i = x - 1; i <= x + 1; ++i)
    {
        for (int j = y - 1; j <= y + 1; ++j)
        {
            if (i < 0 || j < 0 || i >= ans.size() || j >= ans[0].size()) continue;
            if (m[i][j]) ++count;
        }    
    }
    return count;
}

vector<vector<int>> solution(vector<vector<bool>> matrix) 
{
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            ans[i][j] = counter(matrix, ans, i, j) - (matrix[i][j] ? 1 : 0);
        }
    }
    return ans;
}
