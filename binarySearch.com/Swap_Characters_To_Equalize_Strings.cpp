#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* My solution - faster than 40% */
bool solve(string s, string t) 
{
    int n1 = s.size(), n2 = t.size();
    if (n1 != n2) return false;

    unordered_map<char, int> mem;
    string combined = s + t;
    int count = 0;
    
    for (int i = 0; i < 2 * n1; ++i) ++mem[combined[i]];

    for (const auto& val : mem)
    {
        if (val.second % 2 != 0) return false;
    }
    return true;
}

/* Slightly better and faster solution */
bool solve(string s, string t) {
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    for (char c : t) cnt[c - 'a']++;
    for (int i : cnt)
        if (i % 2 == 1) return false;
    return true;
}

/* Best and fastest solution */
bool solve(string s, string t) {
    int a = 0;
    for (auto ch : t) a ^= (1 << ch - 'a');
    for (auto ch : s) a ^= (1 << ch - 'a');
    return a == 0;
}
