#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    unordered_map<char, string> keys{ { '2',"abc" },{ '3',"def" },{ '4',"ghi" }, { '5',"jkl" },
                          { '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz" } };
    
    vector<string> letterCombinations(string D) 
    {
        int length = D.size();
        vector<string> ans;
        
        if (length == 0) return {};
        else dfs(0, length, "", ans, D);
        
        return ans;
    }
    
    void dfs(int pos, int& length, string str, vector<string>& ans, string& D) 
    {
        if (pos == length) ans.push_back(str);
        else 
        {
            string letters = keys[D[pos]];
            for (int i = 0; i < letters.size(); ++i)
            {
                dfs(pos+1, length, str+letters[i], ans, D);
            }
        }
    }
};