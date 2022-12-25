#include <vector>
#include <numeric>

using namespace std;

/* Faster than 80% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (!n) return 0;

    int minVal = *min_element(nums.begin(), nums.end());
    int operations = 0;

    for (const int& val : nums)
    {
        operations += val - minVal;
    }
    return operations;
}