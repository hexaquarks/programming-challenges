#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& nums) 
{
    int max = *max_element(nums.begin(), nums.end());
    int count[max + 1] = { 0 };
    
    for (int i = 0; i < nums.size(); i++) ++count[nums[i]];
    
    if (count[max] == max) return max;
    
    for (int j = max - 1; j >= 0; --j) {
        count[j] += count[j + 1];
        
        if (j == count[j]) return j;
    }
    return -1;
}