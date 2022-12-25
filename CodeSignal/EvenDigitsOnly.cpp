#include <bits/stdc++.h>
using namespace std;

bool solution(int n) {
    string s = to_string(n);
    for (const char c : s)
    {
        if ((c - '0') % 2 != 0) return false;
    }
    return true;
}
