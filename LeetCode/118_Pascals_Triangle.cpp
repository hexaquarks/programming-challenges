class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        else if (numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> ans{{1}, {1, 1}};
        vector<int> curr;
        for (int i = 2; i < numRows; ++i) {
            curr.push_back(1);
            for (int j = 0; j < ans[i - 1].size() - 1; ++j) {
                curr.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }
};