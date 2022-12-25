#include <vector>
#include <unordered_map>

using namespace std;

/* My solution - Faster than 85% */
bool solve(vector<int>& nums, int k) 
{
    int n = nums.size(); 
    if (n == 0) return false;

    unordered_map<int, int> mem;

    for (int i = 0; i < n; ++i)    
    {
        int val = nums[i];
        if (mem.find(k - val) != mem.end()) return true;
        mem[val] = i;
    }
    return false;
}
