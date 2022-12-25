#include <vector>

using namespace std;

/* My solution - Better than 99.9% of submissions */
int solve(vector<int>& nums) 
{
    int n = nums.size();    
    if (n == 0) return 1;

    int min = 1, sum = 0;;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
        if (sum <= 0) min = max(min, 1 - sum);
    }
    return min;
}

/* Slightly cleaner solution */
int solve(vector<int>& nums) {
    int ans = 0, temp = 0;
    for (int& i : nums) {
        temp += i;
        ans = min(temp, ans);
    }
    return -1 * ans + 1;
}
