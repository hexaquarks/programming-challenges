#include <bits/stdc++.h>
using namespace std;

bool isUnique(const string& s)
{
    unordered_map<char, int> mem;
    ++mem[s[0]];
    for (int i = 1; i < s.size(); ++i)
    {
        if (mem[s[i]] != 0) return false;
        ++mem[s[i]];
    }
    return true;
}

void compute(const string& s, int n, int& tot)
{
    for (int i = n; i < s.size(); ++i)
    {
        string sub = s.substr(i - n, n);
        if (isUnique(sub)) { tot += i; break; }
    }
}

int main()
{
    int tot1 = 0, tot2 = 0;
    while (true)
    {
        string s;
        getline(cin, s);
        if (s.empty()) break;

        compute(s, 4, tot1);
        compute(s, 14, tot2);
    }
    cout << "tot1 and tot2 are " << tot1 << ", " << tot2 << endl;
    return 0;
}
