#include <vector>

using namespace std;

/* My solution - Better than 50% */
vector<int> solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return {};
    if (n == 1 || n == 2) return nums;

    for (int i = 2; i < n; ++i)
    {
        swap(nums[i], nums[i - 2]);
        if (i % 2 != 0) i += 2;
    }
    return nums;
}
