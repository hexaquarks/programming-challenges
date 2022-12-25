#include <vector>
#include <string>

using namespace std;

/* My solution - faster than 80% */
vector<string> solve(int n) 
{
    vector<string> ans;
    int count = 1;
    while (count <= n)    
    {
        if (count % 3 == 0 && count % 5 == 0) ans.push_back("FizzBuzz");
        else if (count % 3 == 0) ans.push_back("Fizz");
        else if (count % 5 == 0) ans.push_back("Buzz");
        else ans.push_back(to_string(count));
        ++count;
    }
    return ans;
}

/* Much cleaner solution */
vector<string> solve(int n) {
    vector<string> res;
    for (int i = 1; i <= n; i++) {
        string s;
        if (i % 3 == 0) s += "Fizz";
        if (i % 5 == 0) s += "Buzz";

        res.push_back(s.empty() ? to_string(i) : s);
    }
    return res;
}