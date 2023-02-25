class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> lastRow = triangle[triangle.size() - 1];

        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                lastRow[j] = triangle[i][j] + min(lastRow[j], lastRow[j + 1]);
            }
        }
        return lastRow[0];
    }
};