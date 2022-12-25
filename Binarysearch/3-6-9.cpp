#include <vector>

/* My solution - faster than 40% of submissions */
vector<string> solve(int n) 
{
    vector<string> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0) ans.push_back("clap");
        else
        {
            string s = to_string(i);
            if (s.find('3') != string::npos ||
                s.find('6') != string::npos || 
                s.find('9') != string::npos) ans.push_back("clap");
            else ans.push_back(s);
        }
    }  
    return ans;  
}


/* TODO Find a better c++ solution */
