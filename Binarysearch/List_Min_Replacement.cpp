#include<vector>

using namespace std;

/* My solution - Faster than 25% */
vector<int> solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return {};

    int minVal = nums[0];
    vector<int> ans{0};
    for (int i = 1; i < n; ++i)
    {
        ans.push_back(minVal);
        minVal = min(minVal, nums[i]);
    }
    return ans;
}

/* Better Solutin */
std::vector<int> solve(std::vector<int>& nums) {
    int min = std::min(nums[0], nums[1]);
    nums[1] = nums[0];
    nums[0] = 0;
    for (size_t i = 2; i < nums.size(); i++) {
        int left_min = min;
        min = std::min(min, nums[i]);
        nums[i] = left_min;
    }
    return nums;
}
