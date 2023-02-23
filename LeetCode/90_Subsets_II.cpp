class Solution {
public:
    set<vector<int>> mem;
    void backtrack(
        vector<vector<int>>& ans, 
        vector<int>& nums, 
        vector<int>& curr, 
        int i)  
    {
        if (mem.empty() || mem.find(curr) == mem.end()) {
            ans.push_back(curr); 
            mem.insert(curr);
        }

        for (int j = i; j < nums.size(); ++j) {
            curr.push_back(nums[j]);
            backtrack(ans, nums, curr, j + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, curr, 0);
        return ans;
    }
};