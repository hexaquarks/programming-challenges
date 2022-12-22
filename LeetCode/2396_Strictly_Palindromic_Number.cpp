#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBaseRepresentation(int i, int n)
    {
        string res = "";
        while (n > 0) 
        {
            int remainder = n % i;
            n /= i;
            res = to_string(remainder) + res;
        }
        return res;
    }
    bool isBasePalindrome(int i, int n)
    {
        string rep = convertToBaseRepresentation(i, n);
        int l = 0, r = rep.size() - 1;
        while (l <= r)
        {
            if (rep[l] != rep[r]) return false;
            ++l; --r;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) 
    {
        for (int i = 2; i <= n - 2; ++i)
        {   
            if (!isBasePalindrome(i, n)) return false;
        }
        return true;
    }
};