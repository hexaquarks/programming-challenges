#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        // Two pointer greedy approach
        int size = height.size();
        int i = 0;
        int j = size - 1;
        int area = 0;
        
        while (i < j) 
        {
            area = max(area, (j - i) * (min(height[i], height[j])));
            if (height[i] < height[j]) ++i;
            else --j;
        }
        
        return area;
    }
};