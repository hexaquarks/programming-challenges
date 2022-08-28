#include <string>

using namespace std;

/* My solution (Standard as before) */
bool solution(string inputString) 
{
    int l = 0, r = inputString.size() - 1;
    while (l <= r)
    {
        if (inputString[l] != inputString[r]) return false;
        else {++l; --r;}
    }
    return true;
}

/* Really cool solution that I have not seen before !*/
bool solution(string is) {
    return is == string(is.rbegin(),is.rend());
}
