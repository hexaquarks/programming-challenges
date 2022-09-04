#include <bits/stdc++.h>
using namespace std;

string findNum(const char c, const unordered_map<int, vector<char>>& model)
{
    string num = "";
    for (const auto& [key, val] : model )    
    {
        for (int i = 0; i < val.size(); ++i)
        {
            if (val[i] == c) 
            {
                int j = ++i;
                while (j--) num += to_string(key);
            }
        }
    }
    return num;
}

int main()
{
    unordered_map<int, vector<char>> model{
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };
    
    int n, i = 1;
    cin >> n;
    cin.ignore();
    
    while (n--)
    {
        string in; 
        getline(cin, in);
        
        cout << "Case #" << i << ": ";
        string prev = "";
        for (const char& c : in)
        {
            string s = string((c == ' ') ? "0" : findNum(c, model));
            string newS;
            if (prev != "" && prev[0] == s[0]) newS = ' ' + s;
            else newS = s;
            prev = s;
            cout << newS;
        }
        ++i;
        cout << endl;
    }
    return 0;
}