#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/* My solution - faster than 70% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (!n) return 0;
    sort(nums.begin(), nums.end());
    return max(nums[n-1]*nums[n-2], nums[0]*nums[1]);
}

/* Much faster solution */
int solve(vector<int>& nums) {
    int minval = nums[0], maxval = nums[0], ans = numeric_limits<int>::min();
    for (int i = 1; i < nums.size(); i++) {
        ans = max(ans, max(minval * nums[i], maxval * nums[i]));
        minval = min(minval, nums[i]);
        maxval = max(maxval, nums[i]);
    }
    return ans;
}