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

/* 
 * Alternative solution 
 */

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         if (n == 1 || n == 0) return n;
        
//         int l = 0, r = 0, max = 0;
//         unordered_set<char> set;
        
//         while (r < n) {
//             if (set.find(s[r]) == set.end()) {
//                 set.emplace(s[r]);
//                 max = std::max(max, (int)set.size());
//                 ++r;
//             } else {
//                 set.erase(s[l]);
//                 ++l;
//             }
//         }
//         return max;
//     }
// };