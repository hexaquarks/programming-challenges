#include <vector>
#include <unordered_map>

using namespace std;

/* Naive implementation  - Better than 20% O(nlogn) */
bool solve(string s0, string s1) 
{
    std::sort(s0.begin(), s0.end());
    std::sort(s1.begin(), s1.end());
    return s0 == s1;
}

/* Better solution - Faster than 60% O(n) */
bool solve(string s0, string s1)
{
    int n1 = s0.size(), n2 = s1.size();
    if (n1 != n2) return false;

    unordered_map<char, int> mem;

    for (int i = 0; i < n1; ++i)
    {
        ++mem[s0[i]];
    }

    for (int i = 0; i < n1; ++i)
    {
        --mem[s1[i]];
        if (mem[s1[i]] == -1) return false;
    }
    return true;
}

/* Much better solution - Faster than 92% */
bool solve(string s0, string s1)
{
    int n1 = s0.size(), n2 = s1.size();
    if (n1 != n2) return false;

    vector<int> mem(256, 0);

    for (int i = 0; i < n1; ++i)
    {
        ++mem[s0[i]];
        --mem[s1[i]];
    }

    for (int i = 0; i < 256; ++i)
    {
        if (mem[i] != 0) return false;
    }
    return true;
}
