#include <bits/stdc++.h>
using namespace std;

string solution(string inputString) {
    string ans;
    for (const char c : inputString) ans += c == 'z' ? 'a' : c + 1;
    return ans;
}
