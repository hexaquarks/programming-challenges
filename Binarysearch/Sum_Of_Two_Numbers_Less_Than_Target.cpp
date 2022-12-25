#include <vector>
#include <algorithm>
using namespace std;

/* My solution - Faster tha  75% */
int solve(vector<int>& nums, int target) 
{
    int n = nums.size();
    if (n == 0) return 0;

    sort(nums.begin(), nums.end());
    int l = 0, r = n - 1;
    int maxval = std::numeric_limits<int>::min();
    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum < target)
        {
            maxval = max(maxval, sum);
            ++l;
        }
        else --r;
    }
    return maxval;
}

/* Better accepted solution */
int solve(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1];
    assert(ret < target);
    int lhs = 0;
    int rhs = nums.size() - 1;
    while (lhs < rhs) {
        int candSum = nums[lhs] + nums[rhs];
        if (candSum >= target)
            rhs--;
        else {
            ret = max(ret, candSum);
            lhs++;
        }
    }
    return ret;
}
