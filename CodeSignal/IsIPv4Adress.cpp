#include <bits/stdc++.h>
using namespace std;

bool checkSubstring(const string& curr)
{
    if (curr[0] == '0' && curr[curr.size() - 1] != '0') return false;
    if (curr == "00" || curr == "000") return false;
    if (curr.size() == 0 || curr.size() > 3 || stoi(curr) > 255 || stoi(curr) < 0) return false;   
    return true;
}

bool solution(string inputString) 
{
    string curr = "";
    int dots = 0;
    for (const char& c : inputString)
    {
        if (c == '.')
        {
            if (!checkSubstring(curr)) return false;
            else curr = "";
            ++dots;
        }
        else if (!isdigit(c)) return false;
        else curr += c;
    }
    if (!checkSubstring(curr)) return false;
    else return dots == 3;
}
