#include <vector>

using namespace std;

class Solution 
{
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        rec(nums, 0, nums.size() - 1);
        
        return ans;
    }
    
    void rec(vector<int>& nums, int l, int r) {
        if (l == r)
        {
            ans.push_back(nums);
        } 
        else 
        {  
            for (int i = l; i <= r; ++i) 
            {
                swap(nums[l], nums[i]);
                rec(nums, l + 1, r); 
                swap(nums[l], nums[i]);  
            }  
        }
    }  
};