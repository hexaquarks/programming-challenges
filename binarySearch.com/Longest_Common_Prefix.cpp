#include <string>
#include <algorithm>

using namespace std;

/* My solution - faster than 50% */
string solve(vector<string>& words) 
{
    int n = words.size();
    sort(words.begin(), words.end());
    string first = words[0], last = words[n - 1];
    string ans = "";
    int i = 0;

    while (first[i] == last[i])
    {
        ans += first[i];
        ++i;
    }
    return ans;
}

