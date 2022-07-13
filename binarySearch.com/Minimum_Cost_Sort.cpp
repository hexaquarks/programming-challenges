#include <vector.
#include <algorithm>

/* My solutio - Faster than 92% */
int solve(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) return 0;;

    vector<int> temp = nums;
    std::sort(temp.begin(), temp.end());

    int sumA = 0, sumD = 0;
    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];
        sumA += abs(val - temp[i]);
        sumD += abs(val - temp[n - 1 - i]);
    }
    return min(sumA, sumD);
}
