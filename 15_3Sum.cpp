#include <vector>
#include <algorithm>
using namespace std;
// a + b + c = 0 ==> b + c = -a <==> Two Sum problem
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break; // performance boost
            else if (i > 0 && nums[i] == nums[i-1]) continue;

            l = i+1;
            r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    int prevL = nums[l];
                    int prevR = nums[r];
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    // moving the two pointers to prepare for next iteration
                    while (l < r && nums[l] == prevL) ++l;
                    while (l < r && nums[r] == prevR) --r;
                }
            }

        }
        return ans;
    }
};