class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back()) return nums[0];
        if (nums.size() == 1) return nums[0];

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[0] <= nums[mid]) l = mid + 1;
            else r = mid - 1;
        }

        return nums[l];
    }
};