#include <vector>
#inculde <string>

string solve(string s) 
{
    int n =  s.size();
    if (n == 0) return "";

    string ans;
    for (int i = 0; i < n; ++i)
    {
        char curr = s[i];
        if (curr == '<' && s[i + 1] == '-')
        {
            if (ans != "") ans.pop_back();
            ++i;
        }
        else ans += curr;
    }
    return ans;
}   
