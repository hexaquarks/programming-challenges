class Solution {
public:
    bool hasWord(vector<string>& words, string& s, int& i) {
        if (i == s.size()) return false;
        string word; 

        while (i < s.size() && s[i] != ' ') { word += s[i]; ++i; }
        words.push_back(word);
        while (i < s.size() && s[i] == ' ') ++i;
        return true;
    }
    string reverseWords(string s) {
        vector<string> words;
        
        // prework
        int i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] != ' ') break;
        }
        while (i < s.size()) hasWord(words, s, i);
        string ans;
        for (int i = words.size() - 1; i >= 0; --i) {
            ans += words[i];
            if (i > 0) ans += ' ';
        }
        return ans;
    }
};