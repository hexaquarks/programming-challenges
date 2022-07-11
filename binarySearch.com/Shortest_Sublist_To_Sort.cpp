#include <vector>

using namespace std;

int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    int first = 0, second = n - 1;

    int maxVal = INT_MAX, minVal = INT_MIN;
    int start = 0, end = -1;
    
    while(second >= 0)
    {
        if (nums[first] >= minVal) minVal = nums[first];
        else end = first; 

        if(nums[second] <= maxVal) maxVal = nums[second];
        else start = second;

        ++first;
        --second;
    }
    return end - start + 1;
}
