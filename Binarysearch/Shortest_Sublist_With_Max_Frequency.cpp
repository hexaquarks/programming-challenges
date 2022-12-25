#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* My solution - Faster than 91% */
int solve(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return 0;

    unordered_map<int, vector<int>> mem;
    for (int i = 0; i < n; ++i)
    {
        mem[nums[i]].push_back(i);
    }
    int maxFreq = 0;
    for (auto i = mem.begin(); i != mem.end(); ++i)
    {
        vector<int> v = i->second;
        int vSize = v.size();
        maxFreq = max(maxFreq, vSize);
    }

    vector<int> ans;
    for (auto i = mem.begin(); i != mem.end(); ++i)
    {
        vector<int> v = i->second;
        int vSize = v.size();
        if (vSize != maxFreq) continue;

        ans.push_back(v[v.size() - 1] - v[0] + 1);
    }
    return *min_element(ans.begin(), ans.end());
}

/* More compact solution */
int solve(vector<int>& nums) {
    int k = 0;                     // tracks max freq
    unordered_map<int, int> freq;  // freq of each number
    unordered_map<int, int> si;    // start index
    unordered_map<int, int> ei;    // end index
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
        if (si.count(nums[i]) == 0) si[nums[i]] = i;
        ei[nums[i]] = i;
        k = std::max(k, freq[nums[i]]);
    }
    int shortest_freq = nums.size();  // tracks shortest sublist size
    for (auto x : freq) {
        if (x.second == k) shortest_freq = std::min(shortest_freq, (ei[x.first] - si[x.first]) + 1);
    }
    return shortest_freq;
}