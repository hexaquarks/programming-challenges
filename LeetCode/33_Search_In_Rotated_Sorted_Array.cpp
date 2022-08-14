#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0; 
        int last = nums.size() - 1;
        int mid = 0;
        
        while (first <= last)
        {
            mid = first - ((first - last) >> 1); 
            if (nums[mid] == target) return mid;
            if (nums[first] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[first]) last=mid-1;
                else first=mid+1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[last]) first=mid+1;
                else last=mid-1;
            }
            
        }
        return -1;
    }
};