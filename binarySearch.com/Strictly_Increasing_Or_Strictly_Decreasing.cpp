#include <vector>

using namespace std;

bool solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0 || n == 1) return true;

    int first = nums[0], second = nums[1];
    if (second - first == 0) return false;

    bool increasing = second > first;
    for (int i = 2; i < n; ++i)
    {
        if (increasing && nums[i] <= second || 
            !increasing && nums[i] >= second) return false;
        second = nums[i];
    } 
    return true;  
}
