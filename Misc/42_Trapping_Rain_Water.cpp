#include <vector>

class Solution 
{
public:
    int trap(std::vector<int>& h) 
    {
        if (!h.size()) return 0;
     
        int i = 0, j = h.size() - 1, maxLeft = h[i], maxRight = h[j];
        int ans = 0, temp = 0;
        while (i <= j) 
        {
            if (h[i] > h[j]) {
                temp = h[j];
                if (temp > maxRight) maxRight = temp;
                else ans += maxRight - temp;
                --j;
            }
            else 
            {
                temp = h[i];
                if (temp > maxLeft) maxLeft = temp;
                else ans += maxLeft - temp;
                ++i;
            }
        }
        return ans;
    }
};