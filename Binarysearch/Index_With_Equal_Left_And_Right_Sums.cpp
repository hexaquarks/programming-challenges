#include <vector>
#include <numeric> 

int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    int firstSum = std::accumulate(nums.begin(), nums.end(), 0);
    int secondSum = 0;

    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];

        firstSum -= val;
        if (secondSum == firstSum) return i; 
        secondSum += val;
    }
    return -1;
}
