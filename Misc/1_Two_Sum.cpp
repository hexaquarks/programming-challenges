#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mem;
        vector<int> ans;
        
        int i = 0;
        while (i < nums.size()) {
            if(mem.find(target - nums[i]) != mem.end()) {
                ans.push_back(mem[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else mem[nums[i]]=i;
            ++i;
        }
        return ans;
    }
};