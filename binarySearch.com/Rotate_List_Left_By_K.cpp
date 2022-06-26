#include <vector>
#include <algorithm>

// My implementation 
// vector<int> solve(vector<int>& nums, int k) 
// {
//     int n = nums.size();
//     vector<int> ans(n);
// 
//     for(int i = 0; i < n; ++i)
//     {
//       int newPos = ((i - k) + n) % n;
//       ans[newPos] = nums[i];
//     }
//
//     return ans;
// }

std::vector<int> solve(std::vector<int>& nums, int k) 
{
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.end() - k);
    std::reverse(nums.end() - k, nums.end());

    return nums;
}