#include <vector>
#include <unordered_set>

using namespace std;

/* My solution - Faster than 72% */
bool solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return false;

    unordered_set<int> mem;
    

    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];
        if (mem.find(val) != mem.end()) return true;
        mem.insert(val * 3);
        if (val % 3 == 0) mem.insert(val / 3);
    }
    return false;
}

/* Cleaner but not faster solution */
bool solve(vector<int>& nums) {
    unordered_set<int> set;

    for (int i : nums) {
        if ((i % 3 == 0 && set.count(i / 3) == 1) || set.count(3 * i) == 1) return true;

        set.insert(i);
    }

    return false;
}