
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* My solution - Faster than 90% O(nlogn) though so pretty bad */ 
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return -1;

    std::sort(nums.begin(), nums.end());
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i)
    {
        if (nums[l] > 0) return -1;
        else 
        {
            if (abs(nums[l]) < nums[r]) --r;
            else if (abs(nums[l]) > nums[r]) ++l;
            else return nums[r];
        }
    }
    return -1;
}

/* Better solution - O(n) */
int solve(vector<int>& nums) {
    unordered_set<int> visited;
    int res = -1;
    for (int val : nums) {
        visited.insert(val);
        // check if my negative exists in set...
        if (visited.count(-1 * val)) res = max(res, abs(val));
    }
    return res;
}
