#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                int maxRow = *max_element(grid[i].begin(), grid[i].end());
                int maxColumn = grid[0][j]; 
                for (int k = 1; k < grid.size(); ++k) { 
                    maxColumn = max(maxColumn, grid[k][j]);
                }
                ans += min(maxRow, maxColumn) - grid[i][j];
            }
        }
        return ans;
    }
};