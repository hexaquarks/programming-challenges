#include <vector>

using namespace std;

/* My solution - Faster than 99% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    std::sort(nums.begin(), nums.end());
    return abs(nums[n / 2] - nums[n / 2 - 1]);
}
