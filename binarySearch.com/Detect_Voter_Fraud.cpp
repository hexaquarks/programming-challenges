#include <vector>
#include <unordered_set>

using namespace std;

/* My solution - faster than 85% */
bool solve(vector<vector<int>>& votes) 
{
    int n = votes.size();
    if (n == 0) return false;

    unordered_set<int> mem;
    for (int i = 0; i < n; ++i)
    {
        int voter = votes[i][1];
        if (mem.find(voter) != mem.end()) return true;
        mem.insert(voter);
    }
    return false;
}

/* Better solution - Faster than 96% */
bool solve(vector<vector<int>>& votes) {
    int n = votes.size() - 1, a = 1, d = 1;
    int required_sum = (n * (n + 1)) / 2;
    int actual_sum = 0;
    for (int i = 0; i < votes.size(); ++i) {
        actual_sum += votes[i][1];
    }
    if (actual_sum == required_sum) return false;
    return true;
}
