#include <vector>
#include <string>

using namespace std;

/* Faster than 80 %*/
vector<string> solve(string s, int k) 
{
    int n = s.size();
    if (!n) return {};

    vector<string> ans(k, "");
    int r = 0;
    for (int i = 0; i < n; ++i) 
    {
        ans[r].push_back(s[i]);
        r = (r + 1) % k;
    }
    return ans;
}