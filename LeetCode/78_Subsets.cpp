class Solution {
public:
    void backtrack(
        vector<int>& nums, 
        vector<vector<int>>& ans,
        int idx, 
        vector<int>& curr
    ) {
        ans.push_back(curr);
        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtrack(nums, ans, i + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(nums, ans, 0, curr);
        return ans;
    }