#include <string>

string solve(string s) 
{
    int n = s.size();
    if (n == 0) return "";

    char last = s[0];
    int counter = 0;
    string ans;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == last) ++counter;
        else 
        {
            ans += to_string(counter + 1) + last;
            last = s[i];
            counter = 0;
        }
    }
    return ans;
}