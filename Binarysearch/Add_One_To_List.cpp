#include <vector>

using namespace std;

/* My solution  - Better than 90% */
vector<int> solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return {};

    int i = n - 1;
    
    while (nums[i] + 1 == 10 && i >= 0)
    {
        nums[i] = 0;
        if (i == 0) 
        {
            nums[i] = 1;
            nums.push_back(0);
            return nums;
        }
        --i;
    }
 
    ++nums[i];
    return nums;
}

/* More compact solution */
vector<int> solve(vector<int>& nums) {
    int pre = 1;
    for (int i = nums.size() - 1; i > -1; i--) {
        nums[i] += pre;
        pre = (nums[i] > 9) ? 1 : 0;
        nums[i] %= 10;
    }
    if (pre) nums.insert(nums.begin(), 1);
    return nums;
}
