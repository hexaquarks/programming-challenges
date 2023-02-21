class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mem;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            if (mem[curr] < 2) ans.push_back(curr);
            ++mem[curr];
        }
        nums = ans;
        return ans.size();
    }
};