#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/* Solution from G4G */
string solution(string inputString) 
{
    stack<int> s;
    string ans;
    
    for (int i = 0; i < inputString.size(); ++i)
    {
        if (inputString[i] == '(') s.push(i);
        else if (inputString[i] == ')') 
        {
            reverse(inputString.begin() + s.top() + 1, inputString.begin() + i);
            s.pop();
        }
    }
    for (int i = 0; i < inputString.size(); ++i)
    {
        if (inputString[i] != '(' && inputString[i] != ')')
        {
            ans += inputString[i];
        }
    }
    return ans;
}
