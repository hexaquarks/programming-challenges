#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/* My solution - Faster than 20% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    int ans = 0;
    unordered_map<int, set<int>> mem;

    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];
        if (mem.find(val) != mem.end()) 
        {
            ans += mem[val].size();
        }
        mem[val].insert(i);
    }
    return ans;
}

/* Much better accepted solution */
int solve(vector<int>& nums) {
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans += m[nums[i]]++;
    }
    return ans;
}
