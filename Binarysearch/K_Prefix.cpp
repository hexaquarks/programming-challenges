#include <vector>

using namespace std;

/* Faster than 85% */
int solve(vector<int>& nums, int k) 
{
    int n = nums.size();
    if (n == 0) return -1;

    int last = -1, sum = 0;
    for (int i = 0; i < nums.size(); ++i) 
    {
        sum += nums[i];
        last = sum <= k ? i : last;
    }
    return last;
}
