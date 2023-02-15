class Solution {
public:
    string addBinary(string aa, string bb) {
        int keep = 0;
        int maxLen = max(bb.size(), aa.size());
        if (aa.size() < maxLen) {
            string temp = aa;
            aa = string(maxLen - aa.size(), '0');
            aa += temp;
        } else if (bb.size() < maxLen) {
            string temp = bb;
            bb = string(maxLen - bb.size(), '0');
            bb += temp;
        }
        string s;
        for (int i = maxLen - 1; i >= 0; --i) {
            int a = aa[i] - '0';
            int b = bb[i] - '0';

            if (a + b == 2) {
                if (keep == 1) {
                    s.push_back('1');
                    --keep;
                } else {
                    s.push_back('0');
                }
                ++keep;
            } else if (a + b == 0) {
                if (keep == 1) {
                    s.push_back('1');
                    --keep;
                } else s.push_back('0');
            } else {
                if (keep == 1) {
                    s.push_back('0');
                } else s.push_back('1');
            }
        }
        if (keep == 1) s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};