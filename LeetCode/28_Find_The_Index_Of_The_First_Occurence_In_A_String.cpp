class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        for (; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() - 1) return i - needle.size() + 1;
                ++j;
            }  
            else 
            {
                i -= j;
                j = 0;
                
            }
        }
        return -1;
    }
};