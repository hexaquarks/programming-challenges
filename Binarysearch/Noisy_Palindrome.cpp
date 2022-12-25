#include <string>
#include <algorithm>

using namespace std;
/* My solution - faster than 40% */
bool solve(string s) 
{
    s.erase(remove_if(std::begin(s), std::end(s), 
                           [](auto ch) { return std::isdigit(ch) || isupper(ch); }), 
            s.end()); 
    string temp = s; 
    reverse(temp.begin(), temp.end());
    return temp == s;
}

/* Fasterr community solution */
bool solve(string s) {
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j) {
        if (!isalpha(s[i]) || isupper(s[i])) {
            i++;
        }
        if (!isalpha(s[j]) || isupper(s[j])) {
            j--;
        }
        if (isalpha(s[i]) && islower(s[i]) && isalpha(s[j]) && islower(s[j])) {
            if (s[i] == s[j]) {
                i++, j--;
            } else {
                return false;
            }
        }
    }
    return true;
}