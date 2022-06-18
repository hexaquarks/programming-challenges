// class Solution 
// {
// public:
//     bool canJump(vector<int>& nums) 
//     {
//         int i, minjump = 0;
//         for (i = nums.size() - 2; i >= 0; --i) 
//         {
//             ++minjump;
//             if (nums[i] >= minjump) minjump = 0;
//         }
//         return minJump == 0;
//     }
// } 
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
    public:
    bool canJump(vector<int>& nums) 
    { 
        int n = nums.size();
        int reachable = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (i > reachable) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};