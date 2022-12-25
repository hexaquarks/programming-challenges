#include <vector>
#include <unordered_map>

using namespace std;

int solve(vector<int>& nums) 
{
    unordered_map<int, int> mem;
    int ans = 0;
    
    for (int val : nums) 
    {
        for (int j = 0; j < 31; j++) 
        {
            int pow = 1 << j;
            if (mem.find(pow - val) != mem.end()) ans += mem[pow - val];
        }
        ++mem[val];
    }
    return ans;
}