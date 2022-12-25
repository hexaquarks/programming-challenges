#include <string> 

using namespace std;

bool solve(string s0, string s1) 
{
    int n = s1.size(), m=s0.size();
    if (m - n != 1) return false;

    int j = 0; 

    for (int i = 0; i < m and j < n; ++i)
    {
        if (s1[j] == s0[i]) ++j;
    }

    return (j == n);
}