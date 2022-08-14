#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        
        sort(strs.begin(), strs.end());
        string ans = "";
        string first = strs[0];
        string second = strs[size - 1];
        
        for (int i = 0; i < first.size(); ++i) 
        {
            if (first[i] == second[i]) ans += first[i];
            else break;
        }
        
        return ans;
        
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.size() == 1) return strs[0];
        
//         vector<char> prefix; 
//         char temp; 
//         int j = 0;
//         while (true) {
//             temp = strs[0][j];
//             if (temp == '\0') break;
            
//             for (int i = 1; i < strs.size(); ++i) {
//                 if (strs[i][j] != temp) goto end;
//             }
//             prefix.emplace_back(temp);
//             ++j;
//         }
//         end:
//         string s(prefix.begin(), prefix.end());
//         return s;
//     }
// };