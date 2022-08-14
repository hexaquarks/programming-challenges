#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) 
        {
            if (ans.back()[1] >= intervals[i][0]) 
            {
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
            else ans.emplace_back(intervals[i]); 
        }
        return ans;
    }
};