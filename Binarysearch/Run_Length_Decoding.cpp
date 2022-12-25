
#include <string>

using namespace std;

/* My solution - faster than 70% */
string solve(string s) 
{
    string ans; 
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {   
            string temp; 
            temp += s[i];
            while (isdigit(s[i + 1]) && i + 1 < s.size() - 1)
            {
               temp += s[i + 1];
               ++i;
            }
            int n = stoi(temp);
            for (int j = 0; j < n; ++j) ans += s[i + 1];
            
        }
    }
    return ans;
}

/* better and faster solution */
string solve(string s) {
    int l = 0, temp;
    string ans = "";
    for (char c : s) {
        temp = c - '0';
        if (temp >= 0 && temp <= 9)
            l = l * 10 + temp;
        else {
            while (l--) ans += c;
            l = 0;
        }
    }
    return ans;
}
