#include <vector>
#include <unordered_map>

using namespace std;

/* My solution - faster than 50% */
bool solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return false;

    unordered_map<int, int> mem;
    for (int i = 0; i < n; ++i)
    {
        ++mem[nums[i]];
    }
    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];
        if (mem[val] == val) return true;
    }
    return false; 
}

