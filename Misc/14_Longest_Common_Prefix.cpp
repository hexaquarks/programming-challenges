#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        
        vector<char> prefix; 
        char temp; 
        int j = 0;
        while (true) {
            temp = strs[0][j];
            if (temp == '\0') break;
            
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != temp) goto end;
            }
            prefix.emplace_back(temp);
            ++j;
        }
        end:
        string s(prefix.begin(), prefix.end());
        return s;
    }
};