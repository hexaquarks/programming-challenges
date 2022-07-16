#include <string> 

using namespace std;

/* My solution - Faster than 100% */
bool solve(string s, string t) 
{
    int n = s.size();
    int m = t.size();
    if (n != m || m == 0 || n == 0) return true;

    int memS[256] = {0};
    int memT[256] = {0};

    for (int i = 0; i < n; ++i) 
    {
        ++memS[s[i] - 'a'];
        ++memT[t[i] - 'a'];
    }

    for (int i = 0; i < n; ++i)
    {
        if (memS[s[i] - 'a'] != memT[t[i] - 'a']) return false;
    }
    return true;
}