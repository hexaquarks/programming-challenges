#include <bits/stdc++.h>
using namespace std;

bool isColored(const string& s)
{
    int x = s[0] - 'A' + 1;
    int y = s[1] - '0';
    return (x + y) % 2 == 0;
}

bool solution(string cell1, string cell2) {
    return isColored(cell1) == isColored(cell2);
}
