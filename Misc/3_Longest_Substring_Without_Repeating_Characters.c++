#include <vector> 
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        vector<int> mem(256,-1);
        
        int ans = 0, start = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (mem[s[i]] > start) start = mem[s[i]];
            mem[s[i]] = i;
            ans = max(ans, i - start);
        }
        
        return ans;
    }
};