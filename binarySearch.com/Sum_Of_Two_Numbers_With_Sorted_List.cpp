
/* For sorted array just use sliding window */
bool solve(vector<int>& nums, int k) 
{
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum == k) return true;
        
        if (sum < k) ++l;
        else --r;
    }
    return false;
}
/* Careful, the map solution for two sum is for when the array is non sorted */

// bool solve(vector<int>& nums, int k) 
// {
//     int n = nums.size();
//     unordered_map<int, int> mem;

//     for (int i = 0; i < n; ++i)
//     {
//         if (mem.find(k - nums[i]) != mem.end()) return true;
//         else
//         {
//             mem[nums[i]] = nums[i];
//         }
//     }
//     return false;
// }
