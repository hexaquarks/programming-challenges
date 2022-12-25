#include <bits/stdc++.h>
using namespace std;

bool solution(string name) {
    int i = 0;
    for (const char c : name)
    {
        if (i == 0 && isdigit(c)) return false;
        if (!isdigit(c) && !isalpha(c) && c != '_') return false;
        ++i;
    }
    return true;
}
