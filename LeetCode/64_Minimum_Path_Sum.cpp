class Solution {
public:
    int solve(vector<vector<int>>& grid, int y, int x, int curr, vector<vector<int>>& dp) {
        if (y >= grid.size() || x >= grid[0].size()) return numeric_limits<int>::max();
        curr += grid[y][x];
        if (y == grid.size() - 1 && x == grid[0].size() - 1) return curr;
        if (dp[y][x] != -1) return dp[y][x];

        int down = solve(grid, y + 1, x, 0, dp);
        int right = solve(grid, y, x + 1, 0, dp);

        dp[y][x] = curr + min(down, right);
        return dp[y][x];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, 0, dp);
    }
};