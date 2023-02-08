class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int count = 1;
        int start = 0, end = n;
        while (start != end && start < end) {
            // right
            for (int i = start; i < end; ++i) {
                ans[start][i] = count;
                ++count;
            }
            // down
            for (int j = start + 1; j < end; ++j) {
                ans[j][end - 1] = count;
                ++count;
            }
            // left
            for (int i = end - 2; i >= start; --i) {
                ans[end - 1][i] = count;
                ++count;
            }
            // up
            for (int i = end - 2; i >= start + 1; --i) {
                ans[i][start] = count;
                ++count;
            }
            ++start;
            --end;
        }
        return ans;
    }
};