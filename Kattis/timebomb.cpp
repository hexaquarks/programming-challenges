#include <bits/stdc++.h>
using namespace std;

int main()
{
    // generate a reference model for the digits composure
    vector<string> s{"***", "* *", "  *", "*  "};
    vector<vector<string>> model{
        {s[0], s[1], s[1], s[1], s[0]}, 
        {s[2], s[2], s[2], s[2], s[2]},
        {s[0], s[2], s[0], s[3], s[0]},
        {s[0], s[2], s[0], s[2], s[0]},
        {s[1], s[1], s[0], s[2], s[2]},
        {s[0], s[3], s[0], s[2], s[0]},
        {s[0], s[3], s[0], s[1], s[0]},
        {s[0], s[2], s[2], s[2], s[2]},
        {s[0], s[1], s[0], s[1], s[0]}, 
        {s[0], s[1], s[0], s[2], s[0]}
    };
    
    // store the input digits
    vector<vector<string>> digits;
    for (int i = 0; i < 5; ++i)
    {
        string in;
        getline(cin, in);
        if (i == 0) 
        {
            // initialize the digits vector here
            int size = 0, j = 0, lineSize = in.size();
            while (j < lineSize)
            {
                string t = in.substr(j, 3);
                ++size;
                j += 4; // skip curr triplet and space
            }
            digits.resize(size);
        }
        
        int j = 0, pos = 0, lineSize = in.size();
        while (pos < lineSize)
        {
            string t = in.substr(pos, 3);
            digits[j].push_back(t);
            ++j;
            pos += 4; // skip curr triplet and space
        }
    }
    
    // check matchings between digits and model
    string ans = "";
    for (const vector<string>& v : digits)
    {
        auto it = find(model.begin(), model.end(), v);
        if (it != model.end())
        {
            int digit = it - model.begin();
            string sDigit = to_string(digit);
            ans += sDigit;
        }
    }
    
    // remove trailing zeros
    int iAns = -1;
    if (ans.size() != 0)
    {
        int k = 0;
        while (ans[k] == '0') ++k;
        ans.erase(0, k);
        if (ans != "") iAns = stoi(ans);
    }
    
    cout << (iAns % 6 == 0 && ans.size() != 0 ? "BEER!!" : "BOOM!!") << endl;
    return 0;
}