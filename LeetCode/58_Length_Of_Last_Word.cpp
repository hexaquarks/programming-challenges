class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isCounting = false;
        int ans = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == ' ' && isCounting) {
                return  ans;
            } else if (c != ' ' && isCounting) {
                ++ans;
            } else if (c != ' ' && !isCounting ) {
                isCounting = true;
                ++ans;
            }
        }
        return ans;
    }
};