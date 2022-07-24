#include <vector>
#include <algorithm>

using namespace std;

/* My solution - faster tah 70% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (!n) return 0;

    int prev = nums[0];
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i)
    {
        ans = max(ans, abs(nums[i] - nums[i - 1]));
    }
    return ans;
}