#include <bits/stdc++.h>
using namespace std;

void printStack(stack<char>& s)
{
    if (s.empty()) return;
    char top = s.top();
    s.pop();
    printStack(s);
    cout << top;
    s.push(top);
}

int main()
{
    ios::sync_with_stdio(false);
    
    string in;
    getline(cin, in);
    
    stack<char> s;
    for (const char& c : in)
    {
        if (c == '<') s.pop();
        else s.push(c);
    }
    printStack(s);
    return 0;
}