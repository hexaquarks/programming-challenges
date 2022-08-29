#include <vector>
#include <algorithm>

using namespace std;

/* My solution */
vector<int> solution(vector<int> a) 
{
    vector<pair<int, int>> mem;
    
    for (int i = 0; i < a.size(); ++i) 
    { 
        if (a[i] != -1) mem.push_back({i, a[i]});
    }
    sort(mem.begin(), mem.end(), [](const auto& x, const auto& y)
    {
        return x.second < y.second;
    });
    
    int i = 0;
    vector<int> ans;
    for (int j = 0; j < a.size(); ++j)
    {
        if (a[j] != -1)
        {
            a[j] = mem[i].second;
            ++i;
        }
    }
    return a;
}

/* Pumped up solution ngl */
std::vector<int> t, solution(std::vector<int> a) {
    for (int x:a) if (x>-1) t.push_back(x);
    sort(begin(t), end(t));
    auto p = begin(t);
    for (int x:a) if (x>-1) x = *(p++);
    return a;
}
