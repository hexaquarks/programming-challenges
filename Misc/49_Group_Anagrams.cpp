#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
		if (n == 1) return { { strs[0] } };
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mem;
        
        for (size_t i = 0; i < n; ++i)
        {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mem[strs[i]].push_back(str); 
        }
        for(auto i = mem.begin(); i != mem.end(); ++i){
            ans.push_back(i -> second);  
        }
        return ans;
    }
};