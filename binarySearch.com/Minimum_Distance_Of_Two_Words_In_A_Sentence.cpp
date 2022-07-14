#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

/* My solution - Faster than 40% */
void split(const string &s, char delimiter, vector<string> &words)
{
    string token;
    stringstream tokenStream(s);
 
    while (getline(tokenStream, token, delimiter))
    {
        words.push_back(token);
    }
}

int solve(string text, string word0, string word1) 
{
    int n = text.size();
    if (n == 0) return 0;

    vector<string> arr;
    split(text, ' ', arr);
    
    unordered_map<string,int> mem;
	int minDist = std::numeric_limits<int>::max();

	for (int i=0; i < arr.size(); ++i)
    {
	    if (arr[i] == word0 || arr[i] == word1)
        {
	        mem[arr[i]] = i;
	        if (mem.find(word0) != mem.end() && mem.find(word1) != mem.end())
            {
	            minDist = min(minDist, abs(mem[word0] - mem[word1]) - 1);
            }
	    }
	}
    return minDist == std::numeric_limits<int>::max() ? -1 : minDist;
}

/* Better accepted solution */
int solve(string text, string word0, string word1) {
    int i = -1, j = -1, k = 0;
    istringstream ss(text);
    string w;
    int ans = std::numeric_limits<int>::max();
    while (ss >> w) {
        ++k;
        if (w == word0) {
            if (j != -1) ans = min(ans, k - j - 1);
            i = k;
        }
        if (w == word1) {
            if (i != -1) ans = min(ans, k - i - 1);
            j = k;
        }
    }
    return ans == std::numeric_limits<int>::max ? -1 : ans;
}