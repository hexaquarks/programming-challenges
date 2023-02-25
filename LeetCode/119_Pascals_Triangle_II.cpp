class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return {1, 1};

        vector<vector<int>> ans{{1}, {1, 1}};
        vector<int> curr;
        for (int i = 2; i < rowIndex + 1; ++i) {
            curr.push_back(1);
            for (int j = 0; j < ans[i - 1].size() - 1; ++j) {
                curr.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            curr.clear();
        }
        return ans[rowIndex];
    }
};