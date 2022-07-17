#include <string>

using namespace std;

/* My solution - faster than 100% */
int solve(string s, string t) 
{
    int n = s.size();
    if (n == 0) return 0;

    int memS[26] = { 0 };
    int memT[26] = { 0 };
 
    int count = 0;
 
    for (int i = 0; i < n; ++i) ++memS[s[i] - 'a'];
    for (int i = 0; i < n; ++i) ++memT[t[i] - 'a'];
 
    for (int i = 0; i < 26; ++i) count += (min(memS[i], memT[i]));
    return n - count;
}