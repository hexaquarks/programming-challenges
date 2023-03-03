class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return nums[0];

        int currMin = nums[0];
        int currMax = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(currMin, currMax);

            currMin = min(currMin * nums[i], nums[i]);
            currMax = max(currMax * nums[i], nums[i]);
            ans = max(ans, currMax);
        }

        return ans;
    }
};