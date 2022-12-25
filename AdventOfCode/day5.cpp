#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(string s, string delimiter) 
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void reverseStacks(vector<stack<char>>& v)
{
    for (auto& s : v) {
        stack<char> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        s = temp;
    }
}

void move(vector<stack<char>>& v, int n, int a, int b)
{
    stack<char>& s1 = v[a - 1];
    stack<char>& s2 = v[b - 1];
    
    while (n--)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void moveStable(vector<stack<char>>& v, int n, int a, int b)
{
    stack<char>& s1 = v[a - 1];
    stack<char>& s2 = v[b - 1];
    stack<char> temp;
    
    while (n--)
    {
        temp.push(s1.top());
        s1.pop();
    }
    while (!temp.empty())
    {
        s2.push(temp.top());
        temp.pop();
    }
    
}

int main()
{
    vector<stack<char>> stacks1;
    vector<stack<char>> stacks2;
    bool ioInstructions = false, isFirstLine = true, isFirstBreak = true;
    int nStacks;
    while (true)
    {
        string s;
        getline(cin, s);
        
        if (isFirstLine) 
        {
            isFirstLine = false;
            nStacks = (s.size() + 1) / 4;
            for (int i = 0; i < nStacks; ++i) {
                stacks1.push_back(stack<char>());
                stacks2.push_back(stack<char>());
            }
        }
        
        if (!s.size()) 
        {
            if (!isFirstBreak) break;
            isFirstBreak = !isFirstBreak;
            continue;
        }
        else if (s[0] == ' ' && s[1] == '1') 
        {
            reverseStacks(stacks1);
            reverseStacks(stacks2);
            ioInstructions = true;
            continue;
        }
        
        if (!ioInstructions)
        {
            for (int i = 0; i < nStacks; ++i)
            {
                if (s[4 * i] == '[') {
                    stacks1[i].push(s[(4 * i) + 1]);
                    stacks2[i].push(s[(4 * i) + 1]);
                } 
            }
        }
        
        if (ioInstructions){
            vector<string> splitted = splitString(s, " ");
            move(stacks1, 
                 stoi(splitted[1]),
                 stoi(splitted[3]),
                 stoi(splitted[5]));
            moveStable(stacks2, 
                       stoi(splitted[1]),
                       stoi(splitted[3]),
                       stoi(splitted[5]));
        }
    }
    string ans1, ans2;
    for (auto& s : stacks1)
    {
        if (s.empty()) continue;
        ans1 += s.top();
        
    }
    for (auto& s : stacks2)
    {
        if (s.empty()) continue;
        ans2 += s.top();
    }
    cout << "ans1 is : " << ans1 << endl;
    cout << "ans2 is : " << ans2 << endl;
    return 0;
}
