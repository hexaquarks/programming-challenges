#include <vector>
#include <algorithm>

using namespace std;

/* Personal solution - better than 15% of submissions */
vector<int> solve(vector<int>& a, vector<int>& b) 
{
    std::vector<int> ans;

    for (int i = 0; i < a.size(); ++i) ans.push_back(a[i]);
    for (int i = 0; i < b.size(); ++i) ans.push_back(b[i]);

    sort(ans.begin(), ans.end());
    return ans;
}

/* Better implementation */
vector<int> solve(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() || j < b.size()) {
        bool chooseA = j == b.size() || (i != a.size() && a[i] < b[j]);
        res.push_back(chooseA ? a[i++] : b[j++]);
    }
    return res;
}