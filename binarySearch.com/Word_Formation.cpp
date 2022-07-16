#include <vector>
#include <string> 
#include <unordered_map>
#include <map>

using namespace std;

/* My solution - Faster than 8% because of map copy ! */
int solve(vector<string>& words, string letters) 
{
    int n1 = words.size(), n2 = letters.size();
    if (n1 == 0 || n2 == 0) return 0;

    unordered_map<char, int> mem;
    for (int i = 0; i < n2; ++i) ++mem[letters[i]];
    
    int ans = 0;

    for (int i = 0; i < n1; ++i)
    {
        unordered_map<char, int> memCopy(mem.begin(), mem.end());
        bool isOk = true;
        for (char& c : words[i])
        {
            --memCopy[c];
            if (memCopy[c] < 0) { isOk = false; break; }
        }
        int wordSize = words[i].size();
        if (isOk) ans = max(ans, wordSize);
    }
    return ans;
}

/* Better accepted solution */
int solve(vector<string>& words, string letters) {
    map<char, int> mp, temp;
    int ans = numeric_limits<int>::min();
    for (int i = 0; i < letters.size(); i++) {
        mp[letters[i]]++;
    }
    for (string s : words) {
        temp = mp;
        int count = 0;

        for (char c : s) {
            if (temp.find(c) != temp.end() && temp[c] > 0) {
                temp[c]--;
                count++;
            }
        }
        if (count == s.length()) {
            ans = max(ans, count);
        }
    }
    if (ans != numeric_limits<int>::min()) {
        return ans;
    }
    return 0;
}