#include <string>

using namespace std;

/* My solution - faster than 100% */
string solve(string s, int i, int j) 
{
    int n = s.size(), ni;
    if (!n) return "";
    if (i >= n) ni = i % n;
    else ni = i;

    int diff = j - i;
    int k = 0;
    string res = "";
    while (diff--)
    {
        if (ni + k >= n) k = -ni;
        res += s[ni + k];
        ++k;
    }
    return res;
}