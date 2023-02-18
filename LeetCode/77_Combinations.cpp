class Solution {
public:
    void backtrack(
        vector<vector<int>>& ans, 
        vector<int>& curr,
        int n, 
        int idx,
        int k
    ) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            curr.push_back(i);
            backtrack(ans, curr, n, i + 1, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, n, 1, k);
        return ans;
    }
};