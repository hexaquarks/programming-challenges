#include <string>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if (n == 0) return "";
        int start = 0, end = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int odd = fromMiddle(i, i, s);
            int even = fromMiddle(i, i + 1, s);
            int len = max(even, odd);
            if (len > end - start) 
            {
                start = i - ((len - 1) >> 1);
                end = i + (len >> 1);
            }
        }
        return s.substr(start, end + 1);
    }
    
    int fromMiddle(int l, int r, string& s)
    {
        if (l > r) return 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) 
        {
            --l; ++r;
        }
        return r - l - 1;
    }
};