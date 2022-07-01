#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return {};
    
    vector<int> even, odd;
    std::copy_if (nums.begin(), nums.end(), std::back_inserter(even), [](int i){ return i % 2 == 0; } );
    std::copy_if (nums.begin(), nums.end(), std::back_inserter(odd), [](int i){ return i % 2 != 0; } );

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end(), std::greater<>());

    int e = 0, o = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] % 2 == 0) ans.push_back(even[e]); ++e;
        else ans.push_back(odd[o]); ++o;
    }
    return ans;
}
