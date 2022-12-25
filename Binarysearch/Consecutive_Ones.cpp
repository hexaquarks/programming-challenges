#include <vector>

using namespace std;

/* my solution - faster than 25% */
bool solve(vector<int>& nums) 
{
    int first = -1, last = -1;
    int counter = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int val = nums[i];
        if (val == 1)
        {
            ++counter;
            if (first == -1) { first = i; continue; }
            else last = i;
        }
    }    
    return (last == -1 && first == -1) || (last == -1 && first != -1) 
    || (last - first + 1 == counter);
}

/* much better solution - faster than 95% */
bool solve(vector<int>& nums) {
    for (int i = 0, prev = -1; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (prev != -1 && i - prev > 1)
                return false;
            else
                prev = i;
        }
    }
    return true;
}
