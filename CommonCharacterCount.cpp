#include <vector>
#include <string>

using namespace std; 

/* My solution */
int solution(string s1, string s2) 
{
    vector<int> mem1(256, 0);
    vector<int> mem2(256, 0);
    int ans = 0;
    for (const char& c : s1) ++mem1[c];
    for (const char& c : s2) ++mem2[c];
    for (int i = 0; i < 256; ++i) 
    { 
        ans += min(mem1[i], mem2[i]);
    }
    return ans;
}

/* Slightly faster? */
int solution(std::string s1, std::string s2) {
    int count1[26] = {0};
    int count2[26] = {0};
    
    for(char c: s1) ++count1[c-'a'];
    for(char c: s2) ++count2[c-'a'];
    
    int ret = 0;
    for(int i=0; i<26; ++i)
        ret += min(count1[i],count2[i]);
    
    return ret;
}
