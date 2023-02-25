class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for (char& c : s) {
            if (isalpha(c) || isdigit(c)) {
                newS += isalpha(c) ? tolower(c) : c;
            }
        }
        int l = 0, r = newS.size() - 1;
        while(l <= r) {
            if (newS[l] != newS[r]) return false;
            ++l; 
            --r;
        }
        return true;
    }
};