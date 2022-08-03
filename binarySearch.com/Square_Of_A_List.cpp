#include <vector>

using namespace std;

vector<int> solve(vector<int>& nums) 
{
    int n = nums.size();
    if (!n) return {};

    vector<int> ans;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        while (i <= j)
        {
            int a = nums[i] * nums[i], b = nums[j] * nums[j];
            ans.push_back(a < b ? b : a);
            if (a < b) --j; 
            else ++i;
        }
        reverse(ans.begin(), ans.end());
    }
    return ans;
}
