
#include <vector>

using namespace std; 

/* Faster than 97% */
int solve(vector<int>& nums) 
{
    if (!nums.size()) return 0;

    int ans  = 0;
    int i = 0, j = nums.size() - 1;
    int maxL = nums[0], maxR = nums[j];

    while (i <= j)
    {
        int l = nums[i], r = nums[j];
        if (l > r)
        {
            if (r > maxR) maxR = r;
            else ans += maxR - r;
            --j;
        }
        else
        {
            if (l > maxL) maxL = l;
            else ans += maxL - l;
            ++i;
        }
    }
    return ans;
}