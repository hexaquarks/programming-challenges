#include <vector>
using namespace std;

/* My solution - Faster than 99% */
vector<int> solve(vector<int>& heights) 
{
    vector<int> ans;
    int n = heights.size();
    if (n == 0) return {};

    ans.push_back(n - 1);
    int max = heights[n - 1];
    for (int i = n - 2; i >= 0; --i )
    {
        if (heights[i] <= max) continue;
        else 
        {
            ans.push_back(i);
        }
        max = std::max(max, heights[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}