#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* My solution - faster than 26% */
vector<string> separate(string& s)
{
    string temp = "";
    vector<string> words; 

	for (int i = 0; i < s.size(); ++i)
    {	
		if (s[i] == ' ')
        {
			words.push_back(temp);
			temp = "";
		}
		else temp.push_back(tolower(s[i]));	
	}
	words.push_back(temp);
    return words;
}

int solve(string s0, string s1) 
{
    if (s0.size() == 0 || s1.size() == 0) return 0;
    vector<string> vS0 = separate(s0);
    vector<string> vS1 = separate(s1);

    unordered_set<string> set0(vS0.begin(), vS0.end());
    unordered_set<string> set1(vS1.begin(), vS1.end());

    int n0 = set0.size(), n1 = set1.size();
    if (n0 == 0 || n1 == 0) return 0;

    unordered_set<string> setUnion;
    set_union(set0.begin(), set0.end(), set1.begin(), set1.end(),
             inserter(setUnion, setUnion.begin()));
    int n2 = setUnion.size();
    return abs((n0 + n1) - n2);
}


/* SLightly faster solution 60% */
string lo(string s) {
    string t = "";
    for (int i = 0; i < (int)s.length(); ++i) t += tolower(s[i]);
    return t;
}
int solve(string s0, string s1) {
    unordered_map<string, bool> m, n;
    int nt = 0;
    stringstream a(s0);
    stringstream b(s1);
    string s, t;
    while (a >> s) m[(lo(s))] = true;
    while (b >> t) {
        string x = lo(t);
        if (m[x] == true && n[x] == false) {
            ++nt;
            n[x] = true;
        }
    }

    return nt;
}