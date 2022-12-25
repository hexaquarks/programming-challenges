#include <vector>
#include <unordered_map> 

using namespace std;

/* My solution - Faster than ~90% of submissions */
bool solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return false;

    unordered_map<int, int> mem;

    for (int i = 0; i < n; ++i) ++mem[nums[i]];

    unordered_map<int, int>::iterator it;
    int firstSize = mem[nums[0]];

    for (it = mem.begin(); it != mem.end(); it++)
    {
        if (it->second <= 1 || 
                (it->second != firstSize && 
                    (it->second % 2 != 0 || firstSize % 2 != 0)
                )
            ) return false;
    }
    return true;
}

/* More elegant solution */
bool solve(vector<int>& nums) {
    unordered_map<int, int> m;
    int si = INT_MAX;
    for (int i : nums) m[i]++;
    for (auto i : m) si = min(si, i.second);
    for (auto i : m)
        if (__gcd(i.second, si) == 1) return false;
    return true;
}
