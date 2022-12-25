#include <string>

/* My solution - Faster than 100% */
int solve(string s) 
{
    int n = s.size();
    if (n == 0) return 0;

    int ans = 0;
    int stack = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(') { ++ans; ++stack; }
        else
        {
            if (stack != 0) { --stack; --ans; }
            else ++ans;
        }
    }   
    return ans;
}

/* More compact solution ? */
int solve(string s) {
    int left = 0;
    int stack = 0;

    for (auto c : s) {
        if (!stack && c == ')') ++left;
        else if (c == '(') ++stack;
        else --stack;
    }
    return left + stack;
}
