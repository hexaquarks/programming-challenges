#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) 
    {
        if (n == 1) return {"()"};
        
        helper("", n, n);
        return ans;
    }
    
    void helper(string output_, int open_, int close_)
    {
        // base case
        if (open_ == 0 && close_ == 0)
        {
            ans.push_back(output_);
            return;
        }
        
        // reccursive step
        if (open_ > 0) helper(output_ + "(", open_ - 1, close_);
        if (open_ < close_) helper(output_ + ")", open_, close_ - 1);
    }
};