#include <vector>
#include <bits/stdc++.h>

using namespace std;

// My solution - faster than ~25% of submissions, so sort is overkill here?
// bool solve(vector<int>& nums) 
// {
//     int n = nums.size();
//     if (n <= 1) return false;

//     std::sort(nums.begin(), nums.end());
//     int last = nums[n - 1];
//     int sLast = nums[n - 2];
//     if (sLast == 0) return last >= 1;
    
//     return ((last / sLast) >= 2 && last % sLast > 0) || last / sLast > 2;
// }


// Proposed solution, faster than ~80%
bool solve(vector<int>& nums) 
{
    int m = INT_MIN, n = INT_MIN;

    for (int i : nums) 
    {
        if (i > m) 
        {
            n = m;
            m = i;
        } 
        else 
        {
            n = max(n, i);
        }
    }
    return m > 2 * n;
}